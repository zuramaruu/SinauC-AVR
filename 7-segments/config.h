#ifndef __AVR_ATmega8535__
#define __AVR_ATmega8535__
#endif

#include "avr/io.h"
#define F_CPU 1000000UL
#include "util/delay.h"

#define vint volatile unsigned int
#define NOL 0xC0
#define SATU 0xF9
#define DUA 0xA4
#define TIGA 0xB0
#define MATI 0xFF

#define digit PORTB
#define data PORTC
#define Output 0xFF

#define sum 4

#define pinModeB DDRB
#define pinModeC DDRC

int main();
void setup();
void loop();
void iterate(char _data[sum][4]);
void set(vint *, char val);

int main(void)
{
        setup();
        while (1)
        {
                loop();
        }
}

// #define setB PORTB
// #define setC PORTC
// #define Output 0xFF
// #define Input 0x00

// 0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F
// char arrnum[] = {0xBF, 0x06, 0xDB, 0xCF, 0xE6, 0xED, 0xF9, 0x87, 0xFF, 0xEF};