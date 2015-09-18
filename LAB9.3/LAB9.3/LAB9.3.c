#include <avr/io.h>

int main(){
	DDRD = 0xFF;
	
	// CTC & PRESCA 64 & OC1A on comp match
	TCCR1A = 0b01000000;
	TCCR1B = 0b00001011;
	
	//frkv = 3686400 / (2*64*(1+OCR1A)
	OCR1A  = 50;
	
	while(1){
		if(switchStatus(0)==(1<<0)){
			OCR1A = 27;
		}
		else if(switchStatus(0)==(1<<1)){
			OCR1A = 32;
		}
		else if(switchStatus(0)==(1<<2)){
			OCR1A = 47;
		}
		else if(switchStatus(0)==(1<<3)){
			OCR1A = 63;
		}
		else if(switchStatus(0)==(1<<4)){
			OCR1A = 95;
		}
		else if(switchStatus(0)==(1<<5)){
			OCR1A = 191;
		}
		else if(switchStatus(0)==(1<<6)){
			OCR1A = 575;
		}
	}
}