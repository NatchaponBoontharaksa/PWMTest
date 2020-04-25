/*
 * PWMTEST.c
 *
 * Created: 4/26/2020 12:33:48 AM
 * Author : Natchapon
 */ 

#include <avr/io.h>
#include "COMMON/common.h"

void PWMInit();
void IOInit();

int main(void)
{
    /* Replace with your application code */
	IOInit();
	PWMInit();
	
    while (1) 
    {
		
    }
}

void IOInit()
{
	DDRC = 0x00; //analog 0 is input
	DDRD = 0x60; //digital pin 5, 6 is output
}

void PWMInit()
{
	
}



