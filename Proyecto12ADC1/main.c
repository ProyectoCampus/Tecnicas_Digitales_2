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

unsigned int conversion;
unsigned int tension;
char cadena[20];

void ADC_init(void);
unsigned int ADC_read(char );

int main(void)
{
	lcd_init(LCD_DISP_ON);
	lcd_puts("PRUEBA ADC");
	_delay_ms(1000);

	ADC_init();
	lcd_clrscr();
	while(1)
	{
		conversion=ADC_read(2);
		tension=conversion * 2.5;
		sprintf(cadena,"ADC2: %04d mV",tension);
		lcd_gotoxy(0,0);
		lcd_puts(cadena);

		conversion=ADC_read(3);
		tension=conversion * 2.5;
		sprintf(cadena,"ADC3: %04d mV",tension);
		lcd_gotoxy(0,1);
		lcd_puts(cadena);
		_delay_ms(1000);
	}
	return 0;
}

void ADC_init(void)
{
	ADMUX|=(1<<REFS1)|(1<<REFS0);	// Referencia interna
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS0); 	// habilito el ADC y configuro Clock/32
}

unsigned int ADC_read(char canal)
{
	ADMUX&=0xE0;			// Pongo a cero todos los bits MUX
	ADMUX|=canal & 0x07;
	_delay_us(10);
	ADCSRA|=(1<<ADSC);		// INICIO LA CONVERSION
	while(!TestBit(ADCSRA,ADIF));	// ESPERO A QUE TERMINE
	return ADCW;
}

