#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>

int main(){
	unsigned char Switch = 0;
	unsigned char Led = 3;
	initSwitchPort(Switch);
	initLEDport(Led);
	
	// Mode 3, No PRESCA, COMP w/ UP-count
	TCCR1A = 0b11000011;
	TCCR1B = 0b00000001;
	
	// 0.5 = 1-(OCRn/1023) = 511,5
	OCR1A = 511;
	
	while(1){
		
		if(switchOn(Switch,0)){
			// 0.05 = 1-(OCRn/1023) = 972
			OCR1A = 972;
		}
		else if(switchOn(Switch,1)){
			// 0.5 = 1-(OCRn/1023) = 511
			OCR1A = 511;
		}
		else if(switchOn(Switch,2)){
			// 0.95 = 1-(OCRn/1023) = 51
			OCR1A = 51;
		}
		
		// For sjov
		//_delay_ms(300);
		//writeAllLEDs(Led,0);
		//_delay_ms(300);
		//writeAllLEDs(Led,0xFF);
	}
}