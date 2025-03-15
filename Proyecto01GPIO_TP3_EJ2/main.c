/*
 * main.c
 *
 *  Created on: 22 de abr. de 2019
 *      Author: crixt
 */

#include <avr/io.h>
#include <util/delay.h>

#define SetBit(reg,bit)	reg|=(1<<bit)
#define ClrBit(reg,bit)	reg&=~(1<<bit)
#define TglBit(reg,bit)	reg^=(1<<bit)
#define LED4_ON	ClrBit(PORTD,4)
#define LED4_OFF	SetBit(PORTD,4)
#define LED4_CHG	TglBit(PORTD,4)

int main (void)
{
	DDRD|=(1<<4);	// PONGO COMO SALIDA EL BIT 4 DE PORTD
	PORTD|=(1<<4);	// INICIALIZO EL BIT 4 EN 1 (LED APAGADO)

	while(1)
	{
		LED4_CHG;
		_delay_ms(500);

	}

	return 0;
}

