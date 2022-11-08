#pragma once

#ifndef __AVR_ATmega16__
#define __AVR_ATmega16__
#endif

#define F_CPU 16000000UL

#include "avr/io.h"
#include "util/delay.h"
#include <util/atomic.h>
#include <avr/interrupt.h>
#include "cfg.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define NOL 0xC0
#define SATU 0xF9
#define DUA 0xA4
#define TIGA 0xB0
#define EMPAT 0x99
#define LIMA 0x92
#define ENAM 0x82
#define TUJUH 0xF8
#define DELAPAN 0x80
#define SEMBILAN 0x90
#define MATI 0xFF

uint32_t pows(int x, int y);
char getKey();