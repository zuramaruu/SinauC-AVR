#include "config.h"

int main(void) {

        DDRD &= ~(1 << PD2); //PD2 sbg. Input (INT0)
        PORTD |= (1 << PD2); //R-pullup ON

        DDRA |= (1 << PA0); //PA0 sbg. Out (LED)

        MCUCR |= (1 << ISC01) | (1 << ISC00); //INT0 aktif transisi naik
        GICR |= (1 << INT0); //Enable INT0
        sei();

        for (;;) {

        }
}

SIGNAL(INT0_vect) {
        PORTA ^= (1 << PA0);
}