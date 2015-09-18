/********************************************
* MSYS, LAB 11                              *
* Test program for UART driver.             *
*                                           *
* STK500 setup:                             *
* Header "RS232 spare" connected to RXD/TXD *
*   RXD = PORTD, bit0                       *
*   TXD = PORTD, bit1                       *
*                                           *
* Henning Hargaard 1/11 2011                *
*********************************************/
#include <avr/io.h>
#include "uart.h"

int main()
{
	char tegn;
	char TestStreng[40] = "This string is stored in SRAM memory\r\n";

	// Initialize USART
	// Important : Also other Baud Rates and Data Bits should be tested
	// Corresponding changes has to be made in the terminal program used
	// for the test
	InitUART(9600, 8);

	while (1)
	{
		// Testing SendChar
		SendChar('A');
		SendChar('B');
		SendChar('C');
		SendChar('\r');
		SendChar('\n');

		// Testing ReadChar() : Read and echo
		tegn = ReadChar();
		SendChar(tegn);
		SendChar('\r');
		SendChar('\n');

		// Testing CharReady()
		while ( !CharReady() )
	{}
		SendChar( ReadChar() );
		SendChar('\r');
		SendChar('\n');
		
		// Sending string stored in Flash (constant string)
		SendString("This string is stored as a constant in flash memory\r\n");
		
		// Sending string stored in SRAM (modify-able string)
		SendString(TestStreng);
		
		// Testing SendInteger()
		SendInteger(12345);
		SendChar('\r');
		SendChar('\n');
		SendInteger(-1000);
		SendChar('\r');
		SendChar('\n');
	}
}

