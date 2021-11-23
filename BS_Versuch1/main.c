#include <msp430.h> 

void init(void);
int blink(int l);
void getAdress(void);
short umschalten(short i);
extern int count;

extern short array[24]= {11,10,9,8,7,6,5,4,3,2,1,0,8,8,blink}; // blink an richtige stelle von neuem Stack schreiben
// übergabe von 2 in R12 aus argument für blink
short* zeiger;
short SP[2];
int zaehler;


void getAdress()
{
    zeiger = array; // zeiger auf neuen Stack (erster Stackpointer)
}


short umschalten(short i)
{
    if(zaehler == 0)
    {
        SP[0] = i;
        SP[1] = zeiger + 1 ; // ohne plus 1 wird auf verbotenen adressen geschrieben
        zaehler++;
        return SP[1];
    }
    if(zaehler == 1)
    {
        SP[1]= SP[0];
        SP[0] = i; //alten stackpointer speichern
    }
    return SP[1] ;//neuen stackpointer speichern
}

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	


    init();
    _enable_interrupts();
    getAdress();
    blink(4);
	return 0;
}

void init(void)
{
	// Port 4 als Ausgänge initialisieren
	P4OUT = 0x00;
	P4SEL = 0x00;
	P4DIR = 0xFF;

	// Hilfszaehler fuer die ISR vor initialisieren
	count = 20;
	// Timer auf kontinuierlichen Modus initialisieren
	// Taktquelle Aclk (8MHz) Vorteiler 8
	TACTL &= ~(MC_0);
	TACTL |= TASSEL_1;
	TACTL |= ID_3;
	TACCR0 = 50000u; // an diese Stelle 1000 schreiben um 50Hz frequenz zu erreichen
	TACCTL0 &= ~(CAP);
	TACCTL0 |= CCIE;
	TACTL |= MC_2;
}

int blink(int ledNum)
{
    _enable_interrupts();
	long i;
	if(ledNum < 0 || ledNum > 6)
	{
		return -1;
	}
	while (1)
	{
		// Warteschleife
		i=1100000 + ledNum * 30000;
		while (i>0)
			i--;

		// GPIO umschalten
		P4OUT ^= (1<<ledNum);
	}

}
