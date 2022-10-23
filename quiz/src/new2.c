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
                delay(25);
                for (uint8_t i = 0; i < 14; i++)
                {
                        if (i < 7)
                                PORTB <<= 1;
                        else
                                PORTB >>= 1;
                        delay(25);
                }
                lim++;
        }
        PORTB = 0x00;
}