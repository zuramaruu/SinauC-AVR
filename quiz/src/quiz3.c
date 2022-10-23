#include "../config/config.h"
#include "../utils/utils.h"

void setup()
{
        DDRB = 0xff;
}

void loop()
{

        PORTB = 0xff;
        _delay_ms(15);
        for (uint8_t i = 0; i <= 16; i++)
        {
                if (i < 8)
                        PORTB <<= 1;
                else if (i > 8)
                        PORTB >>= 1;
                else
                        PORTB = 0xff;
                _delay_ms(15);
        }
}
