#include "config/config.h"
#include "utils/utils.h"

void setup()
{
        pinMode(PB, OUTPUT);
}

void loop()
{
        PORTB = 0x81;
        _delay_ms(50);

        for (uint8_t i = 2; i < 5; i++)
        {
                PORTB >>= 1;
                PORTB |= 0x80;
                PORTB |= (pows(2, i) - 1);
                _delay_ms(50);
        }
        /*               :231        :195      :36*/
        for (uint8_t i = 0xE7; i >= 0xC3; i -= 0x24)
        {
                PORTB &= i;
                _delay_ms(50);
        }
}

uint32_t pows(int x, int y)
{
        int res = 1;
        for (int i = 0; i < y; i++)
        {
                res *= x;
        }
        return res;
}
