
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "MyDefs.h"

//unsigned int contador=0;
ISR(INT5_vect)
{
	if(OCR0>13) // DISMINUYO EL 5%
	OCR0-=13;
	else
		OCR0=0;
}
ISR(INT6_vect)  //RESETEO EN 50%
{
	OCR0=127;
}
ISR(INT7_vect)  //AUMENTO EL 5%
{
	if(OCR0<255-13)
	OCR0+=13;
	else
		OCR0=255;
}

int main (void)
{
	DDRD|=(1<<4)|(1<<7);	// PONGO COMO SALIDA EL BIT 4 Y EL 7 DE PORTD
	DDRB|=(1<<PB4);			// PONGO OC0 (PB4) COMO SALIDA
	LED4_OFF;
	LED7_OFF;
	DDRE=0x00;	// INICIALIZO EL port E como entrada
	//Configuro INT7

	// Configuro Timer0. Modo CTC. Prescaler 32. Salida Toggle
	TCCR0|=(1<<WGM01)|(1<<WGM00)|(1<<CS01)|(1<<CS00)|(1<<COM01)|(0<<COM00);
	OCR0=127;

	EICRB|=(1<<ISC71)|(0<<ISC70);	// DEFINO FLANCO DESCENDENTE
	EIMSK|=(1<<INT7);				// HABILITO INT7
	EICRB|=(1<<ISC61)|(0<<ISC60);	// DEFINO FLANCO DESCENDENTE
	EIMSK|=(1<<INT6);				// HABILITO INT6
	EICRB|=(1<<ISC51)|(0<<ISC50);	// DEFINO FLANCO DESCENDENTE
	EIMSK|=(1<<INT5);				// HABILITO INT5
	sei();							// Habilitación general de interrupciones

	while(1)
	{
//		LED4_CHG;
//		_delay_ms(500);

	}

	return 0;
}
