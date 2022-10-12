#ifndef __AVR_ATmega8535__
#define __AVR_ATmega8535__
#endif

#include "avr/io.h"
#define F_CPU 16000000UL
#include "util/delay.h"
// #include "utils/millis.h"

int main();
void setup();
void loop();
void writeDisplay(uint8_t disp4, uint8_t disp3, uint8_t disp2, uint8_t disp1, double delay);
void counter();
void reset();

uint8_t num[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
uint8_t i, a;

int numbers[4] = {0, 0, 0, 0};

int main(void)
{
        setup();
        for (;;)
        {
                loop();
        }
}

void setup()
{
        DDRB |= (7 << PB0);
}

void loop()
{
        counter(numbers);
        if (numbers[0] > 9)
                reset(numbers);

        writeDisplay(numbers[3], numbers[2], numbers[1], numbers[0], 100);
}

void writeDisplay(uint8_t disp4, uint8_t disp3, uint8_t disp2, uint8_t disp1, double delay)
{
        uint8_t bufferDisplay[] = {num[disp4], num[disp3], num[disp2], num[disp1]};
        for (a = 0; a <= 3; a++)
        {
                uint8_t data = bufferDisplay[a];
                for (i = 0x80; i > 0; i >>= 1)
                {
                        if (data & i)
                                PORTB |= (1 << PB0);
                        else
                                PORTB &= ~(1 << PB0);
                        PORTB |= (1 << PB1);
                        PORTB &= ~(1 << PB1);
                }
        }
        PORTB |= (1 << PB2);
        PORTB &= ~(1 << PB2);

        _delay_ms(delay);
}

void counter(int nums[])
{
        nums[3]++;
        if (nums[3] > 9)
        {
                nums[2]++;
                nums[3] = 0;
        }

        if (nums[2] > 9)
        {
                nums[1]++;
                nums[2] = 0;
        }

        if (nums[1] > 9)
        {
                nums[0]++;
                nums[1] = 0;
        }
}

void reset(int nums[])
{
        nums[3] = 0;
        nums[2] = 0;
        nums[1] = 0;
        nums[0] = 0;
}