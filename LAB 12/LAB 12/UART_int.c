#include "UART.h"
#include <stdlib.h>
#include <avr/io.h>

#define XTAL 3686400

void InitUART(unsigned long BaudRate, unsigned char DataBit, unsigned char RX_int){
	unsigned int TempUBRR;

	if ((BaudRate >= 110) && (BaudRate <= 115200) && (DataBit >=5) && (DataBit <= 8)){
		// bit 5   = 1 = "data buffer empty"
		UCSRA = 0b00100000;
		
		// bit 7   = 1 = skal være sat
		// bit 5&4 = 0 = ingen paritet
		// bit 6   = 0 = asynchronous operation
		// bit 3   = 0 = stop bit select = 1bit
		UCSRC = 0b10000000;
		
		// bit 3&4   = 1 = RXEN & TXEN enabled
		// bit 7&6&5 = 0 = all interrups disabled
		UCSRB = 0b00011000;
		
		// bit 7 = 1 = RXCIE Interrupt enabled
		USCRB |= 0b10000000;
		
		TempUBRR = XTAL/(16*BaudRate)-1;
		UBRRH = TempUBRR >> 8;
		UBRRL = TempUBRR;
	}
}
unsigned char CharReady(){
	// RXC - USART Receive complete
	return UCSRA & (1<<7);
}
char ReadChar(){
	// Venter på at der er modtaget et tegn
while((UCSRA & (1<<7))==0){};
// Sender indholdet af UDR tilbage
return UDR;
}
void SendChar(char Tegn){
	// Venter igen
	while((UCSRA & (1<<7)) == 0){};
	// Returnere tegnet som skal sendes
	UDR = Tegn;
}
void SendString(char* Streng){
	while(*Streng != 0){
		// Sender char som der peges på
		SendChar(*Streng);
		// Sender pointeren videre
		Streng++;
	}
}
void SendInteger(int Tal){
	char array[7];
	// Konvertere int til ASCII string, radix 10
	itoa(Tal, array, 10);
	// Sender stringen
	SendString(array);
}