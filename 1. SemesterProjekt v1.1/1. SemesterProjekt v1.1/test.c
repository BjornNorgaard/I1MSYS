/*
* main_test.c
*
* Created: 18-06-2014 20:41:45
*  Author: Bjørn Nørgaard
*/

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include "test.h"

void test(){
	while(1){
		motor_test();
		_delay_ms(1000);
		
		lyd_test();
		_delay_ms(1000);
		
		lys_test();
		_delay_ms(1000);
		
		while(1){
			lysdetektor_test();
		}
	}
}