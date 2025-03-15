/*
 * main.c
 *
 *  Created on: 22 de abr. de 2019
 *      Author: crixt
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "MyDefs.h"

ISR(INT7_vect)
{
	LED7_CHG;
}

int main (void)
{
	DDRD|=(1<<4)|(1<<7);	// PONGO COMO SALIDA EL BIT 4 Y EL 7 DE PORTD
	LED4_OFF;
	LED7_OFF;
	DDRE&=~(1<<7);	// INICIALIZO EL BIT 7 COMO ENTRADA
	//Configuro INT7

	EICRB|=(1<<ISC71)|(0<<ISC70);	// DEFINO FLANCO DESCENDENTE
	EIMSK|=(1<<INT7);				// HABILITO INT7
	sei();							// Habilitación general de interrupciones

	while(1)
	{
		LED4_CHG;
		_delay_ms(50);

	}

	return 0;
}

