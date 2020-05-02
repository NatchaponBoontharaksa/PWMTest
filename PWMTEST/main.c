/*
 * PWMTEST.c
 *
 * Created: 4/26/2020 12:33:48 AM
 * Author : Natchapon
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include "COMMON/common.h"
#include "main.h"
//#include "ADC/ADC.h"

void PWMInit();
void IOInit();
U2 mapValue(U2 tmp_duty);
void ADCInit();
U2 readADC();
U2 duty;

int main(void)
{	
	PWMInit();
	IOInit();
	ADCInit();
	duty = 0;
	
    while (1) 
    {
		//ADCInit();
		duty = readADC();
		duty = mapValue(duty);
		OCR0A = duty;
		PORTD |= 1 << DDD6;
    }
}

void IOInit()
{
	DDRD |= (1 << DDD6) | (1 << DDD5); //digital pin 6 is output
	PORTD = 0x00;
}

void PWMInit()
{
	OCR0A = 0;
	// set PWM for 0% duty cycle

	TCCR0A |= (1 << COM0A1);
	// set none-inverting mode

	TCCR0A |= (1 << WGM01) | (1 << WGM00);
	// set fast PWM Mode
}


U2 mapValue(U2 tmp_duty)
{
	return (tmp_duty * 255) / 1023;
}

void ADCInit()
{
	ADMUX = 0;         // use #0 ADC
	ADMUX |= (1 << REFS0);    // use AVcc as the reference
	ADMUX &= ~(1 << ADLAR);   // clear for 10 bit resolution
	
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);    // 128 prescale for 8Mhz
	ADCSRA |= (1 << ADEN);    // Enable the ADC
	
	/*
	ADCSRA |= (1 << ADSC);
	
	while(ADCSRA & (1 << ADSC))
	{
		PORTD |= (1 << DDD5);
	}
	
	PORTD |= ~(1 << DDD5);
	*/
}

U2 readADC()
{
	ADCSRA |= (1 << ADSC);
	
	while(ADCSRA & (1 << ADSC))
	{
		PORTD |= (1 << DDD5);
		_delay_ms(2000);
		PORTD &= ~(1 << DDD5);
		_delay_ms(2000);
	}
	
	
	return ADC;
}