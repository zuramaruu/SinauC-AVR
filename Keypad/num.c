#include "../config/config.h"
#include "../utils/utils.h"
#include "../include/lcd.h"

#define DEC 10
#define micro2Sec(us) (us * 1000000)
#define NO_KEY '\0'

const uint8_t num[4][4] = {{10, 9, 8, 7},
                           {11, 6, 5, 4},
                           {12, 3, 2, 1},
                           {13, 14, 15, 16}};

char *u_key;
uint8_t getKey();
char buffer[4];

void setup()
{
        DDRA = 0x0f;
        DDRB = 0xff;
        DDRC = 0xff;
        PORTA = 0xf0; // R pull up (on)
        lcd_init(LCD_DISP_ON);
        lcd_gotoxy(0, 0);
        lcd_puts("key = ");
}

void loop()
{
        lcd_gotoxy(0, 1);
        uint8_t key = getKey();
        if (key != NULL)
                u_key = getKey();

        if (u_key != 0)
        {
                utoa(u_key, buffer, 10);
                lcd_puts(buffer);
                if (u_key < 10)
                {
                        lcd_gotoxy(1, 1);
                        lcd_puts(" ");
                }
        }
}

uint8_t getKey()
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
                                return num[i][j];
                }
                _delay_ms(1);
        }
        return NULL;
}

void nKey()
{
        PORTA = 0b11111110; // Pola baris ke 1
        if ((PINA & 0x80) == 0)
                PORTB = 0x00;
        if ((PINA & 0x40) == 0)
                PORTB = 0x09;
        if ((PINA & 0x20) == 0)
                PORTB = 0x08;
        if ((PINA & 0x10) == 0)
                PORTB = 0x07;

        PORTA = 0b11111101; // Pola baris ke 2
        if ((PINA & 0x80) == 0)
                PORTB = 0x00;
        if ((PINA & 0x40) == 0)
                PORTB = 0x06;
        if ((PINA & 0x20) == 0)
                PORTB = 0x05;
        if ((PINA & 0x10) == 0)
                PORTB = 0x04;

        PORTA = 0b11111011; // Pola baris ke 3
        if ((PINA & 0x80) == 0)
                PORTB = 0x00;
        if ((PINA & 0x40) == 0)
                PORTB = 0x03;
        if ((PINA & 0x20) == 0)
                PORTB = 0x02;
        if ((PINA & 0x10) == 0)
                PORTB = 0x01;

        PORTA = 0b11110111; // Pola Baris ke 4
        if ((PINA & 0x80) == 0)
                PORTB = 0x00;
        if ((PINA & 0x40) == 0)
                PORTB = 0x00;
        if ((PINA & 0x20) == 0)
                PORTB = 0x00;
        if ((PINA & 0x10) == 0)
                PORTB = 0x0f;
}
uint32_t pows(int x, int y)
{
        int res = 1;
        for (int i = 0; i < y; i++)
        {
                res *= x;
        }
        return res;
}
