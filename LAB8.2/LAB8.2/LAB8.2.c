/*************************************
* MSYS, LAB8, Part 2                 *
* Timer 1 in Normal Mode (PS = 64)   *
* "Binary Clock" (seconds)           *
* PC:[7..4] = Sec.10  [3..0] = Sec.1 *
*                                    *
* STK500 Setup:                      *
* LEDs connected to PC pins.         *
*                                    *
* Henning Hargaard 6/10 2011         *
**************************************/
#include <avr/io.h>
#include "led.h"

// Prototype
void T1Delay();

int main(){
	unsigned char tiere = 0;
	unsigned char enere = 0;
	// Klargoer LED port
	initLEDport();
	
	while(1){
		// Vent 1 sekund
		T1Delay();
		// Juster enere og tiere (BCD format)
		//---> Skriv kode her, der på rette vis
		//     justerer enere og tiere.
		enere++;
		
		if(enere>9){
			tiere++;
			enere=0;
		}
		if(tiere>5){
			enere=0;
			tiere=0;
		}
		//     Derefter skal tiere og enere skrives
		//     ud til lysdioderne.
		//     [7..4] = 10'ere  [3..0] = 1'ere
		writeAllLEDs( (tiere << 4) | (enere & 0xFF) );
	}
}

void T1Delay(){
	TCNT1 = 61936; // Starttrin (beregnet)
	// "Normal" & prsc 1024
	TCCR1A = 0b00000000;
	TCCR1B = 0b00000101;
	while((TIFR & (1<<TOV1))==0);
	// Timer stoppes, sat til "Normal".
	TCCR1A = 0;
	TCCR1B = 0;
	TIFR = (1<<TOV1); // Resetter timer1
}