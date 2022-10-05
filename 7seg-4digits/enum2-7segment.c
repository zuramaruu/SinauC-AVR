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

char arr[]  = {NOL};
char arr2[] = {SATU, NOL};
char arr3[] = {DUA, SATU, NOL};
char arr4[] = {TIGA, DUA, SATU, NOL};
char ord[]  = {DIG1, DIG2, DIG3, DIG4};

uint8_t state = 0;

int  main();
void setIO();
void loop();
void set(vchar *, char val,vchar *,  char pos);
void iterate(int num, char value[]);

int main(void) { setup(); while (1) { loop(); } }

void setup() {
	DDRB = 0xFF;
        DDRD = 0xFF;
}

void loop() {
        if (state == 4) state = 0;
        for (i = 0; i <= 20; i++) {
                switch (state) 
                {
                        case 0: iterate(1, arr); break;
                        case 1: iterate(2, arr2); break;
                        case 2: iterate(3, arr3); break;
                        case 3: iterate(4, arr4); break; 
                }
                if (i == 20) state++;
        }
}

void iterate(int num, char value[]) {
        int j; for (j = 0; j < num; j++) { set(&PORTD, value[j], &PORTB, ord[j]); _delay_ms(50);}
}

void set(vchar *port_x, char val, vchar *port_y, char pos) {
        *port_x = val;
        *port_y = pos;
}
