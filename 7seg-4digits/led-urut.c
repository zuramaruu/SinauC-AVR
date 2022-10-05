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
#define TIGA            0xB0
#define EMPAT           0x99

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
char arr[] = {NOL, NOL, NOL, SATU};
char arr2[] = {NOL, NOL, SATU, DUA};
char arr3[] = {NOL, SATU, DUA, TIGA};
char arr4[] = {SATU, DUA, TIGA, EMPAT};
char ord[] = {DIG4, DIG3, DIG2, DIG1};


uint8_t state = 0;

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
        for (i = 0; i < 4; i++) {
                if (state < 4) set(&PORTD, arr[i], &PORTB , ord[i]);
                else if (state < 8) set(&PORTD, arr2[i], &PORTB , ord[i]);
                else if (state < 12) set(&PORTD, arr3[i], &PORTB , ord[i]);
                else if (state < 16) set(&PORTD, arr4[i], &PORTB , ord[i]);
                _delay_ms(500);
                state++;
                if (state == 16) state = 0;
        }
}

void set(vchar *port_x, char val, vchar *port_y, char pos) {
        *port_x = val;
        *port_y = pos;
}
