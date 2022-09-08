#include <avr/io.h>
#define #define F_CPU 12000000UL
#include <util/delay.h>

int main(void);
void _setIO(void);

void _setIO()
{
	// Set Output
	DDRB |= (1 << PB3);
	DDRB |= (1 << PB5) | (3 << PB2);
	
		
	//SetInput
	DDRB &= !(1 << PB4);
	DDRB &= !(1 << PB2) & !(1 << PB4) & !(1 << PB6)
}

int main(void)
{
	_setIO();
	
    while (1) 
    {
		//Pass
    }
}
