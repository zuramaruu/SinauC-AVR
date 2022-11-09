#include "../config/config.h"
#include "../utils/utils.h"
#include "../include/lcd.h"
#include "../utils/millis.h"

#define NO_KEY '\0'
#define MAX_INDEX 10
#define RESET 0

const char arr[4][4] = {{'/', '9', '8', '7'},
                        {'*', '6', '5', '4'},
                        {'-', '3', '2', '1'},
                        {'+', '=', '0', 'c'}};

uint8_t cursor = 0;

uint32_t u_time;
char buff[4];

void setup()
{
        DDRA = 0x0f;  // 0000 1111
        DDRC = 0xff;  // LCD
        PORTA = 0xf0; // R pull up 1111 0000
        lcd_init(LCD_DISP_ON_CURSOR);
        lcd_gotoxy(0, 0);
        lcd_puts("TIME:");
        init_millis(16000000UL);
        sei();
}

void loop()
{
        lcd_gotoxy(5, 0);
        utoa(millis(), buff, 10);
        lcd_puts(buff);

        lcd_gotoxy(0, 1);
        char key = getKey();
        if (key != NO_KEY)
        {
                if (cursor == MAX_INDEX)
                        reset();
                else
                {
                        lcd_gotoxy(cursor, 1);
                        lcd_putc(key);

                        cursor++;
                }
        }
}

char getKey()
{
        PORTA = 0xff;
        uint8_t read;
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
                do
                {
                        read = PINA;
                        read = read & 0xf0;
                } while (read != 0xf0);
        }
        return buff;
}

void reset()
{
        lcd_clrscr();
        lcd_gotoxy(0, 0);
        lcd_puts("TIME:");
        cursor = RESET;
}
