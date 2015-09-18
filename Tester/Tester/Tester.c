/*
* 1. semesterprojekt.c
*
* Created: 16-06-2014 16:28:24
*  Author: Bjørn Nørgaard
*/

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	while(1){
		DDRD |= (1<<7);		// PORTD ben7 sættes til udgang
		TCCR2 = 0b01101001;
		OCR2 = 100;
	}
}