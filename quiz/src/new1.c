#define F_CPU 16000000UL

#include "avr/io.h"
#include "util/delay.h"
int main(void)
{
        DDRB = 0xff;
        uint8_t loop = 0;
        while (loop < 4)
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
                loop++;
        }
        PORTB = 0x00;
}