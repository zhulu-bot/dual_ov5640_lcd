#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xil_types.h"
#include "xil_cache.h"
#include "xparameters.h"
#include "xgpio.h"
#include "xaxivdma.h"
#include "xaxivdma_i.h"
#include "display_ctrl/display_ctrl.h"
#include "vdma_api/vdma_api.h"
#include "emio_sccb_cfg/emio_sccb_cfg.h"
#include "ov5640/ov5640_init.h"
#include "osd/osd.h"
#include "ff.h"


//宏定义
#define FRAME_BUFFER_NUM   3                           //帧缓存个数3
#define DYNCLK_BASEADDR    XPAR_AXI_DYNCLK_0_BASEADDR  //动态时钟基地址
#define VDMA_ID            XPAR_AXIVDMA_0_DEVICE_ID    //VDMA器件ID
#define DISP_VTC_ID        XPAR_VTC_0_DEVICE_ID        //VTC器件ID
//PL端  AXI GPIO 0(lcd_id)器件 ID
#define AXI_GPIO_0_ID      XPAR_AXI_GPIO_0_DEVICE_ID
//使用AXI GPIO(lcd_id)通道1
#define AXI_GPIO_0_CHANEL  1

//全局变量
//frame buffer的起始地址
unsigned int frame_buffer_addr[DISPLAY_VDMA_NUM];
unsigned int vdma_id[DISPLAY_VDMA_NUM] = { XPAR_AXIVDMA_0_DEVICE_ID,
XPAR_AXIVDMA_1_DEVICE_ID };

static FATFS fatfs;
//BMP 图片文件头
u8 bmp_head[54] = { 0x42, 0x4d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x36,
		0x0, 0x0, 0x0, 0x28, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x1, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc4,
		0xe, 0x0, 0x0, 0xc4, 0x0e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0 };
//BMP 图片各参数偏移地址
UINT *bf_size = (UINT *) (bmp_head + 0x2);
UINT *bmp_width = (UINT *) (bmp_head + 0x12);
UINT *bmp_height = (UINT *) (bmp_head + 0x16);
UINT *bmp_size = (UINT *) (bmp_head + 0x22);
//BMP 图片编号
int pic_cnt = 0;

//抓拍的图片显存地址
unsigned int const bmp_addr = (XPAR_PS7_DDR_0_S_AXI_BASEADDR + 0x21000000);

XAxiVdma vdma[DISPLAY_VDMA_NUM];
DisplayCtrl dispCtrl;
XGpio axi_gpio_inst;   //PL端 AXI GPIO 驱动实例
VideoMode vd_mode;
unsigned int lcd_id;

//向 SD 卡中写 BMP 图片
void write_sd_bmp(u8 *frame) {
	FIL fil; //文件对象
	UINT bw; //写文件函数返回已写入的字节数
	char pic_name[20]; //字符串，用于存储 BMP 文件名

	//打印 BMP 图片信息(宽/高/图片大小),以及 BMP 文件大小
	xil_printf("width = %d, height = %d, size = %d, file size = %d bytes \n\r",
			*bmp_width, *bmp_height, *bmp_size, *bf_size);

	//给 BMP 图片的文件名编号
	sprintf(pic_name, "picture %04u.bmp", pic_cnt);
	//打开 BMP 文件,如果不存在则创建该文件
	f_open(&fil, pic_name, FA_CREATE_ALWAYS | FA_WRITE);

	//移动文件读写指针到文件开头
	f_lseek(&fil, 0);
	//写入 BMP 文件头
	f_write(&fil, bmp_head, 54, &bw);
	//写入抓拍的图片
	f_write(&fil, frame, *bmp_size, &bw);
	//关闭文件
	f_close(&fil);
	xil_printf("write %s done! \n\r", pic_name);
}

int main(void) {
	u32 status0, status1;
	u16 cmos_h_pixel;   //ov5640 DVP 输出水平像素点数
	u16 cmos_v_pixel;   //ov5640 DVP 输出垂直像素点数
	u16 total_h_pixel;  //ov5640 水平总像素大小
	u16 total_v_pixel;  //ov5640 垂直总像素大小

	int rd_index; //VDMA 读通道操作的帧缓存编号
	unsigned int rd_fram_addr; //VDMA 读通道操作的帧缓存地址

	//获取LCD的ID
	XGpio_Initialize(&axi_gpio_inst, AXI_GPIO_0_ID);
	XGpio_SetDataDirection(&axi_gpio_inst, AXI_GPIO_0_CHANEL, 0x07); //设置AXI GPIO为输入
	lcd_id = LTDC_PanelID_Read(&axi_gpio_inst, AXI_GPIO_0_CHANEL);  //获取LCD的ID
	XGpio_SetDataDirection(&axi_gpio_inst, AXI_GPIO_0_CHANEL, 0x00); //设置AXI GPIO为输出
	xil_printf("lcd_id = %x\r\n", lcd_id);

	//根据获取的LCD的ID号来进行ov5640显示分辨率参数的选择
	switch (lcd_id) {
	case 0x4342:  //4.3寸屏,480*272分辨率
		cmos_h_pixel = 480;
		cmos_v_pixel = 272;
		total_h_pixel = 1800;
		total_v_pixel = 1000;
		break;
	case 0x4384:  //4.3寸屏,800*480分辨率
		cmos_h_pixel = 800;
		cmos_v_pixel = 480;
		total_h_pixel = 1800;
		total_v_pixel = 1000;
		break;
	case 0x7084:  //7寸屏,800*480分辨率
		cmos_h_pixel = 800;
		cmos_v_pixel = 480;
		total_h_pixel = 1800;
		total_v_pixel = 1000;
		break;
	case 0x7016:  //7寸屏,1024*600分辨率
		cmos_h_pixel = 1024;
		cmos_v_pixel = 600;
		total_h_pixel = 2200;
		total_v_pixel = 1000;
		break;
	case 0x1018:  //10.1寸屏,1280*800分辨率
		cmos_h_pixel = 1280;
		cmos_v_pixel = 800;
		total_h_pixel = 2570;
		total_v_pixel = 980;
		break;
	default:
		cmos_h_pixel = 480;
		cmos_v_pixel = 272;
		total_h_pixel = 1800;
		total_v_pixel = 1000;
		break;
	}

	emio_init();                                //初始化EMIO
	status0 = ov5640_init(CMOS_CH0, cmos_h_pixel,                  //初始化ov5640 0
			cmos_v_pixel, total_h_pixel, total_v_pixel);
	status1 = ov5640_init(CMOS_CH1, cmos_h_pixel,                  //初始化ov5640 1
			cmos_v_pixel, total_h_pixel, total_v_pixel);
	if (status0 == 0 && status1 == 0)
		xil_printf("Dual OV5640 detected successful!\r\n");
	else
		xil_printf("Dual OV5640 detected failed!\r\n");

	//根据获取的LCD的ID号来进行video参数的选择
	switch (lcd_id) {
	case 0x4342:
		vd_mode = VMODE_480x272;
		break;  //4.3寸屏,480*272分辨率
	case 0x4384:
		vd_mode = VMODE_800x480;
		break;  //4.3寸屏,800*480分辨率
	case 0x7084:
		vd_mode = VMODE_800x480;
		break;  //7寸屏,800*480分辨率
	case 0x7016:
		vd_mode = VMODE_1024x600;
		break;  //7寸屏,1024*600分辨率
	case 0x1018:
		vd_mode = VMODE_1280x800;
		break;  //10.1寸屏,1280*800分辨率
	default:
		vd_mode = VMODE_800x480;
		break;
	}

	for (u8 i = 0; i < DISPLAY_VDMA_NUM; i++) {
		frame_buffer_addr[i] = XPAR_PS7_DDR_0_S_AXI_BASEADDR + 0x1000000 * (i+1);
		//配置VDMA
		run_vdma_frame_buffer(&vdma[i], vdma_id[i], vd_mode.width / 2,
				vd_mode.height, frame_buffer_addr[i], 0, 0, BOTH);
		// memset(frame_buffer_addr[i],i,vd_mode.height*vd_mode.width*FRAME_BUFFER_NUM*3/2);
	}

	//因摄像头和 RGB LCD 屏的分辨率不匹配,清空 DDR3 帧缓存空间
	 //最后一个参数表示清零的字节数，由于 RGB888 数据格式占用 3 个字节,因此最后乘以 3

     Xil_DCacheFlush();

	//OSD初始化
	osd_init(lcd_id, vd_mode.width, vd_mode.height);
	//初始化Display controller
	DisplayInitialize(&dispCtrl, DISP_VTC_ID, DYNCLK_BASEADDR);
	//设置VideoMode
	DisplaySetMode(&dispCtrl, &vd_mode);
	DisplayStart(&dispCtrl);

	//根据 VDMA 显存大小给 BMP 文件头赋值
	*bmp_width = vd_mode.width/2;
	*bmp_height = vd_mode.height;
	*bmp_size = vd_mode.width * vd_mode.height * 3/2;
	*bf_size = *bmp_size + 54;
	//挂载文件系统
	f_mount(&fatfs, "", 1);

	//根据串口输入的指令控制拍照过程

	while (1) {
		sleep(5);
		xil_printf("capture picture\n");
			//获取当前读通道操作的帧缓存编号
			rd_index = XAxiVdma_CurrFrameStore(&vdma[0], XAXIVDMA_READ);
			xil_printf("current read frame is %d\n", rd_index);
			//读通道驻停在当前帧
			XAxiVdma_StartParking(&vdma[0], rd_index, XAXIVDMA_READ);
			//并获取当前帧的起始地址
			rd_fram_addr = (unsigned int) (frame_buffer_addr[0]
					+ vd_mode.height * vd_mode.width * 3 * rd_index);
			//将当前帧的图像拷贝到抓拍图片缓存区域
			memcpy((void *) bmp_addr, (void *) rd_fram_addr,
					vd_mode.height * vd_mode.width * 3);
			//结束读通道驻停过程，继续在多帧之间进行切换
			XAxiVdma_StopParking(&vdma[0], XAXIVDMA_READ);
			//将抓拍图片缓存区域中的图像以 BMP 格式写入 SD 卡
			write_sd_bmp((u8 *) bmp_addr);
			//BMP 图片编号累加
			pic_cnt++;
			xil_printf("take picture success and the pic_cnt is %d",pic_cnt);

	}

	return 0;
}
