#include <U8g2lib.h>

// Check https://github.com/olikraus/u8g2/wiki/u8g2setupcpp for all supported devices
static U8G2_SSD1306_128X64_NONAME_F_HW_I2C  u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int main(void)
{
    u8g2.begin();
    u8g2.clearBuffer();                         // clear the internal memory
    u8g2.setFont(u8g2_font_6x13_tr);            // choose a suitable font
    u8g2.drawStr(2, 18, "U8g2");                // write something to the internal memory
    u8g2.sendBuffer();                          // transfer internal memory to the display
}