#include <avr/io.h>
#define F_CPU 3686400
#include <util/delay.h>

int main()
{
	unsigned char i = 0x00;
	DDRA = 0x00; //port A as input
	DDRB = 0xFF; //port B as output
	
	while (1)
	{
		if(PINA = PINA & (1<<0)){}
		else
		{
			PORTB = i;
			_delay_us(1000);
			PORTB = ~i;
		}
		if(PINA = PINA & (1<<1)){}
		else
		{
			PORTB = i;
			_delay_us(900);
			PORTB = ~i;
		}
		
		if(PINA = PINA & (1<<2)){}
		else
		{
			PORTB = i;
			_delay_us(800);
			PORTB = ~i;
		}
		if(PINA = PINA & (1<<3)){}
		else
		{
			PORTB = i;
			_delay_us(700);
			PORTB = ~i;
		}
		if(PINA = PINA & (1<<4)){}
		else
		{
			PORTB = i;
			_delay_us(600);
			PORTB = ~i;
		}
		if(PINA = PINA & (1<<5)){}
		else
		{
			PORTB = i;
			_delay_us(500);
			PORTB = ~i;
		}
		if(PINA = PINA & (1<<6)){}
		else
		{
			PORTB = i;
			_delay_us(400);
			PORTB = ~i;
		}
		if(PINA = PINA & (1<<7)){}
		else
		{
			PORTB = i;
			_delay_us(300);
			PORTB = ~i;
		}
	}
	return 0;
}
