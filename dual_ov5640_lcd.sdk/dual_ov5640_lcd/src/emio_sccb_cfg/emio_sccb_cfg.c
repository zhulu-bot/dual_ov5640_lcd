//****************************************Copyright (c)***********************************//
//原子哥在线教学平台：www.yuanzige.com
//技术支持：www.openedv.com
//淘宝店铺：http://openedv.taobao.com
//关注微信公众平台微信号："正点原子"，免费获取ZYNQ & FPGA & STM32 & LINUX资料。
//版权所有，盗版必究。
//Copyright(C) 正点原子 2018-2028
//All rights reserved
//----------------------------------------------------------------------------------------
// File name:           emio_sccb_cfg
// Last modified Date:  2019/10/8 17:25:36
// Last Version:        V1.0
// Descriptions:        SCCB配置
//----------------------------------------------------------------------------------------
// Created by:          正点原子
// Created date:        2019/10/8 17:25:36
// Version:             V1.0
// Descriptions:        The original version
//
//----------------------------------------------------------------------------------------
//****************************************************************************************//

#include"emio_sccb_cfg.h"

#define  GPIOPS_ID  XPAR_XGPIOPS_0_DEVICE_ID  //PS 端 GPIO 器件 ID

static  XGpioPs  gpiops_inst; //PS 端 GPIO 驱动实例

//EMIO初始化
void emio_init(void)
{

	XGpioPs_Config *gpiops_cfg_ptr; //PS 端 GPIO 配置信息

	//根据器件 ID 查找配置信息
	gpiops_cfg_ptr = XGpioPs_LookupConfig(GPIOPS_ID);
	//初始化器件驱动
	XGpioPs_CfgInitialize(&gpiops_inst, gpiops_cfg_ptr, gpiops_cfg_ptr->BaseAddr);

	//设置 CMOS0 sccb端口 为输出
	XGpioPs_SetDirectionPin(&gpiops_inst, EMIO_SCL0_NUM, 1);
	XGpioPs_SetDirectionPin(&gpiops_inst, EMIO_SDA0_NUM, 1);
	//使能CMOS0 sccb端口 输出
	XGpioPs_SetOutputEnablePin(&gpiops_inst, EMIO_SCL0_NUM, 1);
	XGpioPs_SetOutputEnablePin(&gpiops_inst, EMIO_SDA0_NUM, 1);
	//将CMOS0 sccb的SCLK和SDA都拉高
	XGpioPs_WritePin(&gpiops_inst, EMIO_SCL0_NUM, 1);
	XGpioPs_WritePin(&gpiops_inst, EMIO_SDA0_NUM, 1);

	//设置 CMOS1 sccb端口 为输出
	XGpioPs_SetDirectionPin(&gpiops_inst, EMIO_SCL1_NUM, 1);
	XGpioPs_SetDirectionPin(&gpiops_inst, EMIO_SDA1_NUM, 1);
	//使能CMOS1 sccb端口 输出
	XGpioPs_SetOutputEnablePin(&gpiops_inst, EMIO_SCL1_NUM, 1);
	XGpioPs_SetOutputEnablePin(&gpiops_inst, EMIO_SDA1_NUM, 1);
	//将CMOS1 sccb的SCLK和SDA都拉高
	XGpioPs_WritePin(&gpiops_inst, EMIO_SCL1_NUM, 1);
	XGpioPs_WritePin(&gpiops_inst, EMIO_SDA1_NUM, 1);
}

//产生sccb起始信号
void sccb_start(u8 cmos_ch)
{
	u8 emio_scl = 0 ,emio_sda = 0;
    if(cmos_ch == 0){
        emio_scl = EMIO_SCL0_NUM;
        emio_sda = EMIO_SDA0_NUM;
    }
    else{
        emio_scl = EMIO_SCL1_NUM;
        emio_sda = EMIO_SDA1_NUM;        
    }

	XGpioPs_WritePin(&gpiops_inst, emio_scl, 1);
	XGpioPs_WritePin(&gpiops_inst, emio_sda, 1);

	usleep(4);

 	XGpioPs_WritePin(&gpiops_inst, emio_sda, 0);  //START:when CLK is high,DATA change form high to low

 	usleep(4);

 	XGpioPs_WritePin(&gpiops_inst, emio_scl, 0);  //钳住I2C总线，准备发送或接收数据

}

//产生sccb停止信号
void sccb_stop(u8 cmos_ch)
{
	u8 emio_scl = 0 ,emio_sda = 0;
        if(cmos_ch == 0){
        emio_scl = EMIO_SCL0_NUM;
        emio_sda = EMIO_SDA0_NUM;
    }
    else{
        emio_scl = EMIO_SCL1_NUM;
        emio_sda = EMIO_SDA1_NUM;        
    }
    
	XGpioPs_WritePin(&gpiops_inst, emio_scl, 0);

	XGpioPs_WritePin(&gpiops_inst,emio_sda, 0);  //STOP:when CLK is high DATA change form low to high

 	usleep(4);

	XGpioPs_WritePin(&gpiops_inst, emio_scl, 1);

	usleep(4);

	XGpioPs_WritePin(&gpiops_inst, emio_sda, 1);  //发送I2C总线结束信号

}

//sccb发送一个字节
void sccb_send_byte(u8 cmos_ch,u8 txd)
{
    u8 t;
    u8 emio_scl = 0 ,emio_sda = 0;
        if(cmos_ch == 0){
        emio_scl = EMIO_SCL0_NUM;
        emio_sda = EMIO_SDA0_NUM;
    }
    else{
        emio_scl = EMIO_SCL1_NUM;
        emio_sda = EMIO_SDA1_NUM;        
    }
    
    XGpioPs_WritePin(&gpiops_inst, emio_scl, 0);  //拉低时钟开始数据传输

    for(t=0; t<8; t++)
    {
        XGpioPs_WritePin(&gpiops_inst, emio_sda, (txd&0x80)>>7);

        txd<<=1;

        usleep(4);

        XGpioPs_WritePin(&gpiops_inst, emio_scl, 1);

        usleep(4);

        XGpioPs_WritePin(&gpiops_inst, emio_scl, 0);

        usleep(4);
    }
}

//SCCB接收一个字节
u8  sccb_rece_byte(u8 cmos_ch)
{
	unsigned char i=0 , rxd=0;
	u8 emio_scl = 0 ,emio_sda = 0;
    if(cmos_ch == 0){
        emio_scl = EMIO_SCL0_NUM;
        emio_sda = EMIO_SDA0_NUM;
    }
    else{
        emio_scl = EMIO_SCL1_NUM;
        emio_sda = EMIO_SDA1_NUM;        
    }

	XGpioPs_SetOutputEnablePin(&gpiops_inst, emio_sda, 0);
	XGpioPs_SetDirectionPin(&gpiops_inst, emio_sda, 0);

	XGpioPs_WritePin(&gpiops_inst, emio_scl, 0);
	usleep(4);

	for(i=0;i<8;i++ )
	{
        XGpioPs_WritePin(&gpiops_inst, emio_scl, 1);
        usleep(2);

        rxd <<= 1;
        if( XGpioPs_ReadPin(&gpiops_inst, emio_sda) ) {
        	rxd = rxd | 0x01;
        }
		usleep(2);

		XGpioPs_WritePin(&gpiops_inst, emio_scl, 0);
		usleep(4);
    }

	XGpioPs_SetDirectionPin(&gpiops_inst, emio_sda, 1);  //SDA设置为输出
	XGpioPs_SetOutputEnablePin(&gpiops_inst, emio_sda, 1);

    return rxd;

}

//产生ACK应答
void sccb_ack(u8 cmos_ch)
{
	u8 emio_scl = 0 ,emio_sda = 0;
    if(cmos_ch == 0){
        emio_scl = EMIO_SCL0_NUM;
        emio_sda = EMIO_SDA0_NUM;
    }
    else{
        emio_scl = EMIO_SCL1_NUM;
        emio_sda = EMIO_SDA1_NUM;        
    }
    
	XGpioPs_WritePin(&gpiops_inst, emio_scl, 0);
	XGpioPs_WritePin(&gpiops_inst, emio_sda, 0);

	usleep(4);

	XGpioPs_WritePin(&gpiops_inst, emio_scl, 1);

	usleep(4);

	XGpioPs_WritePin(&gpiops_inst, emio_scl, 0);

	usleep(4);
}

