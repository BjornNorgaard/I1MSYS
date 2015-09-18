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
#include "lys.h"
#include "lyd.h"

int main(void)
{
	while(1)
	{
		startlyd();
	}
}