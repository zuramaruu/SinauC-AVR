#include "../config/config.h"
#include "../utils/utils.h"
#include "../include/lcd.h"

int tombol;
char str[4];
int indikasi = 0;
int tombol = 0x8f;
int baca;

void scan_key()
{
        // kolom pertama
        PORTA = 0b01111111;
        if (bit_is_clear(PINA, 3))
        {
                tombol = 0;
                indikasi = 1;
        }
        if (bit_is_clear(PINA, 2))
        {
                tombol = 0;
                indikasi = 1;
        }
        if (bit_is_clear(PINA, 1))
        {
                tombol = 0;
                indikasi = 1;
        }
        if (bit_is_clear(PINA, 0))
        {
                tombol = 0;
                indikasi = 1;
        }
        do
        {
                baca = PINA;
                baca = baca & 0x0f;
        } while (baca != 0x0f);

        // kolom kedua
        PORTA = 0b10111111;
        if (bit_is_clear(PINA, 3))
        {
                tombol = 0;
                indikasi = 1;
        }
        if (bit_is_clear(PINA, 2))
        {
                tombol = 3;
                indikasi = 1;
        }
        if (bit_is_clear(PINA, 1))
        {
                tombol = 6;
                indikasi = 1;
        }
        if (bit_is_clear(PINA, 0))
        {
                tombol = 9;
                indikasi = 1;
        }
        do
        {
                baca = PINA;
                baca = baca & 0x0f;
        } while (baca != 0x0f);

        // kolom ketiga
        PORTA = 0b11011111;
        if (bit_is_clear(PINA, 3))
        {
                tombol = 0;
                indikasi = 1;
        }
        if (bit_is_clear(PINA, 2))
        {
                tombol = 2;
                indikasi = 1;
        }
        if (bit_is_clear(PINA, 1))
        {
                tombol = 5;
                indikasi = 1;
        }
        if (bit_is_clear(PINA, 0))
        {
                tombol = 8;
                indikasi = 1;
        }
        do
        {
                baca = PINA;
                baca = baca & 0x0f;
        } while (baca != 0x0f);

        // kolom keempat
        PORTA = 0b11101111;
        if (bit_is_clear(PINA, 3))
        {
                tombol = 0;
                indikasi = 1;
        }
        if (bit_is_clear(PINA, 2))
        {
                tombol = 1;
                indikasi = 1;
        }
        if (bit_is_clear(PINA, 1))
        {
                tombol = 4;
                indikasi = 1;
        }
        if (bit_is_clear(PINA, 0))
        {
                tombol = 7;
                indikasi = 1;
        }
        do
        {
                baca = PINA;
                baca = baca & 0x0f;
        } while (baca != 0x0f);
}

void setup()
{
        DDRC = 0xff;
        lcd_init(LCD_DISP_ON_CURSOR);
        lcd_gotoxy(0, 0);
        lcd_puts("Program Key_LCD");

        lcd_gotoxy(0, 1);
        lcd_puts("key: ");

        DDRA = 0xf0;
        PORTA = 0x0f;
        tombol = 0;
}

void loop()
{
        indikasi = 0;
        scan_key();
        if (indikasi != 0)
        {
                utoa(tombol, str, 10);
                lcd_puts(str);
        }
}