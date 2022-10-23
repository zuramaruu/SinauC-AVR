#include "../config/config.h"
#include "../utils/utils.h"

void setup()
{
        pinMode(PB, OUTPUT);
}

void loop()
{
        PORTB = 0xff;
        delay(25);
        for (uint8_t i = 0; i < 14; i++)
        {
                if (i < 7)
                        PORTB <<= 1;
                else
                        PORTB >>= 1;
                delay(25);
        }
}