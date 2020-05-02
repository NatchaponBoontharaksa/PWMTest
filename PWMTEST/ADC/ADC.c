
#include "../COMMON/common.h"
#include "../main.h"
#include "ADC.h"
#include <avr/io.h>
/*
void ADCInit()
{
	ADMUX = 0;         // use #0 ADC
	ADMUX |= (1 << REFS0);    // use AVcc as the reference
	ADMUX &= ~(1 << ADLAR);   // clear for 10 bit resolution
	
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);    // 128 prescale for 8Mhz
	ADCSRA |= (1 << ADEN);    // Enable the ADC
	
	
	ADCSRA |= (1 << ADSC);
	
	while(ADCSRA & (1 << ADSC))
	{
		PORTD |= (1 << DDD5);
	}
	
	PORTD |= ~(1 << DDD5);
	
}
*/
/*
U2 readADC()
{
	ADCSRA |= (1 << ADSC);
	
	while(ADCSRA & (1 << ADSC))
	{
		PORTD |= (1 << DDD5);
	}
	
	PORTD |= ~(1 << DDD5);
	
	return ADC;
}
*/