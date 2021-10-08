cmake_minimum_required(VERSION 3.16.0)
project(led VERSION 0.1.0
            DESCRIPTION "show machine statics on raspberry")

set(CMAKE_CXX_STANDARD 17)

# set bin prosition
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include(FetchContent)

# include u8g2 to show info on oleds

set(U8G2 u8g2)

FetchContent_Declare(
        ${U8G2}
        GIT_REPOSITORY https://hub.fastgit.org/olikraus/u8g2.git
        GIT_TAG 5d7eb072723b14c82d9b2d55093b3dc7ff0e8e7e)

# define register_component
function(register_component)
## csrc
configure_file(csrc/mui.h inc/c/mui.h COPYONLY)
configure_file(csrc/mui_u8g2.h inc/c/mui_u8g2.h COPYONLY)
configure_file(csrc/u8g2.h inc/c/u8g2.h COPYONLY)
configure_file(csrc/u8x8.h inc/c/u8x8.h COPYONLY)

configure_file(sys/arm-linux/drivers/gpio.h inc/c/gpio.h COPYONLY)
configure_file(sys/arm-linux/drivers/i2c.h inc/c/i2c.h COPYONLY)
configure_file(sys/arm-linux/drivers/spi.h inc/c/spi.h COPYONLY)

add_library(cmui STATIC
                csrc/mui.c)
add_library(cmuiu8g2 STATIC
                csrc/mui_u8g2.c)
add_library(cu8g2 STATIC
                csrc/mui_u8g2.c
                csrc/u8g2_bitmap.c
                csrc/u8g2_box.c
                csrc/u8g2_buffer.c
                csrc/u8g2_button.c
                csrc/u8g2_circle.c
                csrc/u8g2_cleardisplay.c
                csrc/u8g2_d_memory.c
                csrc/u8g2_d_setup.c
                csrc/u8g2_font.c
                csrc/u8g2_fonts.c
                csrc/u8g2_hvline.c
                csrc/u8g2_input_value.c
                csrc/u8g2_intersection.c
                csrc/u8g2_kerning.c
                csrc/u8g2_line.c
                csrc/u8g2_ll_hvline.c
                csrc/u8g2_message.c
                csrc/u8g2_polygon.c
                csrc/u8g2_selection_list.c
                csrc/u8g2_setup.c
                csrc/u8log_u8g2.c)
add_library(cu8x8 STATIC
                csrc/u8log_u8x8.c
                csrc/u8x8_8x8.c
                csrc/u8x8_byte.c
                csrc/u8x8_cad.c
                csrc/u8x8_capture.c
                csrc/u8x8_d_a2printer.c
                csrc/u8x8_debounce.c
                csrc/u8x8_d_hd44102.c
                csrc/u8x8_d_il3820_296x128.c
                csrc/u8x8_display.c
                csrc/u8x8_d_ist3020.c
                csrc/u8x8_d_ist7920.c
                csrc/u8x8_d_ks0108.c
                csrc/u8x8_d_lc7981.c
                csrc/u8x8_d_ld7032_60x32.c
                csrc/u8x8_d_ls013b7dh03.c
                csrc/u8x8_d_max7219.c
                csrc/u8x8_d_pcd8544_84x48.c
                csrc/u8x8_d_pcf8812.c
                csrc/u8x8_d_pcf8814_hx1230.c
                csrc/u8x8_d_s1d15721.c
                csrc/u8x8_d_s1d15e06.c
                csrc/u8x8_d_sbn1661.c
                csrc/u8x8_d_sed1330.c
                csrc/u8x8_d_sh1106_64x32.c
                csrc/u8x8_d_sh1106_72x40.c
                csrc/u8x8_d_sh1107.c
                csrc/u8x8_d_sh1108.c
                csrc/u8x8_d_sh1122.c
                csrc/u8x8_d_ssd1305.c
                csrc/u8x8_d_ssd1306_128x32.c
                csrc/u8x8_d_ssd1306_128x64_noname.c
                csrc/u8x8_d_ssd1306_2040x16.c
                csrc/u8x8_d_ssd1306_48x64.c
                csrc/u8x8_d_ssd1306_64x32.c
                csrc/u8x8_d_ssd1306_64x48.c
                csrc/u8x8_d_ssd1306_72x40.c
                csrc/u8x8_d_ssd1306_96x16.c
                csrc/u8x8_d_ssd1309.c
                csrc/u8x8_d_ssd1316.c
                csrc/u8x8_d_ssd1317.c
                csrc/u8x8_d_ssd1318.c
                csrc/u8x8_d_ssd1320.c
                csrc/u8x8_d_ssd1322.c
                csrc/u8x8_d_ssd1325.c
                csrc/u8x8_d_ssd1326.c
                csrc/u8x8_d_ssd1327.c
                csrc/u8x8_d_ssd1329.c
                csrc/u8x8_d_ssd1606_172x72.c
                csrc/u8x8_d_ssd1607_200x200.c
                csrc/u8x8_d_st7511.c
                csrc/u8x8_d_st75256.c
                csrc/u8x8_d_st7528.c
                csrc/u8x8_d_st75320.c
                csrc/u8x8_d_st7565.c
                csrc/u8x8_d_st7567.c
                csrc/u8x8_d_st7571.c
                csrc/u8x8_d_st7586s_erc240160.c
                csrc/u8x8_d_st7586s_s028hn118a.c
                csrc/u8x8_d_st7586s_ymc240160.c
                csrc/u8x8_d_st7588.c
                csrc/u8x8_d_st7920.c
                csrc/u8x8_d_stdio.c
                csrc/u8x8_d_t6963.c
                csrc/u8x8_d_uc1601.c
                csrc/u8x8_d_uc1604.c
                csrc/u8x8_d_uc1608.c
                csrc/u8x8_d_uc1610.c
                csrc/u8x8_d_uc1611.c
                csrc/u8x8_d_uc1617.c
                csrc/u8x8_d_uc1638.c
                csrc/u8x8_d_uc1701_dogs102.c
                csrc/u8x8_d_uc1701_mini12864.c
                csrc/u8x8_fonts.c
                csrc/u8x8_gpio.c
                csrc/u8x8_input_value.c
                csrc/u8x8_message.c
                csrc/u8x8_selection_list.c
                csrc/u8x8_setup.c
                csrc/u8x8_string.c
                csrc/u8x8_u16toa.c
                csrc/u8x8_u8toa.c)

add_library(cgpio STATIC sys/arm-linux/drivers/gpio.c)
add_library(ci2c STATIC sys/arm-linux/drivers/i2c.c)
add_library(cspi STATIC sys/arm-linux/drivers/spi.c)

## cppsrc
configure_file(sys/arm-linux/port/Print.h inc/cpp/Print.h COPYONLY)
configure_file(sys/arm-linux/port/Printable.h inc/cpp/Printable.h COPYONLY)
configure_file(sys/arm-linux/port/U8g2lib.h inc/cpp/U8g2lib.h COPYONLY)
configure_file(sys/arm-linux/port/u8g2port.h inc/cpp/u8g2port.h COPYONLY)
configure_file(sys/arm-linux/port/U8x8lib.h inc/cpp/U8x8lib.h COPYONLY)


add_library()


endfunction(register_component)

# enddeifine register_component
FetchContent_MakeAvailable(${U8G2})

# end include u8g2
add_subdirectory(${CMAKE_SOURCE_DIR}/src)