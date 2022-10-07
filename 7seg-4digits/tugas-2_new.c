#ifndef __AVR_ATmega8535__
#define __AVR_ATmega8535__
#endif

#include "avr/io.h"
#define  F_CPU 1000000UL
#include "util/delay.h"

#define vint     volatile unsigned int
#define NOL             0xC0
#define SATU            0xF9
#define DUA             0xA4
#define TIGA            0xB0
#define MATI            0xFF

#define digit           PORTB
#define data            PORTC
#define Output          0xFF

#define sum             4

int i, j, a;

vint dig[] = {PB0, PB1, PB2, PB3};

char alldata[sum][4] =  {{NOL, MATI, MATI, MATI},
                        {SATU, NOL, MATI, MATI},
                        {DUA, SATU, NOL, MATI},
                        {TIGA, DUA, SATU, NOL}};

int  main();
void setup();
void loop();
void iterate(char _data[sum][4]);
void set(vint *, char val);

int main(void) { setup(); while (1) { loop(); } }

void setup() {
	DDRC = Output;
        DDRB = Output;
}

void loop() {
        iterate(alldata);
}

void iterate(char _data[sum][4]){
        for (a = 0; a < sum; a++) {
                for (i = 0; i <= 270; i++){
                        for (j = 0; j < 4; j++){
                                set(&dig[j], _data[a][j]);
                        }       
                }
        }
}

void set(vint *port_x, char val) {
        digit |= (1 << *port_x);
        data = val;
        _delay_ms(1);
        digit &= ~(1 << *port_x);
}
