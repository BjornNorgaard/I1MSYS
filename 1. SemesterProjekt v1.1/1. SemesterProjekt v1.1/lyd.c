/*
* lyd.c
*
* Created: 17-06-2014 00:21:12
*  Author: Bjørn Nørgaard
*/

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include "lyd.h"

void startlyd( void ){
	DDRD |= (1<<7);		// PORTD ben7 sættes til udgang
	TCCR2 = 0b01101101;		// Fast PWM, Clear on Compare match, Set at TOP, 128 prescaler
	
	// Her begynder noget der skulle minde om en melodi...
	OCR2 = 250;				// 250 = random værdi
	_delay_ms(300);
	OCR2 = 200;
	_delay_ms(300);
	OCR2 = 150;
	_delay_ms(300);
	OCR2 = 100;
	_delay_ms(300);
	OCR2 = 50;
	_delay_ms(300);
	// Her slutter det der skulle minde om en melodi
	
	TCCR2 = 0;			// timer2 stoppes
}

void refleksbriklyd( void ){
	DDRD |= (1<<7);		// PORTD ben7 sættes til udgang
	TCCR2 = 0b01101101;		// Fast PWM, Clear on Compare match, Set at TOP, 128 prescaler
	
	OCR2 = 250;				// 250 = random værdi
	_delay_ms(50);
	TCCR2 = 0;				// timer2 stoppes
}

void slutlyd( void ){
	startlyd();				// indtil vi finder på noget bedre så er slut og startlyden ens
}