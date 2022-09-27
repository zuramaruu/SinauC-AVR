#ifndef __AVR_ATmega32__
#define __AVR_ATmega32__
#endif

#include "avr/io.h"
#define  F_CPU 1000000UL
#include "util/delay.h"

#define vchar   volatile unsigned char
#define NOL     0xC0
#define SATU    0xF9
#define DUA     0xA4
#define TIGA    0x30

#define DIG1    0x08
#define DIG2    0x04
#define DIG3    0x02
#define DIG4    0x01

int i;
char arr[] = {NOL, SATU, DUA, TIGA};
char ord[] = {DIG1, DIG2, DIG3, DIG4};

int  main();
void setIO();
void loop();
void set(vchar *, char num,vchar * ,  char pos);

int main(void) { setup(); while (1) { loop(); } }

void setup() {
	DDRB = 0xFF;
        DDRC = 0xFF;
}

void loop() {
	for (i = 0; i < 4; i++) {
                set(&PORTC, arr[i], &PORTB , ord[i]);
		_delay_ms(500);	
	}
}

void set(vchar *port_x, char val, vchar *port_y, char pos) {
        *port_x = val;
        *port_y = pos;
}