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

void pause();

void main_test(){
	int reCounter = 0;
	int acceleration = 10;
	
	// Vi begynder...
	startlyd();
	pause();
	// Gør klar til kørsel fremad...
	setRetning(1);
	forlys(1);
	baglys(1);
	pause();
	// Sætter afsted...
	for(int i = 0; i<=99; i++){
		setPWM(i);
		_delay_ms(acceleration);
	}
	// Venter på sjette refleks
	while(reCounter != 6){
		if(detektor()){
			reCounter++;
			refleksbriklyd();
			_delay_ms(500);
		}
	}
	// Gør klar til standsning...
	baglys(2);
	pause();
	// Standser...
	brems(99);
	pause();
	// Bilen holder stille...
	baglys(0);
	forlys(0);
	pause();
	// Gør klar til at køre baglæns...
	setRetning(0);
	baglys(1);
	forlys(1);
	pause();
	// Sætter afsted bagud...
	for(int i = 0; i<=99; i++){
		setPWM(i);
		_delay_ms(acceleration);
	}
	// Venter på ottende refleks
	while(reCounter != 8){
		if(detektor()){
			reCounter++;
			refleksbriklyd();
			_delay_ms(500);
		}
	}
	pause();
	// Gør klar til standsning...
	baglys(2);
	pause();
	// Standser...
	brems(99);
	pause();
	// Bilen holder stille...
	baglys(0);
	forlys(0);
	pause();
	// Gør klar til kørsel fremad...
	setRetning(1);
	forlys(1);
	baglys(1);
	pause();
	// Sætter afsted...
	for(int i = 0; i<=99; i++){
		setPWM(i);
		_delay_ms(acceleration);
	}
	// Venter på elfte refleks
	while(reCounter != 11){
		if(detektor()){
			reCounter++;
			refleksbriklyd();
			_delay_ms(500);
		}
	}
	pause();
	// Gør klar til standsning...
	baglys(2);
	pause();
	// Standser...
	brems(99);
	pause();
	// Bilen holder stille...
	baglys(0);
	forlys(0);
	pause();
	// Vi slutter
	slutlyd();
}

void pause(){
	_delay_ms(2000);
}