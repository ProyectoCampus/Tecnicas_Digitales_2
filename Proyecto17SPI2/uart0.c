/*
 * uart0.c
 *
 *  Created on: 18 de jun. de 2018
 *      Author: crixt
 */

#include <avr/io.h>
#include "MyDefs.h"
#include <avr/interrupt.h>

void uart0_init(void)
{
	//Configuración de la UART0 9600 8N1

	UCSR0B|=(1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);	// 8N1 Interrupcion RXC
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ0);		// 8N1
	UBRR0H=0;							// 9600 bps
	UBRR0L=51;							// 9600 bps

}

void uart0_putchar(char dato)
{
	while(!TestBit(UCSR0A,UDRE0));
	UDR0=dato;
}

void uart0_puts(char* str)
{
	char k;
	while(k=*str++)
		uart0_putchar(k);
	uart0_putchar(10);
	uart0_putchar(13);
}

char uart0_getchar()
{
	while(!TestBit(UCSR0A,RXC0));
	return UDR0;
	}


