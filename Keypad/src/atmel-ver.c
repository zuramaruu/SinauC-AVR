#define F_CPU 16000000UL

#include "avr/io.h"
#include "util/delay.h"
#include "../include/lcd.h"

#define NO_KEY '\0'

const char arr[4][4] = {{'/', '9', '8', '7'},
                        {'*', '6', '5', '4'},
                        {'-', '3', '2', '1'},
                        {'+', '=', '0', 'c'}};

int main(void)
{
        DDRA = 0x0f;
        DDRB = 0xff;
        DDRC = 0xff;
        PORTA = 0xf0; // R pull up (on)
        lcd_init(LCD_DISP_ON);
        lcd_gotoxy(0, 0);
        lcd_puts("key = ");

        while (1)
        {
                lcd_gotoxy(6, 0);
                char key = getKey();
                if (key != NO_KEY)
                        lcd_putc(key);
        }
}

char getKey()
{
        PORTA = 0xff;
        for (uint8_t i = 0; i < 4; i++)
        {
                PORTA <<= 1;
                if (i > 0)
                        PORTA |= 0x01;
                for (uint8_t j = 0; j < 4; j++)
                {
                        if (!(PINA & (0x80 >> j)))
                                return arr[i][j];
                }
        }
        return NO_KEY;
}