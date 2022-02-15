// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
// Date        : Mon Feb 14 10:38:59 2022
// Host        : LAPTOP-0IRDMRHN running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               C:/Users/86182/Desktop/36_dual_ov5640_lcd/dual_ov5640_lcd.srcs/sources_1/bd/system/system_stub.v
// Design      : system
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-2
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
module system(DDR_addr, DDR_ba, DDR_cas_n, DDR_ck_n, DDR_ck_p, 
  DDR_cke, DDR_cs_n, DDR_dm, DDR_dq, DDR_dqs_n, DDR_dqs_p, DDR_odt, DDR_ras_n, DDR_reset_n, DDR_we_n, 
  FIXED_IO_ddr_vrn, FIXED_IO_ddr_vrp, FIXED_IO_mio, FIXED_IO_ps_clk, FIXED_IO_ps_porb, 
  FIXED_IO_ps_srstb, aclken_0, aclken_1, cam_data_0, cam_data_1, cam_href_0, cam_href_1, 
  cam_pclk_0, cam_pclk_1, cam_pwdn_0, cam_pwdn_1, cam_rst_n_0, cam_rst_n_1, cam_vsync_0, 
  cam_vsync_1, emio_sccb_tri_i, emio_sccb_tri_o, emio_sccb_tri_t, lcd_bl, lcd_clk, lcd_de, 
  lcd_hs, lcd_rgb_tri_i, lcd_rgb_tri_o, lcd_rgb_tri_t, lcd_rst, lcd_vs)
/* synthesis syn_black_box black_box_pad_pin="DDR_addr[14:0],DDR_ba[2:0],DDR_cas_n,DDR_ck_n,DDR_ck_p,DDR_cke,DDR_cs_n,DDR_dm[3:0],DDR_dq[31:0],DDR_dqs_n[3:0],DDR_dqs_p[3:0],DDR_odt,DDR_ras_n,DDR_reset_n,DDR_we_n,FIXED_IO_ddr_vrn,FIXED_IO_ddr_vrp,FIXED_IO_mio[53:0],FIXED_IO_ps_clk,FIXED_IO_ps_porb,FIXED_IO_ps_srstb,aclken_0,aclken_1,cam_data_0[7:0],cam_data_1[7:0],cam_href_0,cam_href_1,cam_pclk_0,cam_pclk_1,cam_pwdn_0,cam_pwdn_1,cam_rst_n_0,cam_rst_n_1,cam_vsync_0,cam_vsync_1,emio_sccb_tri_i[3:0],emio_sccb_tri_o[3:0],emio_sccb_tri_t[3:0],lcd_bl,lcd_clk,lcd_de,lcd_hs,lcd_rgb_tri_i[23:0],lcd_rgb_tri_o[23:0],lcd_rgb_tri_t[23:0],lcd_rst,lcd_vs" */;
  inout [14:0]DDR_addr;
  inout [2:0]DDR_ba;
  inout DDR_cas_n;
  inout DDR_ck_n;
  inout DDR_ck_p;
  inout DDR_cke;
  inout DDR_cs_n;
  inout [3:0]DDR_dm;
  inout [31:0]DDR_dq;
  inout [3:0]DDR_dqs_n;
  inout [3:0]DDR_dqs_p;
  inout DDR_odt;
  inout DDR_ras_n;
  inout DDR_reset_n;
  inout DDR_we_n;
  inout FIXED_IO_ddr_vrn;
  inout FIXED_IO_ddr_vrp;
  inout [53:0]FIXED_IO_mio;
  inout FIXED_IO_ps_clk;
  inout FIXED_IO_ps_porb;
  inout FIXED_IO_ps_srstb;
  input aclken_0;
  input aclken_1;
  input [7:0]cam_data_0;
  input [7:0]cam_data_1;
  input cam_href_0;
  input cam_href_1;
  input cam_pclk_0;
  input cam_pclk_1;
  output cam_pwdn_0;
  output cam_pwdn_1;
  output cam_rst_n_0;
  output cam_rst_n_1;
  input cam_vsync_0;
  input cam_vsync_1;
  input [3:0]emio_sccb_tri_i;
  output [3:0]emio_sccb_tri_o;
  output [3:0]emio_sccb_tri_t;
  output lcd_bl;
  output lcd_clk;
  output lcd_de;
  output lcd_hs;
  input [23:0]lcd_rgb_tri_i;
  output [23:0]lcd_rgb_tri_o;
  output [23:0]lcd_rgb_tri_t;
  output lcd_rst;
  output lcd_vs;
endmodule
