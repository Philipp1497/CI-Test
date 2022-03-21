/*********************************************************************************
* Headerfile for BOCAS-System in MR-Lab
*
*********************************************************************************/

#ifndef BOCAS_H
#define BOCAS_H

#include <msp430f1611.h>

//*******  Definitions for display usage*********************************
// Initialization of IO-ports and display
void initDisplay(void);
// Output of a single ascii character - only standard ascii character allowed
int putChar(						// returns 0 success or -1 error
	unsigned char x,				// column 0..15
	unsigned char y,				// row 0..7
	const char character
);
// Output of a byte in hex-code - without tag 0x
int putHex(							// returns 0 success or -1 error
	unsigned char x,				// column 0..15
	unsigned char y,				// row 0..7
	const unsigned char value
);
// Output of a string - only standard ascii character allowed
int putString(						// returns 0 success or -1 error
	unsigned char x,				// column 0..15
	unsigned char y,				// row 0..7
	const char* mystring
);


//*******  Definitions for AD-converter ADC12 ***********************************
//Modus: Single Conversion; no interrupt; Vref=2.5V

#define ADC_CHAN_NTC1K5 5			// channel for NTC sensor at port P6.5

// Initialization of ADC12
void adcInit( void );
// Read single value - 12 Bit
int adcRead( 						// returns 0 success or -1 error
	unsigned char channel, 			// input channel 0..15
	unsigned short *result 			// result of conversion
);

#endif // BOCAS_H
