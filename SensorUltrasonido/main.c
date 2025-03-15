/*
 * main.c
 *
 *  Created on: 26/08/2014
 *      Author: Cristian
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "lcd_alfa.h"
#include "Timer0.h"

#define SET_INT2_FALLING	EICRA=0x20
#define SET_INT2_RISING		EICRA=0x30
#define SET_INT2_ON			EIMSK|=(1<<INT2)
#define SET_INT2_OFF		EIMSK&=~(1<<INT2)
#define SET_TRIGGER_HIGH	PORTD|=(1<<3)
#define SET_TRIGGER_LOW		PORTD&=~(1<<3)
#define ASCENDENTE 			0
#define DESCENDENTE 		1

unsigned char flanco;
unsigned int contador;
unsigned int distancia;
char distanciaCadena[]="3000mm";

ISR(TIMER0_COMP_vect)					//Rutina de Interrupcion por compare correcta del Timer0
{
	contador++;

}

ISR(INT2_vect)
{
	if(flanco==ASCENDENTE)
	{
		contador=0;
		TCNT0=0;
		TIMER0_COMP_Interrupt_ON;
		flanco=DESCENDENTE;
		SET_INT2_FALLING;
	}
	else
	{
		distancia=contador*1.7;
		TIMER0_COMP_Interrupt_OFF;
	}

}

int main (void)
{
	lcd_init(LCD_DISP_ON);
	lcd_puts("INICIANDO");
	DDRD|=(1<<3);
	DDRD|=(1<<4);
	Timer0_init(CTC,Timer0_Prescaler_1,Disconected);
	OCR0=79;
	sei();

	_delay_ms(1000);

	lcd_clrscr();
	lcd_puts("TP5 - EJ2 ");
	while(1)
	{
		SET_TRIGGER_HIGH;
		_delay_us(10);
		SET_TRIGGER_LOW;
		flanco=ASCENDENTE;
		SET_INT2_RISING;
		SET_INT2_ON;
		_delay_ms(500);
		sprintf(distanciaCadena,"%4dmm",distancia);
		lcd_gotoxy(0,1);
		lcd_puts(distanciaCadena);
	}
	return 0;
}


