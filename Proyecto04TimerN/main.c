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

ISR(TIMER0_OVF_vect)
{
	TCNT0=6;
	contador++;
	if(contador==500)
	{
		contador=0;
		LED4_CHG;
	}
}

int main (void)
{
	DDRD|=(1<<4)|(1<<7);	// PONGO COMO SALIDA EL BIT 4 Y EL 7 DE PORTD
	LED4_OFF;
	LED7_OFF;
	DDRE&=~(1<<7);	// INICIALIZO EL BIT 7 COMO ENTRADA
	//Configuro INT7

	// Configuro Timer0. Modo Normal. Prescaler 32
	TCCR0|=(0<<WGM00)|(0<<WGM01)|(1<<CS01)|(1<<CS00);
	TIMSK|=(1<<TOIE0); 	// HABILITO LA INTERRUPCION POR OV

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

