/*
 * main.c
 *
 *  Created on: 16 de mar. de 2018
 *      Author: xtian23
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "MyDefs.h"

#define SS_LOW ClrBit(PORTB,PB0)
#define SS_HIGH SetBit(PORTB,PB0)

unsigned char SPI_TX_RX(unsigned char);

void Init_spi(void);

int main(void)
{
	Init_spi();
	SS_LOW;
	SPI_TX_RX(0x12);
	SPI_TX_RX(0x34);
	SS_HIGH;

	while(1);
	return 0;
}

unsigned char SPI_TX_RX(unsigned char dato)
{
	SPDR=dato;
	while(!TestBit(SPSR,SPIF));
	return SPDR;
}

void Init_spi(void)
{
	DDRB|=(1<<PB0)|(1<<PB1)|(1<<PB2);	// Configuro como salida SS, MOSI y SCK
	SPCR|=(1<<SPE)|(1<<MSTR)|(1<<SPR1);

	}
