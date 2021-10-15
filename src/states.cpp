#include <U8g2lib.h>
#include "system.h"

int main(void)
{
    // Check https://github.com/olikraus/u8g2/wiki/u8g2setupcpp for all supported devices
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C  u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
    
    System s;

    u8g2.begin();

    for(size_t total, idle; s.cpu(idle, total); sleep(30)) {

        u8g2.clearBuffer();
        u8g2.sendBuffer(); 
        
        sleep(30);

        size_t idle_d = idle - s.getIdleTime();
        size_t total_d = total - s.getTotalTime();

        s.setIdleTime(idle);
        s.setTotalTime(total);

        u8g2.clearBuffer();                         // clear the internal memory
        u8g2.setFont(u8g2_font_6x13_tr);            // choose a suitable font
        
        char first[64];
        sprintf(first, "ip: %s", s.ip().c_str());

        char second[30];
        sprintf(second, "cpu: %.2f%% mem: %.2f%%", 100.0 * (1.0 - 1.0*idle_d/total_d), s.memory());

        char third[30];
        sprintf(third, "SD: %.2f%%", s.storage());

        u8g2.drawStr(1, 16, first);       // write something to the internal memory
        u8g2.drawStr(1, 32, second);
        u8g2.drawStr(1, 48, third);
        u8g2.sendBuffer();
    }
}