#----------------------摄像头接口的时钟---------------------------
#72M
create_clock -period 13.888 -name cam_pclk [get_ports cam_pclk_0]
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets cam_pclk_0_IBUF]

create_clock -period 13.888 -name cam_pclk [get_ports cam_pclk_1]
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets cam_pclk_1_IBUF]

#----------------------LCD接口---------------------------
set_property -dict {PACKAGE_PIN W18 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[0]}]
set_property -dict {PACKAGE_PIN W19 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[1]}]
set_property -dict {PACKAGE_PIN R16 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[2]}]
set_property -dict {PACKAGE_PIN R17 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[3]}]
set_property -dict {PACKAGE_PIN W20 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[4]}]
set_property -dict {PACKAGE_PIN V20 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[5]}]
set_property -dict {PACKAGE_PIN P18 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[6]}]
set_property -dict {PACKAGE_PIN N17 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[7]}]
set_property -dict {PACKAGE_PIN V17 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[8]}]
set_property -dict {PACKAGE_PIN V18 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[9]}]
set_property -dict {PACKAGE_PIN T17 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[10]}]
set_property -dict {PACKAGE_PIN R18 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[11]}]
set_property -dict {PACKAGE_PIN Y18 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[12]}]
set_property -dict {PACKAGE_PIN Y19 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[13]}]
set_property -dict {PACKAGE_PIN P15 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[14]}]
set_property -dict {PACKAGE_PIN P16 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[15]}]
set_property -dict {PACKAGE_PIN V16 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[16]}]
set_property -dict {PACKAGE_PIN W16 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[17]}]
set_property -dict {PACKAGE_PIN T14 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[18]}]
set_property -dict {PACKAGE_PIN T15 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[19]}]
set_property -dict {PACKAGE_PIN Y17 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[20]}]
set_property -dict {PACKAGE_PIN Y16 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[21]}]
set_property -dict {PACKAGE_PIN T16 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[22]}]
set_property -dict {PACKAGE_PIN U17 IOSTANDARD LVCMOS33} [get_ports {lcd_rgb_tri_io[23]}]

set_property -dict {PACKAGE_PIN N18 IOSTANDARD LVCMOS33} [get_ports lcd_hs]
set_property -dict {PACKAGE_PIN T20 IOSTANDARD LVCMOS33} [get_ports lcd_vs]
set_property -dict {PACKAGE_PIN U20 IOSTANDARD LVCMOS33} [get_ports lcd_de]
set_property -dict {PACKAGE_PIN M20 IOSTANDARD LVCMOS33} [get_ports lcd_bl]
set_property -dict {PACKAGE_PIN P19 IOSTANDARD LVCMOS33} [get_ports lcd_clk]
set_property PACKAGE_PIN L17 [get_ports lcd_rst]
set_property IOSTANDARD LVCMOS33 [get_ports lcd_rst]

#----------------------摄像头接口1---------------------------
set_property -dict {PACKAGE_PIN U10 IOSTANDARD LVCMOS33} [get_ports cam_rst_n_0]
set_property -dict {PACKAGE_PIN V11 IOSTANDARD LVCMOS33} [get_ports cam_pwdn_0]
set_property -dict {PACKAGE_PIN T9 IOSTANDARD LVCMOS33} [get_ports {cam_data_0[0]}]
set_property -dict {PACKAGE_PIN W6 IOSTANDARD LVCMOS33} [get_ports {cam_data_0[1]}]
set_property -dict {PACKAGE_PIN V6 IOSTANDARD LVCMOS33} [get_ports {cam_data_0[2]}]
set_property -dict {PACKAGE_PIN Y7 IOSTANDARD LVCMOS33} [get_ports {cam_data_0[3]}]
set_property -dict {PACKAGE_PIN Y6 IOSTANDARD LVCMOS33} [get_ports {cam_data_0[4]}]
set_property -dict {PACKAGE_PIN Y9 IOSTANDARD LVCMOS33} [get_ports {cam_data_0[5]}]
set_property -dict {PACKAGE_PIN Y8 IOSTANDARD LVCMOS33} [get_ports {cam_data_0[6]}]
set_property -dict {PACKAGE_PIN W10 IOSTANDARD LVCMOS33} [get_ports {cam_data_0[7]}]
set_property -dict {PACKAGE_PIN U9 IOSTANDARD LVCMOS33} [get_ports cam_href_0]
set_property -dict {PACKAGE_PIN W9 IOSTANDARD LVCMOS33} [get_ports cam_pclk_0]
set_property -dict {PACKAGE_PIN W8 IOSTANDARD LVCMOS33} [get_ports cam_vsync_0]
#cam_scl:
set_property -dict {PACKAGE_PIN V8 IOSTANDARD LVCMOS33} [get_ports {emio_sccb_tri_io[0]}]
#cam_sda:
set_property -dict {PACKAGE_PIN U8 IOSTANDARD LVCMOS33} [get_ports {emio_sccb_tri_io[1]}]
#pull up
set_property PULLUP true [get_ports {emio_sccb_tri_io[0]}]
set_property PULLUP true [get_ports {emio_sccb_tri_io[1]}]

#----------------------摄像头接口2---------------------------
set_property -dict {PACKAGE_PIN V13 IOSTANDARD LVCMOS33} [get_ports cam_rst_n_1]
set_property -dict {PACKAGE_PIN V10 IOSTANDARD LVCMOS33} [get_ports cam_pwdn_1]
set_property -dict {PACKAGE_PIN U13 IOSTANDARD LVCMOS33} [get_ports {cam_data_1[0]}]
set_property -dict {PACKAGE_PIN U14 IOSTANDARD LVCMOS33} [get_ports {cam_data_1[1]}]
set_property -dict {PACKAGE_PIN U15 IOSTANDARD LVCMOS33} [get_ports {cam_data_1[2]}]
set_property -dict {PACKAGE_PIN V12 IOSTANDARD LVCMOS33} [get_ports {cam_data_1[3]}]
set_property -dict {PACKAGE_PIN W13 IOSTANDARD LVCMOS33} [get_ports {cam_data_1[4]}]
set_property -dict {PACKAGE_PIN W14 IOSTANDARD LVCMOS33} [get_ports {cam_data_1[5]}]
set_property -dict {PACKAGE_PIN Y14 IOSTANDARD LVCMOS33} [get_ports {cam_data_1[6]}]
set_property -dict {PACKAGE_PIN V15 IOSTANDARD LVCMOS33} [get_ports {cam_data_1[7]}]
set_property -dict {PACKAGE_PIN Y11 IOSTANDARD LVCMOS33} [get_ports cam_href_1]
set_property -dict {PACKAGE_PIN W15 IOSTANDARD LVCMOS33} [get_ports cam_pclk_1]
set_property -dict {PACKAGE_PIN Y13 IOSTANDARD LVCMOS33} [get_ports cam_vsync_1]
#cam_scl:
set_property -dict {PACKAGE_PIN Y12 IOSTANDARD LVCMOS33} [get_ports {emio_sccb_tri_io[2]}]
#cam_sda:
set_property -dict {PACKAGE_PIN W11 IOSTANDARD LVCMOS33} [get_ports {emio_sccb_tri_io[3]}]
#pull up
set_property PULLUP true [get_ports {emio_sccb_tri_io[2]}]
set_property PULLUP true [get_ports {emio_sccb_tri_io[3]}]



set_property PACKAGE_PIN L14 [get_ports aclken_0]
set_property PACKAGE_PIN K16 [get_ports aclken_1]
set_property IOSTANDARD LVCMOS33 [get_ports aclken_1]
set_property IOSTANDARD LVCMOS33 [get_ports aclken_0]
