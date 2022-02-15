-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
-- Date        : Mon Feb 14 10:38:59 2022
-- Host        : LAPTOP-0IRDMRHN running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               C:/Users/86182/Desktop/36_dual_ov5640_lcd/dual_ov5640_lcd.srcs/sources_1/bd/system/system_stub.vhdl
-- Design      : system
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg400-2
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity system is
  Port ( 
    DDR_addr : inout STD_LOGIC_VECTOR ( 14 downto 0 );
    DDR_ba : inout STD_LOGIC_VECTOR ( 2 downto 0 );
    DDR_cas_n : inout STD_LOGIC;
    DDR_ck_n : inout STD_LOGIC;
    DDR_ck_p : inout STD_LOGIC;
    DDR_cke : inout STD_LOGIC;
    DDR_cs_n : inout STD_LOGIC;
    DDR_dm : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dq : inout STD_LOGIC_VECTOR ( 31 downto 0 );
    DDR_dqs_n : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dqs_p : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_odt : inout STD_LOGIC;
    DDR_ras_n : inout STD_LOGIC;
    DDR_reset_n : inout STD_LOGIC;
    DDR_we_n : inout STD_LOGIC;
    FIXED_IO_ddr_vrn : inout STD_LOGIC;
    FIXED_IO_ddr_vrp : inout STD_LOGIC;
    FIXED_IO_mio : inout STD_LOGIC_VECTOR ( 53 downto 0 );
    FIXED_IO_ps_clk : inout STD_LOGIC;
    FIXED_IO_ps_porb : inout STD_LOGIC;
    FIXED_IO_ps_srstb : inout STD_LOGIC;
    aclken_0 : in STD_LOGIC;
    aclken_1 : in STD_LOGIC;
    cam_data_0 : in STD_LOGIC_VECTOR ( 7 downto 0 );
    cam_data_1 : in STD_LOGIC_VECTOR ( 7 downto 0 );
    cam_href_0 : in STD_LOGIC;
    cam_href_1 : in STD_LOGIC;
    cam_pclk_0 : in STD_LOGIC;
    cam_pclk_1 : in STD_LOGIC;
    cam_pwdn_0 : out STD_LOGIC;
    cam_pwdn_1 : out STD_LOGIC;
    cam_rst_n_0 : out STD_LOGIC;
    cam_rst_n_1 : out STD_LOGIC;
    cam_vsync_0 : in STD_LOGIC;
    cam_vsync_1 : in STD_LOGIC;
    emio_sccb_tri_i : in STD_LOGIC_VECTOR ( 3 downto 0 );
    emio_sccb_tri_o : out STD_LOGIC_VECTOR ( 3 downto 0 );
    emio_sccb_tri_t : out STD_LOGIC_VECTOR ( 3 downto 0 );
    lcd_bl : out STD_LOGIC;
    lcd_clk : out STD_LOGIC;
    lcd_de : out STD_LOGIC;
    lcd_hs : out STD_LOGIC;
    lcd_rgb_tri_i : in STD_LOGIC_VECTOR ( 23 downto 0 );
    lcd_rgb_tri_o : out STD_LOGIC_VECTOR ( 23 downto 0 );
    lcd_rgb_tri_t : out STD_LOGIC_VECTOR ( 23 downto 0 );
    lcd_rst : out STD_LOGIC;
    lcd_vs : out STD_LOGIC
  );

end system;

architecture stub of system is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "DDR_addr[14:0],DDR_ba[2:0],DDR_cas_n,DDR_ck_n,DDR_ck_p,DDR_cke,DDR_cs_n,DDR_dm[3:0],DDR_dq[31:0],DDR_dqs_n[3:0],DDR_dqs_p[3:0],DDR_odt,DDR_ras_n,DDR_reset_n,DDR_we_n,FIXED_IO_ddr_vrn,FIXED_IO_ddr_vrp,FIXED_IO_mio[53:0],FIXED_IO_ps_clk,FIXED_IO_ps_porb,FIXED_IO_ps_srstb,aclken_0,aclken_1,cam_data_0[7:0],cam_data_1[7:0],cam_href_0,cam_href_1,cam_pclk_0,cam_pclk_1,cam_pwdn_0,cam_pwdn_1,cam_rst_n_0,cam_rst_n_1,cam_vsync_0,cam_vsync_1,emio_sccb_tri_i[3:0],emio_sccb_tri_o[3:0],emio_sccb_tri_t[3:0],lcd_bl,lcd_clk,lcd_de,lcd_hs,lcd_rgb_tri_i[23:0],lcd_rgb_tri_o[23:0],lcd_rgb_tri_t[23:0],lcd_rst,lcd_vs";
begin
end;
