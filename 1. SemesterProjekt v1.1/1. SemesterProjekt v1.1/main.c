/*
* 1. semesterprojekt.c
*
* Created: 16-06-2014 16:28:24
*  Author: Bjørn Nørgaard
*/

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include "lysdetektor.h"
#include "motor.h"
#include "test.h"
#include "lys.h"
#include "lyd.h"

int main(void){
	DDRA = 0x00;
	forlys(0);
	baglys(0);
	
	while(1){
		
		PORTB = 0;
		PORTB &= ~(1<<2);
		
	while (PINA == 0b11111111){};
	
	int reCounter = 0;
	int acceleration = 2;
	int detektDelay = 500;
	int mod = 10;
	int maxPWM = 90+mod;
	int midPWM = 50+mod;
	int minPWM = 20+mod;
	
	// Slukker for -og baglys
	forlys(0);
	baglys(0);
	
	// Vi begynder...
	startlyd();

	// Gør klar til kørsel fremad...
	setRetning(0);
	forlys(1);
	baglys(1);

	// Sætter afsted...
	for(int i = 0; i<=maxPWM; i++){
		setPWM(i);
		_delay_ms(acceleration);
	}
	// Venter på sjette refleks
	while(reCounter != 7){
		if(detektor()){
			reCounter++;
			refleksbriklyd();
			
			if(reCounter==6){
				setPWM(midPWM);
			}
			else{
				setPWM(maxPWM);
			}
			
			_delay_ms(detektDelay);
		}
	}
	reCounter = 0;
	
	// Gør klar til standsning...
	baglys(2);

	// Standser...
	brems(maxPWM);

	// Bilen holder stille...
	baglys(0);
	forlys(0);

	// Gør klar til at køre baglæns...
	setRetning(1);
	baglys(1);
	forlys(1);

	// Sætter afsted bagud...
	for(int i = 0; i<=maxPWM; i++){
		setPWM(maxPWM);
		_delay_ms(acceleration);
	}
	// Venter på ottende refleks
	while(reCounter != 2){
		if(detektor()){
			reCounter++;
			refleksbriklyd();
			_delay_ms(detektDelay);
		}
	}
	reCounter=0;

	// Gør klar til standsning...
	baglys(2);

	// Standser...
	brems(maxPWM);

	// Bilen holder stille...
	baglys(0);
	forlys(0);

	// Gør klar til kørsel fremad...
	setRetning(0);
	forlys(1);
	baglys(1);

	// Sætter afsted...
	for(int i = 0; i<=maxPWM; i++){
		setPWM(i);
		_delay_ms(acceleration);
	}
	// Venter på elfte refleks
	while(reCounter != 3){
		if(detektor()){
			reCounter++;
			refleksbriklyd();
			
			if(reCounter==2){
				setPWM(midPWM);
			}
			else if(reCounter==3){
				setPWM(midPWM);
			}
			else{
				setPWM(maxPWM);
			}
			
			_delay_ms(detektDelay);
		}
	}

	// Gør klar til standsning...
	baglys(2);

	// Standser...
	brems(maxPWM);

	// Bilen holder stille...
	baglys(0);
	forlys(0);
	
	// Vi slutter
	slutlyd();
}
}
