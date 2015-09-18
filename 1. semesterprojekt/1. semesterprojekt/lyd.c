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
	TCCR2 = 0b01011001;	// Toggle on COMP match, Fast PWM, no Prescaler
	_delay_ms(2000);
	TCCR2 = 0;
}

void refleksbriklyd( void ){
	
}

void slutlyd( void ){
	
}