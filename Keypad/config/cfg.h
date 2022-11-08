#pragma once

#ifndef __CFG__
#define __CFG__

#define vint volatile unsigned int
#define vchar volatile unsigned char

int main(void);
void setup();
void loop();

int main(void)
{
        setup();
        while (1)
        {
                loop();
        }
        return 0;
}

#endif