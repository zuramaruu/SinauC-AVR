#include "avr/io.h"
#define F_CPU 16000000UL
#include "util/delay.h"

void getKey();
void set(uint8_t* port_x, char val);
void shiftDisp(void);
void display(void);

const uint8_t num[4][4] = { {0xbf, 0x90, 0x80, 0xf8},
                            {0xbf, 0x82, 0x92, 0x99},
                            {0xbf, 0xb0, 0xa4, 0xf9},
                            {0xbf, 0xbf, 0xc0, 0xff} };

uint8_t isPress, buffer;

uint8_t bufferDisp[4] = { 0x92, 0x99, 0xff, 0x90 };
uint8_t dig[4] = { PB0, PB1, PB2, PB3 };

int main() {
        DDRA = 0x0f;  // KeyPad
        DDRB = 0xff;  // Digit
        DDRD = 0xff;  // 7segment

        while (1) {
                isPress = 0;
                getKey();
                shiftDisp();
                display();
        }
}

void shiftDisp(void) {
        if (isPress) {
                for (uint8_t i = 0; i < 3; i++) {
                        bufferDisp[i] = bufferDisp[i + 1];
                        bufferDisp[i] |= 0x80;
                }
                bufferDisp[3] = buffer;
        }
}

void display(void) {
        for (int j = 0; j < 4; j++) { // 0 1 2 3
                set(&dig[j], bufferDisp[j]);
        }
}

void set(uint8_t* port_x, char val) {
        PORTB |= (1 << *port_x);
        PORTD = val;
        _delay_ms(1);
        PORTB &= ~(1 << *port_x);
}

void getKey(void) {
        PORTA = 0xff;
        uint8_t guard;

        for (uint8_t i = 0; i < 4; i++) {
                PORTA <<= 1;
                if (i > 0) PORTA |= 0x01;

                for (uint8_t j = 0; j < 4; j++) {
                        if (!(PINA & (0x80 >> j))) {
                                isPress = 1;
                                buffer = num[i][j];
                                buffer &= 0x7f;
                                _delay_ms(3);
                        }
                }

                do {
                        guard = PINA;
                        guard &= 0xf0;
                } while (guard != 0xf0);
        }
}