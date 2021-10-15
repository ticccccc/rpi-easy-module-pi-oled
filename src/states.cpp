#include <U8g2lib.h>
#include "system.h"

int main(void)
{
    // Check https://github.com/olikraus/u8g2/wiki/u8g2setupcpp for all supported devices
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C  u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
    
    System s;

    u8g2.begin();

    for(size_t total, idle; s.cpu(idle, total); sleep(60)) {

        size_t idle_d = idle - s.getIdleTime();
        size_t total_d = total - s.getTotalTime();

        char usage[8];
        sprintf(usage, "%.2f%", 100.0 * (1.0 - 1.0*idle_d/total_d));

        s.setIdleTime(idle);
        s.setTotalTime(total);

        u8g2.clearBuffer();                         // clear the internal memory
        u8g2.setFont(u8g2_font_6x13_tr);            // choose a suitable font
        char line[64];
        sprintf(line, "ip: %s cpu: %s", s.ip(), usage);
        u8g2.drawStr(1, 2, line);       // write something to the internal memory
        u8g2.sendBuffer();
    }
}