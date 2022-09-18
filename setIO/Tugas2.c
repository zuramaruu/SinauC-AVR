#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main();
void setIO();
void runKasus1();
void runKasus2();

int main(void)
{
	setIO(); // SetOutput
	while (1) { runKTugas2(); } // Infitinite Loop()
}

void setIO() 
{
	DDRB = 0xFF;
	PORTB = 0x80;
}

void runKTugas2() 
{
	for (int i = 0; i < 8; i++)
	{
		PORTB >>= 1;
		PORTB |= 0x80;
		_delay_ms(100);
	}
	for (int i = 0; i < 8; i++)
	{
		PORTB <<= 1;
		_delay_ms(100);
	}
}
