#include "bocas.h"
#include "ringbuffer.h"

#include "stdbool.h"

#define BITSET(x,y) ((x)|= (y))
#define BITCLR(x,y) ((x)&=~(y))
#define HIGH_16(x) (((x) &0xFF00)>>8)
#define LOW_16(x)  ((x) &0x00FF)

#define FAIL 0
#define SUCCESS 1

#define INT_ENABLE asm ("\tEINT")


char data[7];
unsigned int read = 0 ;
unsigned int write = 0;     //Datenbuffer mit read und write index

char trash; // zeichen die nicht verwertet werden

#pragma INTERRUPT (isr_rs232_receive);
#pragma vector = 3;

void isr_rs232_receive()// isr
{
       if(write < 8)
       {
           data[write] = U1RXBUF; // solange write index < 8 kopieren aus Empfangsbuffer in Datenbuffer
       }
       if(write > 7)
       {
           trash = U1RXBUF; // falls write > 7 zeichen nicht verwerten
       }
       write++;

}
void warteschleife(int i); // verzögerungsfunktion aus versuch 4



void main (void)
{
    P4SEL = 0x00;
    P4DIR = 0x8F; // Porthardware init

    rs232init();
    BITCLR(IFG2, URXIFG1);
    BITSET(IE2, URXIE1);


    BITCLR(IFG2, UTXIFG1);
    BITCLR(IFG2, URXIFG1);
    INT_ENABLE;


    while(1)
    {

        if(data[read] != 0) // falls buffer nicht leer mach was, sonst busy wait
        {


            warteschleife(1000);
            if(write > 7)
            {
                write = 8;
                P4OUT = 0x80 + write; // falls write > 7 wort mit mehr als 8 zeichen also linke led an
            }

            if(read < write)
            {
                U1TXBUF = data[read]; // solange read < write in sendebuffer kopieren
            }

            read++;



            if(read >= write) // falls read index write index einholt dann reset uns led aus
            {
                read = 0;
                write = 0;
                data[read] = 0;
                P4OUT = 0;
            }
            if(write <= 7)
            {
                P4OUT = write;
            }
            P4OUT = P4OUT - read; //led nacheinander aus machen falls ein zeichen gelesen wurde


        }
    }



}
