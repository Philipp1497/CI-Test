#include "rs232.h"

#define BITSET(x,y) ((x)|= (y))
#define BITCLR(x,y) ((x)&=~(y))
#define HIGH_16(x) (((x) &0xFF00)>>8)
#define LOW_16(x)  ((x) &0x00FF)


void rs232init()
{
    BITSET(P3SEL, 0xC0); //use alternate device
    BITSET(P3DIR, 0x40); // P3.6 output TX(UART)


    BITSET(U1CTL, SWRST); //switch to reset state
    BITSET(ME2, UTXE1+URXE1); //enable device, RX+TR
    BITSET(U1TCTL, SSEL0);//ACLK 8 Mhz
    BITCLR(U1CTL, SYNC);//uart mode
    BITCLR(U1CTL, PENA|SPB);// no parity 1 stop
    BITCLR(U1CTL, CHAR);//7 data bits

    U1BR0 = LOW_16(416);//baudrate 19200 = 8Mhz/416
    U1BR1 = HIGH_16(416);
    U1MCTL = 0x6D; // use 1/3 of 416 divider
    BITCLR(U1CTL, SWRST);// switch to active state
}
