/*
 * main.c
 *
 *  Created on: 17 de abr. de 2017
 *      Author: xtian23
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "MyDefs.h"
#include "t6963c.h"


int main (void)
{
	unsigned char i,j;

	GLCD_Initalize();
	GLCD_ClearText();
	GLCD_ClearGraphic();
	GLCD_TextGoTo(0,0);
	GLCD_WriteString("HOLA MUNDO");

	for(i=0;i<128;i++)
	{
		for(j=0;j<16;j++)
			GLCD_SetPixel(i,j,1);
	}


	while(1);
	return 0;
}


