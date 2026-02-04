/**
 ******************************************************************************
 * @file           : main.c
 * @author         : AYYAPPA
 * @brief          : Main program body
 ******************************************************************************
 * Here the delay function is not working properly i just write to skip some instructions to get the led in stable
 ******************************************************************************
 */
#include <stdint.h>
#include "defines.h"

void delay_ms(int d)
{
	volatile unsigned int i,j;
	for(j=0;j<d;j++)
		for (i = 0; i < 3200; i++);
}

int main(void)
{
	SET_BIT(RCC_IOPENR,0); // enabling clock

	SET_BIT(PORTA_MODER,10);// setting the direction of the PA5 onboard led
	CLR_BIT(PORTA_MODER,11);

	while(1)
	{
		CLR_BIT(PORTA_BSRR,21);
		SET_BIT(PORTA_BSRR,5);
		delay_ms(1000);
		CLR_BIT(PORTA_BSRR,5);
		SET_BIT(PORTA_BSRR,21);
		delay_ms(1000);
	}

}
