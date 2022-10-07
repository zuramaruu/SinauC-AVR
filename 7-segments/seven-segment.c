#include "config.h"

vint dig[] = {PB0, PB1, PB2, PB3};

char alldata[sum][4] =  {{NOL, MATI, MATI, MATI},
                        {SATU, NOL, MATI, MATI},
                        {DUA, SATU, NOL, MATI},
                        {TIGA, DUA, SATU, NOL}};

int i, j, a;

void setup() {
	pinModeC = Output;
        pinModeB = Output;
}

void loop() {
        iterate(alldata);
}

void iterate(char _data[sum][4]){
        for (a = 0; a < sum; a++) {
                for (i = 0; i <= 270; i++){
                        for (j = 0; j < 4; j++){
                                set(&dig[j], _data[a][j]);
                        }       
                }
        }
}

void set(vint *port_x, char val) {
        digit |= (1 << *port_x);
        data = val;
        _delay_ms(1);
        digit &= ~(1 << *port_x);
}
