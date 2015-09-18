#include <avr/io.h>
#include "Timer.h"

void timer( int whichTimer, float ms_duration)
{
	if(whichTimer==0)
	{
		float etTrinOp = ( 1024 / 3686400 );
		float trinTilOverflow = ( ms_duration / etTrinOp );
		
		// Starttrin vælges (0 - 255)
		TCNT0 = 255 - trinTilOverflow;
		// Timer0 klargøres med 1024 prescaler
		TCCR0 = 0b00000101;
		// Venter på overflow
		while( (TIFR & 0b00000001) == 0 );
		// Stopper timer
		TCCR0 = 0;
		// Resetter timer0's overflow
		TIFR = 1 << TOV1;
	}
	if(whichTimer==1)
	{
		
	}
	if(whichTimer==2)
	{
		
	}
}