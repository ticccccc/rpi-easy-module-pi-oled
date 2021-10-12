#include <U8g2lib.h>
#include "system.h"

int main(void)
{
    // Check https://github.com/olikraus/u8g2/wiki/u8g2setupcpp for all supported devices
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C  u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
    
    System s;

    u8g2.begin();
    u8g2.clearBuffer();                         // clear the internal memory
    u8g2.setFont(u8g2_font_6x13_tr);            // choose a suitable font
    u8g2.drawStr(2, 18, s.ip().c_str());       // write something to the internal memory
    u8g2.sendBuffer();                          // transfer internal memory to the display
}