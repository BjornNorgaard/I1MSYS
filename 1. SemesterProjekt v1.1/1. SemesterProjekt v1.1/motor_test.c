/*
* motor_test.c
*
* Created: 18-06-2014 12:32:31
*  Author: Bjørn Nørgaard

Denne test tjekker at motor funktionerne gør som de skal
ved at teste dem hver for sig på følgende måde:

setRetning( int )
	1. setRetning indstilles til baglæns kørsel ved at
		sætte setRetning(0) - det forventes at LED'en lyser
		da STK LED'erne tænder på HØJT signal.
	1.1 setRetning indstilles til fremadgående kørsel ved at
		sætte setRetning(1) - det forventes ikke at LED'en vil
		lyse, da STK LED'erne tænder ved et LAVT signal.
		
setPWM( int ) 
	2. setPWM bruges til at få en LED til at lyse, først med
		PWM = 5% og efter 2sek sættes PWM = 95%

brems( int ) 
	3. brems bruges efter sidste punkt hvor PWM er sat = 95%
		og da skulle vi gerne se at LED'en langsomt slukker.
*/

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include "test.h"
#include "motor.h"

void motor_test(){
	// Klargøre LED'er
	initLEDport(3);
	initLEDport(1);
	
	// Slukker LED'er
	PORTD = 0xFF;
	PORTB = 0xFF;
	
	//int PWM = 100;		// motor slukket ved PWM = 100
	
	// setRetning
	setRetning(0);		// LED0 tændt
	_delay_ms(1000);
	setRetning(1);		// LED0 slukket
	_delay_ms(1000);
	
	// setPWM
	setPWM(5);
	_delay_ms(2000);
	setPWM(95);
	_delay_ms(1000);
	
	// brems
	brems(95);
	_delay_ms(1000);
	
}