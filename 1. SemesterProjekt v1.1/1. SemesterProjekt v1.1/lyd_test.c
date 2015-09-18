/*
 * lyd_test.c
 *
 * Created: 18-06-2014 12:32:51
 *  Author: Bjørn Nørgaard
 
 Denne funktion skal blot tjekke at når en given
 lyd funktion kaldes skal den givne melodi
 afspilles.
 
 -Først kaldes startlyd() og afspilles én gang.
 -Så kaldes refleksbriklyd() og afspilles 5 gange
 med 500ms mellemrum.
 -Dernæst kaldes slutlyd() og afspilles én gang.
 
 */ 

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include "test.h"
#include "lyd.h"

void lyd_test(){
	startlyd();
	_delay_ms(1000);
	
	for(int i = 0; i<5; i++){
		refleksbriklyd();
		_delay_ms(500);
	}
	_delay_ms(1000);
	
	slutlyd();
	_delay_ms(1000);
}