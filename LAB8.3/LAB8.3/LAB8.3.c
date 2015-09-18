#include <avr/io.h>
#include "Led.h"
#include "switch.h"

int main ()
{
	initLEDport();
	DDRB = 0x00;
	TCCR0 = 0b00000110;
	unsigned char x = 0;
	while(1){
		x = TCNT0;
		writeAllLEDs(x);
	}
}