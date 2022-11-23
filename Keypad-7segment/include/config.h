#include "avr/io.h"
#define F_CPU 16000000UL
#include "util/delay.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "lcd.h"

#define vint volatile unsigned int

void getKey();
void set(vint* port_x, char val);
void display(void);