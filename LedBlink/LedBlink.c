#ifndef __AVR_ATmega32__
#define __AVR_ATmega32__
#endif

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int i;

int main();
void setIO();
void loop();

int main(void) { setIO(); while (1) { loop(); } }

void setIO()
{
	DDRB = 0xFF;
        DDRC = 0xFF;
        // PORTB = 0x80;
}

void loop()
{
	for (i = 1; i < 5; i++) {
                switch (i) {
                case 1: zero(); break;
                case 2: two(); break;
                case 3: zero(); break;
                case 4: two(); break;
                }
		_delay_ms(1000);	
	}
}

void two() {
        PORTB = 0x01;
        PORTC = 0xDB;
}

void zero() {
        PORTB = 0x08;
        PORTC = 0xBF;
}