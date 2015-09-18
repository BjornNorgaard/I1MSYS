/*
* frem.c
*
* Created: 16-06-2014 16:28:24
*  Author: Bjørn Nørgaard
*/

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include "motor.h"

void setPWM( int PWM ){
	// Klargøre LED'er
	initLEDport(3);
	
	TCCR1A = 0b11000011;	// Mode 3, 10bit
	TCCR1B = 0b00000001;	// ingen prescaler
	
	PWM = 0+ PWM;		// nu kan PWM sætte = 90 og derved få 90% HØJ dutycycle
	double startTrin = (( - ( (double)PWM / 100 ) + 1 ) * 1023 );	// OCRn beregnes ( se maple dokument: 'Motor - Beregning af OCRn til PWM signal'
	int startTrinSomInteger = startTrin;	// startTrin variablen er en double og dette kan ikke indsættes i et register, så den laves om til en integer
	OCR1A = startTrinSomInteger;			// OCRn den beregnede værdi indsættes i OCR1A
	
	//return PWM;				// sender vores PWM tilbage som heltal mellem 0 og 100
}

void setRetning( int retning ){
	DDRB |= (1<<2);			// PORTB sat som output
	
	if(retning){
		PORTB |= (1<<2);	// '1' skrives til PB2 = bilen kører fremad
	}
	else{
		PORTB &= ~(1<<2);	// '0' skrives til PB2 = bilen kører baglæns
	}
}

void brems( int PWM){
	int i;
	/* bremser ned fra aktuelle PWM til 0 */
	for(i = PWM; i>=0; i--){
		setPWM(i);
		_delay_ms(2);		
		/* 5ms delay mellem hver decrementering = 100*2=500,
		altså 200ms om at bremse fra PWM=100 */
	}
	_delay_ms(1000);
}	