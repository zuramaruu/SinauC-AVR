#ifndef __AVR_ATmega8535__
#define __AVR_ATmega8535__
#endif

#include "avr/io.h"
#define  F_CPU 1000000UL
#include "util/delay.h"

#define vchar    volatile unsigned char
#define NOL             0xC0
#define SATU            0xF9
#define DUA             0xA4
#define TIGA            0x30
#define EMPAT           0x19

#define LIMA            0x12
#define ENAM            0x02
#define TUJUH           0xB8
#define DELAPAN         0x00
#define SEMBILAN        0x10

#define DIG1            0x08
#define DIG2            0x04
#define DIG3            0x02
#define DIG4            0x01

int i;
char arr[] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};
char ord[] = {0xFF};

int  main();
void setIO();
void loop();
void set(vchar *, char num,vchar *,  char pos);

int main(void) { setup(); while (1) { loop(); } }

void setup() {
	DDRB = 0xFF;
        DDRD = 0xFF;
}

void loop() {
        for (i = 0; i < 8; i++) {
                set(&PORTD, arr[i], &PORTB , ord[0]);
                _delay_ms(500);
        }
}

void set(vchar *port_x, char val, vchar *port_y, char pos) {
        *port_x = val;
        *port_y = pos;
}
