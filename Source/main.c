#include "bocas.h"
#include "stdbool.h"

#define BITSET(x,y) ((x)|= (y))
#define BITCLR(x,y) ((x)&=~(y))
#define HIGH_16(x) (((x) &0xFF00)>>8)
#define LOW_16(x)  ((x) &0x00FF)

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))


#define FAIL 0
#define SUCCESS 1

#define INT_ENABLE asm ("\tEINT")

int count;
int zuendungs_flag;
int blinken_flag;
int blinkzyklen;
int warnblink;
//static int schalter_flag;

extern void initTimerA();

#pragma INTERRUPT (isrTimer);
#pragma vector = 6;

void isrTimer (void)
{
    TACCR0 += 50000u; //50000 takte
    count--;
    if(warnblink == 1 && blinken_flag == 0){
        if (count == 10)         //Interrupt Service Routine vom Timer
            {
                P4OUT &= ~(0x81);
            }
            if (count == 0)
            {
                P4OUT |= 0x81;
                count = 20;
            }
    }
    if(warnblink == 0){
        if (count == 10)         //Interrupt Service Routine vom Timer
        {
            P4OUT &= ~(0x81);
            blinkzyklen++;
            if(blinkzyklen == 3){
                if(P1IN == 0x01 || P1IN == 0x02 || P1IN == 0x04 || P1IN == 0x03){
                    blinkzyklen = 1;//flag zur�cksetzen
                } else {
                    TACTL &= ~(MC_2); // Timer stoppen
                    blinkzyklen = 0;//flag zur�cksetzen
                    blinken_flag = 0;
                }
            }
        }
        if (count == 0)
        {
            if(zuendungs_flag == 1){
                if(blinken_flag == 1){
                    P4OUT &= ~(0x80);
                    P4OUT |= 0x01;
                }
                if(blinken_flag == 2){
                    P4OUT &= ~(0x01);
                    P4OUT |= 0x80;
                }
                if(blinken_flag == 3){
                    P4OUT |= 0x81;
                }
                count = 20;
            }
        }
    }
}

#pragma INTERRUPT (isrTaster1);
#pragma vector = 4;
void isrTaster1(void)
{
    switch(P1IFG) {
    case 0x80:
        // Z�ndungs Case, Taster ganz links
        if(zuendungs_flag == 0){
            zuendungs_flag++;
            P4OUT |= 0x20; // Led f�r Z�ndung
        } else {
            zuendungs_flag = 0; //reset vom flag
            P4OUT = 0x00; //Leds ausmachen
        }
        break;
    case 0x40:
        // Warnblink Case
        if (warnblink == 1) {
            warnblink = 0;
            P4OUT &= ~(0x81);
            TACTL &= ~(MC_2);
        } else if(warnblink == 0 && blinken_flag == 0){
            warnblink = 1;
            count = 1;
            initTimerA();
        }
        break;
    case 0x01:
        // Rechts Blinker Case
        if(zuendungs_flag == 1){
            TACTL &= ~(MC_2);
            count = 1;
            warnblink = 0;
            blinken_flag = 1; // f�r den fall rechts blinken
            blinkzyklen = 0;
            initTimerA();
        }
        break;
    case 0x02:
        if(zuendungs_flag == 1){
            TACTL &= ~(MC_2);
            count = 1;
            warnblink = 0;
            blinken_flag = 2; // f�r den fall links blinken
            blinkzyklen = 0;
            initTimerA();
        }
        break;
    case 0x04:
        if(zuendungs_flag == 1){
            TACTL &= ~(MC_2);
            count = 1;
            warnblink = 0;
            blinken_flag = 3; // f�r den fall rechts und links blinken gleichzeitig
            blinkzyklen = 0;
            initTimerA();
        }
        break;

    }
    P1IFG = 0x00;
}



void main (void)
{
    P1SEL = 0x00;
    P1DIR = 0x00;
    P1IN  = 0xFF;
    P4SEL = 0x00;
    P4DIR = 0xFF; // Porthardware init

    P1IES = 0x00; //Bitclear auf steigende Flanke reagieren
    P1IE = 0xFF;
    P1IFG = 0x00;

    WDTCTL = WDTPW+WDTHOLD;       // Watchdog abschalten
    INT_ENABLE;


    while(1)
    {
        /*if(P1IN == 0x01 && schalter_flag == 1){
            schalter_flag = 0;
            var = 1;
            initTimerA();
        }
        if (P1IN != 0x01 && var == 1){
            TACTL &= ~(MC_2);
            P4OUT &= ~(0x81);
            var = 0;
        }*/
    }

}
