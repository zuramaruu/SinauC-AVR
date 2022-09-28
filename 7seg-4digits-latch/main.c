#ifndef __AVR_ATmega16__
#define __AVR_ATmega16__
#endif

#include "avr/io.h"
#define  F_CPU 1000000UL
#include "util/delay.h"

int  main();
void setup();
void loop();
int main(void) { setup(); for (;;) { loop(); } }

void setup() {
        DDRB |= (7 << PB0);
}

void loop() {
        uint8_t bufferDisplay[] = {0x66, 0x4f, 0x5b, 0x06};
        uint8_t i, a;
        for (a = 0; a <= 3; a++) {
                uint8_t data = bufferDisplay[a];
                for (i = 0x80; i > 0; i>>=1) {
                        if (data & i)
                                PORTB |= (1 << PB0);
                        else
                                PORTB &= ~(1 << PB0);
                        PORTB |= (1 << PB1); PORTB &= ~(1 << PB1);
                }
        }
        PORTB |= (1 << PB2);PORTB &= ~(1 << PB2);
}
