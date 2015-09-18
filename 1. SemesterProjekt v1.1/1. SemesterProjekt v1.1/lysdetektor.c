/*
* lysdetektor.c
*
* Created: 17-06-2014 00:23:54
*  Author: Bjørn Nørgaard
*/

#define F_CPU 3686400
#include <avr/io.h>
#include "lysdetektor.h"

int detektor( void ){
	//DDRD = ~(1<<2);
	DDRD = 0b11110011;
	if((PIND & (1<<2)) || (PIND & (1<<3))){	// ved STK "PIND == (PIND & ~(1<<2))", på bil "PIND & (1<<2)"
		return 1;
	}
	else {
		return 0;
	}
}