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
#include "MyDefs.h"
#include "t6963c.h"
#include "mickey2.h"
#include "android.h"
#include "youtube.h"
#include "pokemon.h"

ISR(INT7_vect);
ISR(INT6_vect);
ISR(INT5_vect);
ISR(INT4_vect);

int main (void)
{
	unsigned char x,y;

	DDRC|=0xFF;
	SET_MY_INTERRUPTS;
	sei();

	GLCD_Initalize();
	GLCD_ClearText();
	GLCD_ClearGraphic();
	GLCD_TextGoTo(0,0);
	GLCD_WriteString("ESTO ES UNA PRUEBA. PRESIONES LOS PULSADORES");
	GLCD_GraphicGoTo(0,0);
	for(x=60; x<69; x++)
	{
		for(y=60; y<69; y++)
			GLCD_SetPixel(x,y,1);
	}


	while(1);
	return 0;
}

ISR(INT7_vect)
{
	GLCD_ClearText();
	GLCD_Bitmap(&pokemon,0,0,128,128);
}
ISR(INT6_vect)
{
	GLCD_ClearText();
	GLCD_Bitmap(&youtube,0,0,128,128);
}
ISR(INT5_vect)
{
	GLCD_ClearText();

	GLCD_Bitmap(&mickey,0,0,128,128);
}
ISR(INT4_vect)
{
	GLCD_ClearText();
	GLCD_Bitmap(&android,0,0,128,128);
}


