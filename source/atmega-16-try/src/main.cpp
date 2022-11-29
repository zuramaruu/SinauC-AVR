#include "avr/io.h"
#define F_CPU 16000000UL
#include "util/delay.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "lcd.h"

#define NO_LED_ON
#define NO_USING_MILLIS

#ifdef USING_MILLIS
#include "millis.h"
#endif

#define NO_KEY '\0'
#define MAX_INDEX 10
#define RESET 0
#define CLEAR 'c'
#define EQUALS '='

#define ADD '+'
#define SUBS '-'
#define MULTIPLIED '*'
#define DIVIDED '/'

const char arr[4][4] = { {'/', '9', '8', '7'},
                         {'*', '6', '5', '4'},
                         {'-', '3', '2', '1'},
                         {'+', '=', '0', 'c'} };

uint8_t cursor = 0;
uint8_t n_value = 0;
char num[3][16];
int indx[2] = { 0, 0 };
char OP;

char getKey();
void reset();

int main(void) {
        DDRA = 0x0f;  // 0000 1111
        DDRB = 0xff;  // LED
        DDRC = 0xff;  // LCD
        PORTA = 0xf0; // R pull up 1111 0000
        lcd_init(LCD_DISP_ON);
        lcd_gotoxy(0, 0);
        lcd_puts("STARTING ...");
        _delay_ms(100);
        lcd_clrscr();
        lcd_init(LCD_DISP_ON_CURSOR);

#ifdef USING_MILLIS
        init_millis(16000000UL);
        sei();
#endif

        while (1) {
                lcd_gotoxy(15, 0);
                char key = getKey();
                if (key != NO_KEY) {
                        if (isdigit(key)) {
                                if (!n_value) num[0][indx[0]] = key;
                                else num[1][indx[0]] = key;
                                indx[0]++;
                        }
                        else {
                                if (key == CLEAR) reset();
                                else if (key == EQUALS) {

                                        double res;
                                        double x = (double)atol(num[0]);
                                        double y = (double)atol(num[1]);

                                        switch (OP) {

                                        case ADD: res = x + y; break;
                                        case SUBS: res = x - y; break;
                                        case MULTIPLIED: res = x * y; break;
                                        case DIVIDED: res = x / y; break;

                                        }

                                        char str[35];
                                        dtostrf(res, 0, 3, str);

                                        lcd_gotoxy(0, 1);
                                        lcd_puts(str);
                                }
                                else {
                                        OP = key;
                                        n_value = 1;
                                        indx[0] = 0;
                                }
                        }

                        if (key == CLEAR) reset();
                        else {
                                if (indx[1] < 16) {
                                        num[2][indx[1]] = key;
                                        indx[1]++;

                                        lcd_gotoxy(15 - indx[1] + 1, 0);
                                        lcd_puts(num[2]);
                                }
                        }
                }
        }
}

char getKey(void) {
        PORTA = 0xff;
        uint8_t guard;
        char buff = NO_KEY;
        for (uint8_t i = 0; i < 4; i++) {
                PORTA <<= 1;
                if (i > 0) PORTA |= 0x01;

                for (uint8_t j = 0; j < 4; j++) {
                        if (!(PINA & (0x80 >> j))) {
                                buff = arr[i][j];
#ifdef LED_ON
                                PORTB = (uint8_t)arr[i][j];
#endif
                                _delay_ms(3);
                        }
                }

                do {
                        guard = PINA;
                        guard &= 0xf0;
                } while (guard != 0xf0);
        }
        return buff;
}

void reset(void) {
        for (uint8_t i = 0; i < 4; i++) {
                for (uint8_t j = 0; j < 16; j++) {
                        num[i][j] = NO_KEY;
                }

        }

        n_value = 0;
        indx[0] = 0;
        indx[1] = 0;
        cursor = RESET;
        lcd_clrscr();
}