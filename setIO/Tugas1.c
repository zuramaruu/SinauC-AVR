#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main();
void setIO();
void runTugas1();

int main(void)
{
	setIO(); // SetOutput
	while (1) { runTugas1();} // Infitinite Loop()
}

void setIO()
{
	DDRB = 0xFF;
	PORTB = 0x80;
}

void runTugas1()
{
	for (int i = 0; i < 14; i++)
	{
		if (i > 6) PORTB <<= 1;
		else PORTB >>= 1;
		_delay_ms(100);
	}
}
