/*********************************************
* MSYS, LAB7, Part 2                         *
* Testprogram for STK500 SWITCH PORT driver  *
*                                            *
* STK500 Setup:                              *
* LEDs connected to PC pins.                 *
* SWITCHES connected to PA pins.             *
*                                            *
* Henning Hargaard 27/9 2011                 *
**********************************************/
#define F_CPU 3686400UL
#include <util/delay.h>
#include <avr/io.h>
#include "switch.h"
#include "led.h"

int main()
{
	unsigned char i;

	// Klargøring af SWITCH-porten
	initSwitchPort();
	// Klargøring af LED-porten
	initLEDport();
	
	// Test af switchStatus():
	// Resultatet skrives til hele lysdiodeporten
	// Testen afsluttes, når man samtidigt
	// trykket på SW7 og SW0
	i = 0;
	while (i != 0b10000001)
	{
		i = switchStatus();
		writeAllLEDs(i);
	}
	
	// Tænd alle lysdioder i 2 sekunder
	// og sluk så alle lysdioder
	// Så kan vi se, at næste test starter
	writeAllLEDs(0xFF);
	_delay_ms(2000);
	writeAllLEDs(0);
	_delay_ms(1000);
	
	// Test af switchOn():
	// Læs efter tur hver enkelt switch
	// og tænd tilsvarende lysdiode, hvis der trykkes på tasten
	// - ellers slukkes lysdiden
	while (1)
	{
		for (i=0; i<=7; i++)
		{
			if (switchOn(i))
			turnOnLED(i);
			else
			turnOffLED(i);
		}
	}
	return 0;
}
