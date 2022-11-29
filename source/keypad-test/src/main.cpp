#include "avr/io.h"
#define F_CPU 16000000UL
#include "util/delay.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "millis.h"
#include "lcd.h"

#define NO_KEY '\0'
#define MAX_INDEX 10
#define RESET 0
#define CLEAR 'c'

const char arr[4][4] = { {'/', '9', '8', '7'},
                         {'*', '6', '5', '4'},
                         {'-', '3', '2', '1'},
                         {'+', '=', '0', 'c'} };

uint8_t cursor = 0;

uint32_t u_time;
char buff[10];

char getKey();
void reset();

int main(void) {
        DDRA = 0x0f;  // 0000 1111
        DDRB = 0xff;  // LED
        DDRC = 0xff;  // LCD
        PORTA = 0xf0; // R pull up 1111 0000
        lcd_init(LCD_DISP_ON_CURSOR);
        lcd_gotoxy(0, 0);
        lcd_puts("TIME:");
        init_millis(16000000UL);
        sei();

        while (1) {
                lcd_gotoxy(5, 0);
                utoa(millis(), buff, 10);
                lcd_puts(buff);

                lcd_gotoxy(cursor, 1);
                char key = getKey();
                if (key != NO_KEY) {
                        if (cursor == MAX_INDEX || key == CLEAR) reset();
                        else {
                                lcd_gotoxy(cursor, 1);
                                lcd_putc(key);

                                cursor++;
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
                                PORTB = (uint8_t)arr[i][j];
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
        lcd_clrscr();
        lcd_gotoxy(0, 0);
        lcd_puts("TIME:");
        cursor = RESET;
}
