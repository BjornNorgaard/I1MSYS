/*
* LAB10.c
*
* Created: 08-11-2014 15:47:36
*  Author: Bjørn Nørgaard
*/

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Switch.h"
#include "Led.h"

unsigned char ledDriver = 2;	// LED = portC
unsigned char switchDriver = 3;	// Switch = portD

void initInterrupts();			// enabler interrupts

int main(){

	initSwitchPort(switchDriver);		// kalder driverfunktion
	initLEDport(ledDriver);				// meme
	initInterrupts();					// enabler interrupts
	
	while(1){
		toggleLED(ledDriver,7);
		_delay_ms(1000);
	}
}

void initInterrupts(){
	// allow interrupts
	sei();					
				
	// enable INT 1 and 0
	GICR = ( (1<<INT1) | (1<<INT0) );
	
	// enable falling edge for INT0
	MCUCR = (1<<ISC01);
	
	// enable rising edge for INT1
	MCUCR |= ( (1<<ISC11) | (1<<ISC10) );
	

}

ISR(INT0_vect){
	toggleLED(ledDriver, 0);
}

ISR(INT1_vect){
	toggleLED(ledDriver, 1);
}