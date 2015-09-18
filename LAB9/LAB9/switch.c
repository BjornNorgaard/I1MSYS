﻿/********************************************************
* "SWITCH.C":                                           *
* Implementation file for the STK500 SWITCH PORT driver.*
* The SWITCHES are connected to the PA pins.            *
* Henning Hargaard, 27/9 2011                           *
*********************************************************/
#include <avr/io.h>

#define MAX_SWITCH_NR 7

// Klargør switch-porten
void initSwitchPort()
{
	DDRA = 0x00;
}

// Læser alle switches samtidigt
unsigned char switchStatus()
{
	return ~PINA;
}

// Returnerer TRUE, hvis switchen med nummeret
// "switch_nr" er aktiveret - ellers returneres FALSE
unsigned char switchOn(unsigned char switch_nr)
{
	if(switch_nr <= MAX_SWITCH_NR)
	{
		unsigned char mask = ~(PINA | ~(1<<switch_nr));
		return mask;
	}
}
 