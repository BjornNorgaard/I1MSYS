#include "Led.h"
#include "UART_int.h"
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(USART_RXC_vect);

int main(){
	// Init USART (med interrupt)
	InitUART(9600,8,1);
	
	// Global interrupt enable
	sei();
	
	// Init led
	initLEDport(0);
	
	while(1){
		// Her vil vi så lave noget "fornuftigt"
	}
}

ISR(USART_RXC_vect){
	char modtaget_tegn;
	// Aflæs UART modtage-register
	modtaget_tegn = UDR;
	// Reager kun på lovlige tegn
	if ((modtaget_tegn >= '0') && (modtaget_tegn <= '7')){
		// Toggle aktuelle lysdiode
		toggleLED(modtaget_tegn - '0');
		// Send streng "LED nummer x er toggled"
		SendString("LED nummer ");
		SendChar(modtaget_tegn);
		SendString(" er toggled\r\n");
	}
}