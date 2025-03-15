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

unsigned char digito1, digito2, digito3, digito4;


ISR(TIMER0_COMP_vect)
{
	static unsigned char mux=1;

	PORTA=0;
	switch(mux)
	{
		case 1:
			PORTA = 0x10 | digito1;
			mux=2;
			break;
		case 2:
			PORTA = 0x20 | digito2;
			mux=3;
			break;
		case 3:
			PORTA = 0x40 | digito3;
			mux=4;
			break;
		case 4:
			PORTA = 0x80 | digito4;
			mux=1;
			break;
		default:
			mux=1;
			break;
	}
}

int main (void)
{
	DDRA=0xFF;		// PORTA COMO SALIDA

	// Configuro Timer0. Modo CTC. Prescaler 32. Salida Toggle
	TCCR0|=(1<<WGM01)|(0<<WGM00)|(1<<CS01)|(1<<CS00)|(0<<COM01)|(1<<COM00);
	OCR0=249;
	TIMSK|=(1<<OCIE0); 	// HABILITO LA INTERRUPCION POR COMPARACIÓN
	sei();							// Habilitación general de interrupciones

	digito1=1;
	digito2=2;
	digito3=3;
	digito4=4;

	while(1)
	{

	}

	return 0;
}

