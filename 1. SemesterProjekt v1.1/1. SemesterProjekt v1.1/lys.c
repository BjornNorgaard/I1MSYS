/*
* lys.c
*
* Created: 17-06-2014 00:18:13
*  Author: Bjørn Nørgaard
*/

#define F_CPU 3686400
#include <avr/io.h>
#include "lys.h"

void forlys( int on ){
	DDRB |= (1<<7);
	if(on){
		PORTB |= (1<<7);	// PB7 går høj
	}
	else{
		PORTB &= ~(1<<7);	// PB7 går lav
	}
}

void baglys( int state ){
	DDRB |= (1<<3);
	TCCR0 = 0b01101001;		// Fast PWM, Clear on Compare match, Set at TOP, ingen prescaler
	
	if(state == 1){
		OCR0 = 242;			// 5% dutycycle, se maple dokument: Lys - Beregning af OCRn til PWM signal
		
		//TCCR0 = 0;		// bruges til at stoppe timer0, men da den ikke 
							// ...skal stoppes før banen er kørt, har jeg den ikke med
	}
	else if(state == 2){
		OCR0 = 12;			// 95% dutycycle
	}
	else{
		OCR0 = 255;			// 0% dutycycle, muligvis 255 i stedet for 0 til slukket
	}
}