#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{
	
    DDRB = 0xFF; // SetOutput
	
    while (1) 
    {
		PORTB = 0x80;
		for (int i = 0; i < 8; i++)
		{
			PORTB >>= 1;
			PORTB |= 0x80;
			_delay_ms(100);
		}
		for (int i = 0; i < 8; i++)
		{
			PORTB <<= 1;
			PORTB |= 0x00;
			_delay_ms(100);
		}
		
    }
}
