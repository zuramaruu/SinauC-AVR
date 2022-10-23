#include "../config/config.h"
#include "../utils/utils.h"

void setup()
{
        DDRB = 0xFF;
}

void loop()
{
        PORTB = 0xC0;
        _delay_ms(25);
        for (uint8_t i = 0; i < 12; i++)
        {
                if (i < 6)
                        PORTB >>= 1;
                else
                        PORTB <<= 1;
                _delay_ms(25);
        }
}