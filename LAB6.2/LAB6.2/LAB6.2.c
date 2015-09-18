#define F_CPU 3686400UL
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
	DDRA = 0;		// indput
	DDRB = 0xFF;	// output

	while(1)
	{
		PORTB = 0xFF;	// leds off
		if((PINA & 0b00000001)==0)
		{
			// SW0 - 100ms - 5%
			PORTB = 0xFF;
			_delay_ms(0.05*100);
			PORTB = 0x00;
			_delay_ms(0.95*100);
		}
		
		if((PINA & 0b00000010)==0)
		{
			// SW1 - 100ms - 50%
			PORTB = 0xFF;
			_delay_ms(0.50*100);
			PORTB = 0x00;
			_delay_ms(0.50*100);
		}
		if((PINA & 0b00000100)==0)
		{
			// SW2 - 100ms - 25%
			PORTB = 0xFF;
			_delay_ms(0.25*100);
			PORTB = 0x00;
			_delay_ms(0.75*100);
		}
		if((PINA & 0b00001000)==0)
		{
			// SW3 - 1000us - 5%
			PORTB = 0xFF;
			_delay_us(0.05*1000);
			PORTB = 0x00;
			_delay_us(0.95*1000);
		}
		if((PINA & 0b00010000)==0)
		{
			// SW4 - 1000us - 95%
			PORTB = 0xFF;
			_delay_us(0.95*1000);
			PORTB = 0x00;
			_delay_us(0.05*1000);
		}
	}
	
	return 0;
}