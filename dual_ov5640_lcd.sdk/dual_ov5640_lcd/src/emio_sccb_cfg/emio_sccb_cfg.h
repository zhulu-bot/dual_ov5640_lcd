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

#include"xgpiops.h"
#include"sleep.h"

#ifndef sccb_EMIO_CFG_
#define sccb_EMIO_CFG_

#define EMIO_SCL0_NUM 54
#define EMIO_SDA0_NUM 55

#define EMIO_SCL1_NUM 56
#define EMIO_SDA1_NUM 57

#define CMOS_CH0      0  //CMOS0
#define CMOS_CH1      1  //CMOS1

void emio_init(void);
void sccb_start(u8 cmos_ch);
void sccb_stop(u8 cmos_ch);
void sccb_ack(u8 cmos_ch);
void sccb_send_byte(u8 cmos_ch,u8 txd);
u8  sccb_rece_byte(u8 cmos_ch);

#endif /* sccb_EMIO_CFG_ */
