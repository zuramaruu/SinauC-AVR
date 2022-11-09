#include "../config/config.h"
#include "../utils/utils.h"
#include "../include/lcd.h"

#define DEC 10
#define micro2Sec(us) (us * 1000000)
#define NO_KEY '\0'
#define MAX_INDEX 10
#define RESET 0

const char arr[4][4] = {{'/', '9', '8', '7'},
                        {'*', '6', '5', '4'},
                        {'-', '3', '2', '1'},
                        {'+', '=', '0', 'c'}};

char txt[10];
uint8_t cursor = RESET, index = RESET;

void setup()
{
        DDRA = 0x0f;
        DDRB = 0xff;
        DDRC = 0xff;
        PORTA = 0xf0; // R pull up (on)
        lcd_init(LCD_DISP_ON_CURSOR);
        lcd_gotoxy(0, 0);
        lcd_puts("PROGRAM KEYPAD");
}

void loop()
{
        char key = getKey();
        if (key != NO_KEY)
        {
                if (cursor == MAX_INDEX)
                        reset();
                else
                {
                        lcd_gotoxy(cursor, 1);
                        lcd_putc(key);
                        txt[index] = key;

                        cursor++;
                        index++;
                }
        }
}

char getScanning()
{
        PORTA = 0xff;
        char buff = NO_KEY;
        for (uint8_t i = 0; i < 4; i++)
        {
                PORTA <<= 1;
                if (i > 0)
                        PORTA |= 0x01;

                for (uint8_t j = 0; j < 4; j++)
                {
                        if (!(PINA & (0x80 >> j)))
                                buff = arr[i][j];
                }
        }
        return buff;
}

char getKey()
{
        char key = NO_KEY;
        while (getScanning() != NO_KEY)
        {
                // Ga ngapa" in
        }

        do
        {
                key = getScanning();
        } while (key == NO_KEY);
        return key;
}

void reset()
{
        lcd_clrscr();
        lcd_gotoxy(0, 0);
        lcd_puts("PROGRAM KEYPAD");
        memset(txt, 0, sizeof(txt));
        index = RESET;
        cursor = RESET;
}
