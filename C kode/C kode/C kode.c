#include <avr/io.h>
#define F_CPU 3686400 //SKAL stå FØR <util/delay.h>
#include <util/delay.h>
/*
Disse ligger i <util/delay.h>:
_delay_ms(1000);
_delay_ns(1000);
*/

void delay100ms(void) // nok ikke nødvendig når util...
{
	unsigned int i;
	for(i=0; i<42150; i++)
}

int main(void)
{
	delay100ms();
	
	return 0;
}