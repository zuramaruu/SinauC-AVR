#ifndef __AVR_ATmega32__
#define __AVR_ATmega32__
#endif

#include "avr/io.h"
#define  F_CPU 1000000UL
#include "util/delay.h"
#include "Pins.h"

#define vchar   volatile unsigned char
#define NOL     0xBF
#define DUA     0xDB

#define DIG1    0x08
#define DIG2    0x04
#define DIG3    0x02
#define DIG4    0x01

int i;
char arr[] = {DUA, NOL, DUA, NOL};
char ord[] = {DIG1, DIG2, DIG3, DIG4};

int  main();
void setIO();
void loop();
void set(vchar *, char num,vchar * ,  char pos);

int main(void) { setup(); while (1) { loop(); } }

void setup() {
	pinModeB = Output;
        pinModeC = Output;
}

void loop() {
	for (i = 0; i < 4; i++) {
                set(&setC, arr[i], &setB , ord[i]);
		_delay_ms(600);	
	}
}

void set(vchar *port_x, char num, vchar *port_y, char pos) {
        *port_x = num;
        *port_y = pos;
}
