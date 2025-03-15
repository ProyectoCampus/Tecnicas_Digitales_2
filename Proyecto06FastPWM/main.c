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

unsigned int contador=0;

ISR(INT7_vect)
{
	LED7_CHG;
}

int main (void)
{
	DDRD|=(1<<4)|(1<<7);	// PONGO COMO SALIDA EL BIT 4 Y EL 7 DE PORTD
	DDRB|=(1<<PB4);			// PONGO OC0 (PB4) COMO SALIDA
	LED4_OFF;
	LED7_OFF;
	DDRE&=~(1<<7);	// INICIALIZO EL BIT 7 COMO ENTRADA
	//Configuro INT7

	// Configuro Timer0. Modo CTC. Prescaler 32. Salida Toggle
	TCCR0|=(1<<WGM01)|(1<<WGM00)|(1<<CS01)|(1<<CS00)|(1<<COM01)|(0<<COM00);
	OCR0=100;

	EICRB|=(1<<ISC71)|(0<<ISC70);	// DEFINO FLANCO DESCENDENTE
	EIMSK|=(1<<INT7);				// HABILITO INT7
	sei();							// Habilitación general de interrupciones

	while(1)
	{
//		LED4_CHG;
//		_delay_ms(500);

	}

	return 0;
}

