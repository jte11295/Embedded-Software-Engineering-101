#include <msp430.h>				


/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P4DIR |= 0x80;					// configure P1.0 as output
	P1DIR |= 0x01;
	P1OUT |= 0x01;

	volatile unsigned int i;		// volatile to prevent optimization

	while((P1IN && 0x02) != 0x00)
	{
		P1OUT ^= 0x01;
	    P4OUT ^= 0x80;				// toggle P1.0
		for(i=100000; i>0; i--);     // delay
	}
}
