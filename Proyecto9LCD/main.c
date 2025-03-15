/*
 * main.c
 *
 *  Created on: 16 de mar. de 2018
 *      Author: xtian23
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "MyInt.h"
#include "lcd_alfa.h"



int main(void)
{
	lcd_init(LCD_DISP_ON);
	lcd_puts("HOLA MUNDO");


	while(1)
	{

	}
	return 0;
}

