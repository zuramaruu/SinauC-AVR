#define F_CPU 16000000UL

#include "avr/io.h"
#include "util/delay.h"

int main(void)
{
        DDRB = 0xff;
        uint8_t lim = 0;
        while (lim < 4)
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
                lim++;
        }
        PORTB = 0x00;
}