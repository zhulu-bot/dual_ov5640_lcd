//****************************************Copyright (c)***********************************//
//原子哥在线教学平台：www.yuanzige.com
//技术支持：www.openedv.com
//淘宝店铺：http://openedv.taobao.com
//关注微信公众平台微信号："正点原子"，免费获取ZYNQ & FPGA & STM32 & LINUX资料。
//版权所有，盗版必究。
//Copyright(C) 正点原子 2018-2028
//All rights reserved
//----------------------------------------------------------------------------------------
// File name:           osd
// Last modified Date:  2019/10/8 17:25:36
// Last Version:        V1.0
// Descriptions:        OSD IP核配置
//----------------------------------------------------------------------------------------
// Created by:          正点原子
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

//OSD图层配置结构体
typedef struct {
	u32 index;        //图层索引
	u32 alpha_value;  //图层透明度
	u32 priority;     //图像优先级
	u32 alpha_enable; //透明度使能
}OSD_LayerCfg;

//OSD图层0配置参数
static const OSD_LayerCfg OSD_Layer0 = {
		.index = 0,
		.alpha_value = 0xff,
		.priority = XOSD_LAYER_PRIORITY_0,
		.alpha_enable = 1
};

//OSD图层1配置参数
static const OSD_LayerCfg OSD_Layer1 = {
		.index = 1,
		.alpha_value = 0xff,
		.priority = XOSD_LAYER_PRIORITY_1,
		.alpha_enable = 1
};

//OSD图层2配置参数
static const OSD_LayerCfg OSD_Layer2 = {
		.index = 2,
		.alpha_value = 0xff,
		.priority = XOSD_LAYER_PRIORITY_2,
		.alpha_enable = 0
};

//OSD图层3配置参数
static const OSD_LayerCfg OSD_Layer3 = {
		.index = 3,
		.alpha_value = 0xff,
		.priority = XOSD_LAYER_PRIORITY_3,
		.alpha_enable = 0
};

#endif /* OSD_H_ */
