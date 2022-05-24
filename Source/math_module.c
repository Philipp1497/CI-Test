#include "math_module.h"


int add (int a, int b){
	a = a + b;
	return a;
}
int greater_zero (int a, int b){
	if( a + b >= 0){
		return 0;
	} else {
		return 1;
	}	
}

int timer_isr(int count, int blinken_flag, int warnblink, int P1IN, int blinkzyklen, int zuendungs_flag){
	int P4OUT;
	if(warnblink == 1 && blinken_flag == 0){
        if (count == 10)         //Interrupt Service Routine vom Timer
            {
                P4OUT &= ~(0x81);
				return 1;
            }
            if (count == 0)
            {
                P4OUT |= 0x81;
                count = 20;
				return 2;
            }
			return 3;
    }
    if(warnblink == 0){
        if (count == 10)         //Interrupt Service Routine vom Timer
        {
            P4OUT &= ~(0x81);
            blinkzyklen++;
            if(blinkzyklen == 3){
                if(P1IN == 0x01 || P1IN == 0x02 || P1IN == 0x04 || P1IN == 0x03){
                    blinkzyklen = 1;//flag zur�cksetzen
					return 4;
                } else {
                    blinkzyklen = 0;//flag zur�cksetzen
                    blinken_flag = 0;
					return 5;
                }
            }
			return 6;
        }
        if (count == 0)
        {
            if(zuendungs_flag == 1){
                if(blinken_flag == 1){
                    P4OUT &= ~(0x80);
                    P4OUT |= 0x01;
					return 7;
                }
                if(blinken_flag == 2){
                    P4OUT &= ~(0x01);
                    P4OUT |= 0x80;
					return 8;
                }
                if(blinken_flag == 3){
                    P4OUT |= 0x81;
					return 9;
                }
                count = 20;
				return 10;
            }
			return 11;
        }
		return 12;
    }
	return 0;
}