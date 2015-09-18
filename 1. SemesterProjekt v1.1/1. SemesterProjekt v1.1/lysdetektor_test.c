/*
 * lysdetektor_test.c
 *
 * Created: 18-06-2014 12:33:13
 *  Author: Bjørn Nørgaard
 
 En lille ændring er lavet i detektor funktionen for
 at den skal virke til test på STK'en.
 
 Hver gang der trykkes på en switch som er forbundet
 til PIND skal refleksbriklyden afspilles.
 
 */ 

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include "test.h"
#include "lysdetektor.h"

void lysdetektor_test(){
	if(detektor()){
		refleksbriklyd();
	}
}