#ifndef __AVR_ATmega8535__
#define __AVR_ATmega8535__
#endif

#include "avr/io.h"
#define  F_CPU 1000000UL
#include "util/delay.h"

#define vchar    volatile unsigned char
#define vint     volatile unsigned int
#define NOL             0xC0
#define SATU            0xF9
#define DUA             0xA4
#define TIGA            0x30
#define EMPAT           0x19
#define MATI            0xFF

#define digit           PORTB
#define data            PORTC
#define Output          0xFF

int i, j;

vint dig[] = {PB0, PB1, PB2, PB3};

char data1[] = {NOL, MATI, MATI, MATI};
char data2[] = {SATU, NOL, MATI, MATI};
char data3[] = {DUA, SATU, NOL, MATI};
char data4[] = {TIGA, DUA, SATU, NOL};

int  main();
void setup();
void loop();
void set(vint *, char val);
void iterate(char _data[]);

int main(void) { setup(); while (1) { loop(); } }

void setup() {
	DDRC = Output;
        DDRB = Output;
}

void loop() {
        run(data1);
        run(data2);
        run(data3);
        run(data4);
}

void run(char _data[]){
        for (i = 0; i <= 270; i++){
                for (j = 0; j < 4; j++){
                        set(&dig[j], _data[j]);
                }       
        }
}

void set(vint *port_x, char val) {
        digit |= (1 << *port_x);
        data = val;
        _delay_ms(1);
        digit &= ~(1 << *port_x);
}
