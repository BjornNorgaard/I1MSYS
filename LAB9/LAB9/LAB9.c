#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRD = 0xFF;		// PD er udgange
	initLEDport(3);		// PD LED klar
	writeAllLEDs(3,0);	// LED slukket
	TCNT1  = 61936;
	// CTC & PRESCA 1024 & OC1A on comp match
	TCCR1A = 0b01000000;
	TCCR1B = 0b00001101;
	// Frekvens = 0,5 Hz
	// 0,5 = 3686400/(2*1024*(1+OCR1A))
	OCR1A = 3599;
	
	// Uendelig løkke
	unsigned char pause = 100;
	while(1){
		_delay_ms(pause);
		writeAllLEDs(3, 0b00000000);
		_delay_ms(pause);
		writeAllLEDs(3, 0b00000001);
	}
}