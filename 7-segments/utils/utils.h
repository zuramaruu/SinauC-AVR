#pragma once

#ifndef __UTILS__
#define __UTILS__

#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5
#define A6 6
#define A7 7

#define B0 8
#define B1 9
#define B2 10
#define B3 11
#define B4 12
#define B5 13
#define B6 14
#define B7 15

#define C0 16
#define C1 17
#define C2 18
#define C3 19
#define C4 20
#define C5 21
#define C6 22
#define C7 23

#define D0 24
#define D1 25
#define D2 26
#define D3 27
#define D4 28
#define D5 29
#define D6 30
#define D7 31

#define OUTPUT 1
#define INPUT  0

#define PA 32
#define PB 33
#define PC 34
#define PD 35

#define pinMode(pin, mode) if (mode) { switch (pin) { case A0: DDRA |= (1 << PA0); break; case A1: DDRA |= (1 << PA1); break; case A2: DDRA |= (1 << PA2); break; case A3: DDRA |= (1 << PA3); break; case A4: DDRA |= (1 << PA4); break; case A5: DDRA |= (1 << PA5); break; case A6: DDRA |= (1 << PA6); break; case A7: DDRA |= (1 << PA7); break; case B0: DDRB |= (1 << PB0); break; case B1: DDRB |= (1 << PB1); break; case B2: DDRB |= (1 << PB2); break; case B3: DDRB |= (1 << PB3); break; case B4: DDRB |= (1 << PB4); break; case B5: DDRB |= (1 << PB5); break; case B6: DDRB |= (1 << PB6); break; case B7: DDRB |= (1 << PB7); break; case C0: DDRC |= (1 << PC0); break; case C1: DDRC |= (1 << PC1); break; case C2: DDRC |= (1 << PC2); break; case C3: DDRC |= (1 << PC3); break; case C4: DDRC |= (1 << PC4); break; case C5: DDRC |= (1 << PC5); break; case C6: DDRC |= (1 << PC6); break; case C7: DDRC |= (1 << PC7); break; case D0: DDRD |= (1 << PC0); break; case D1: DDRD |= (1 << PD1); break; case D2: DDRD |= (1 << PD2); break; case D3: DDRD |= (1 << PD3); break; case D4: DDRD |= (1 << PD4); break; case D5: DDRD |= (1 << PD5); break; case D6: DDRD |= (1 << PD6); break; case D7: DDRD |= (1 << PD7); break; case PA: DDRA = 0xff; break; case PB: DDRB = 0xff; break; case PC: DDRC = 0xff; break; case PD: DDRD = 0xff; break; } } else { switch(pin) { case A0: DDRA &= !(1 << PA0); break; case A1: DDRA &= !(1 << PA1); break; case A2: DDRA &= !(1 << PA2); break; case A3: DDRA &= !(1 << PA3); break; case A4: DDRA &= !(1 << PA4); break; case A5: DDRA &= !(1 << PA5); break; case A6: DDRA &= !(1 << PA6); break; case A7: DDRA &= !(1 << PA7); break; case B0: DDRB &= !(1 << PB0); break; case B1: DDRB &= !(1 << PB1); break; case B2: DDRB &= !(1 << PB2); break; case B3: DDRB &= !(1 << PB3); break; case B4: DDRB &= !(1 << PB4); break; case B5: DDRB &= !(1 << PB5); break; case B6: DDRB &= !(1 << PB6); break; case B7: DDRB &= !(1 << PB7); break; case C0: DDRC &= !(1 << PC0); break; case C1: DDRC &= !(1 << PC1); break; case C2: DDRC &= !(1 << PC2); break; case C3: DDRC &= !(1 << PC3); break; case C4: DDRC &= !(1 << PC4); break; case C5: DDRC &= !(1 << PC5); break; case C6: DDRC &= !(1 << PC6); break; case C7: DDRC &= !(1 << PC7); break; case D0: DDRD &= !(1 << PC0); break; case D1: DDRD &= !(1 << PD1); break; case D2: DDRD &= !(1 << PD2); break; case D3: DDRD &= !(1 << PD3); break; case D4: DDRD &= !(1 << PD4); break; case D5: DDRD &= !(1 << PD5); break; case D6: DDRD &= !(1 << PD6); break; case D7: DDRD &= !(1 << PD7); break; case PA: DDRA = 0x00; break; case PB: DDRB = 0x00; break; case PC: DDRC = 0x00; break; case PD: DDRD = 0x00; break; } }

#endif