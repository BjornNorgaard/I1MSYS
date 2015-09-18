/*
 * lys_test.c
 *
 * Created: 18-06-2014 12:32:59
 *  Author: Bjørn Nørgaard
 
 Dette testprogram skal tænde forlyset, og så gennemløbe de 3
 muligheder for baglyset: slukket, svagt, kraftigt, svagt og slukket,
 derefter slukker forlyset og testen er færdig.
 
 */ 

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include "test.h"
#include "lys.h"

void lys_test(){
	forlys(0);
	_delay_ms(1000);
	
	baglys(0);
	_delay_ms(1000);
	baglys(1);
	_delay_ms(1000);
	baglys(2);
	_delay_ms(1000);
	baglys(1);
	_delay_ms(1000);
	baglys(0);
	_delay_ms(1000);
	
	forlys(1);
	_delay_ms(1000);
}