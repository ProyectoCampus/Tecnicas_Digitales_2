/*
 * main.c
 *
 *  Created on: 16 de mar. de 2018
 *      Author: xtian23
 */
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "MyInt.h"
#include "MyDefs.h"
#include "lcd_alfa.h"


char letra;

void uart0_putchar(char);
void uart0_puts(char*);
char uart0_getchar(void);

int main(void)
{
	UCSR0B|=(1<<TXEN0)|(1<<RXEN0);		// HABILITAR TX Y RX
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);	// DEFINIMOS 8N1
	UBRR0L=51;							// 9600bps
	UBRR0H=0;
	uart0_puts("HOLA MUNDO");
	while(1)
	{
		letra=uart0_getchar();
		uart0_putchar(letra+1);
	}
	return 0;
}

void uart0_putchar(char dato)
{
	while(!TestBit(UCSR0A, UDRE));
	UDR0=dato;
}

char uart0_getchar(void)
{
	while(!TestBit(UCSR0A, RXC));
	return UDR0;
	}

void uart0_puts(char* str)
{
	char dato;
	while(dato=*str++)
		uart0_putchar(dato);
}













