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
uint8_t cursor = 0, index = 0;
int numbers[2], result, op;

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
        lcd_gotoxy(cursor, 1);
        char key = getKey();
        if (key != NO_KEY)
        {
                if (isdigit(key))
                {
                        if (cursor == MAX_INDEX)
                                reset();
                        else
                        {
                                lcd_gotoxy(cursor, 1);
                                lcd_putc(key);
                                txt[index] = key;
                                numbers[2] = atoi(txt);

                                cursor++;
                                index++;
                        }
                }
                else
                {
                        if (key != '=')
                        {
                                numbers[1] = numbers[2];
                                op = key;
                        }
                        else
                        {
                                switch (op)
                                {
                                case '+':
                                        break;
                                case '-':
                                        break;
                                }
                        }
                }
        }
}

char getKey()
{
        char buff = NO_KEY;
        uint8_t read;
        PORTA = 0xff;
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
        lcd_puts("PROGRAM KEYPAD");
        memset(txt, 0, sizeof(txt));
        index = RESET;
        cursor = RESET;
}