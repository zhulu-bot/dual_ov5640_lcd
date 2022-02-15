//****************************************Copyright (c)***********************************//
//ԭ�Ӹ����߽�ѧƽ̨��www.yuanzige.com
//����֧�֣�www.openedv.com
//�Ա����̣�http://openedv.taobao.com
//��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡZYNQ & FPGA & STM32 & LINUX���ϡ�
//��Ȩ���У�����ؾ���
//Copyright(C) ����ԭ�� 2018-2028
//All rights reserved
//----------------------------------------------------------------------------------------
// File name:           osd
// Last modified Date:  2019/10/8 17:25:36
// Last Version:        V1.0
// Descriptions:        OSD IP������
//----------------------------------------------------------------------------------------
// Created by:          ����ԭ��
// Created date:        2019/10/8 17:25:36
// Version:             V1.0
// Descriptions:        The original version
//
//----------------------------------------------------------------------------------------
//****************************************************************************************//

#ifndef OSD_H_
#define OSD_H_

#include "xbasic_types.h"
#include "xparameters.h"
#include "xstatus.h"
#include "xosd.h"

void osd_init(u16 lcd_id,int screen_width,int screen_height);
void osd_layer_cfg(int screen_width,int screen_height);
void OsdDrawBox(int x_start, int y_start, int x_last, int y_last, int color);
void osd_draw_text(XOSD Osd,int layer_index,int x_start, int y_start, int color_index, int text_index, int text_size);

//OSDͼ�����ýṹ��
typedef struct {
	u32 index;        //ͼ������
	u32 alpha_value;  //ͼ��͸����
	u32 priority;     //ͼ�����ȼ�
	u32 alpha_enable; //͸����ʹ��
}OSD_LayerCfg;

//OSDͼ��0���ò���
static const OSD_LayerCfg OSD_Layer0 = {
		.index = 0,
		.alpha_value = 0xff,
		.priority = XOSD_LAYER_PRIORITY_0,
		.alpha_enable = 1
};

//OSDͼ��1���ò���
static const OSD_LayerCfg OSD_Layer1 = {
		.index = 1,
		.alpha_value = 0xff,
		.priority = XOSD_LAYER_PRIORITY_1,
		.alpha_enable = 1
};

//OSDͼ��2���ò���
static const OSD_LayerCfg OSD_Layer2 = {
		.index = 2,
		.alpha_value = 0xff,
		.priority = XOSD_LAYER_PRIORITY_2,
		.alpha_enable = 0
};

//OSDͼ��3���ò���
static const OSD_LayerCfg OSD_Layer3 = {
		.index = 3,
		.alpha_value = 0xff,
		.priority = XOSD_LAYER_PRIORITY_3,
		.alpha_enable = 0
};

#endif /* OSD_H_ */
