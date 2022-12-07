#include "avr/io.h"
#define F_CPU 16000000UL
#include "util/delay.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <util/atomic.h>
#include <avr/interrupt.h>
#include "stdbool.h"

void set(uint8_t* port_x, char val);
void display(void);
void reset();

uint8_t num[] = { 0xc0, 0xf9, 0xa4, 0xb0, 0x99,
                  0x92, 0x82, 0xf8, 0x80, 0x90 };

int8_t en[4];
uint8_t buffer[4];

uint8_t dig[4] = { PB0, PB1, PB2, PB3 };

int main() {
        DDRA = 0xff;
        DDRB = 0xff;
        DDRD &= ~(1 << PD2) & ~(1 << PD3);
        PORTD |= (1 << PD2) | (1 << PD3);
        MCUCR |= (1 << ISC01) | (1 << ISC00) | (1 << ISC11) | (1 << ISC10); //INT0 aktif transisi naik
        GICR |= (1 << INT0) | (1 << INT1);
        reset();
        sei();

        while (1) {
                display();
        }
}

ISR(INT0_vect) {
        if (en[0] > 9) reset();
        else en[3]++;

        for (uint8_t i = 3; i > 0; i--) {
                if (en[i] > 9) {
                        en[i] = 0;
                        en[i - 1]++;
                }
        }
}

ISR(INT1_vect) {
        if (!(en[3] == 0 && en[2] == 0
                && en[1] == 0 && en[0] == 0)) {
                en[3]--;
        }

        for (uint8_t i = 3; i > 0; i--) {
                if (en[i] < 0) {
                        en[i] = 9;
                        en[i - 1]--;
                }
        }
}

void display(void) {
        for (int i = 0; i < 4; i++) { // 0 1 2 3
                buffer[i] = num[en[i]];
                set(&dig[i], buffer[i]);
        }
}

void set(uint8_t* port_x, char val) {
        PORTB |= (1 << *port_x);
        PORTA = val;
        _delay_ms(1);
        PORTB &= ~(1 << *port_x);
}

void reset() {
        for (uint8_t i = 0; i < 4; i++) {
                buffer[i] = num[0];
                en[i] = 0;
        }
}