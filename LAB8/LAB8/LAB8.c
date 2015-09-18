/*************************************
* MSYS, LAB8, Part 1                 *
* Timer 0 in Normal Mode             *
* Led port increments 20 times/sec.  *
*                                    *
* STK500 Setup:                      *
* LEDs connected to PC pins.         *
*                                    *
* Henning Hargaard 6/10 2011         *
**************************************/
#include <avr/io.h>
#include "led.h"

// Prototype
void T0Delay(); 

int main()
{
	unsigned char x = 0;
	// Klargoer LED port
	initLEDport();
	while(1)
	{
		// Vent 1/20 sekund
		T0Delay();
		// Inkrementer og vis variablen x
		x++;
		writeAllLEDs(x);
	}
}

void T0Delay(){
	// Vælget starttrin
	TCNT0 = 74; 
	// "Normal Mode" og Prescaler på 1024
	TCCR0 = 0b00000101;
	// Venter på overflow
	while ((TIFR & 0b00000001) == 0);
	// Stopper timeren 
	TCCR0 = 0;
	// Resetter overflow flaget
	TIFR = (1<<TOV0);
}