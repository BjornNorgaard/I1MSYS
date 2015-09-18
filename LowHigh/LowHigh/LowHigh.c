#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include "Led.h"
#include "Switch.h"

void wait();

int main(void) {
	
	unsigned char led = 2;
	unsigned char swi = 0;
	unsigned char user_input = 0;
	
	initLEDport(led);
	initSwitchPort(swi);
	
	writeAllLEDs(led,0);
	
	while(1) {
		user_input = switchStatus(swi);
		
		switch(user_input) {
			case 0b00000001:
			toggleLED(led, 0);
			wait();
			break;
			case 0b00000010:
			toggleLED(led, 1);
			break;
			case 0b00000100:
			toggleLED(led, 2);
			break;
			case 0b00001000:
			toggleLED(led, 3);
			break;
		}
	}
	
	return 0;
}

void wait() {
	_delay_ms(100);
}