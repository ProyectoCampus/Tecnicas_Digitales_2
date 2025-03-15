/*
 * main.c
 * 6- En base al punto anterior implementar una versión del conocido juego Pac-Man. Con
las INT5, INT6 e INT7 moveremos nuestro personaje en el Display LCD alfanumérico
intentando evitar al fantasma, el juego debe constar de 5 niveles, para pasar de nivel
hay durar 15 segundos sin que el fantasma nos “atrape”, cuando se avanza de nivel
debe aumentar la velocidad en la que se mueve el fantasma.
INT5=Izquierda
INT6=Derecha
INT7= Cambiar de línea
 * */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd_alfa.h"
#include "MyDefsComplete.h"
#include <stdlib.h>


unsigned char Character1[8] = {0x00, 0x0F, 0x1A, 0x1C, 0x1E, 0x0F, 0x00, 0x00};
unsigned char Character2[8] = {0x0E, 0x1F, 0x15, 0x1F, 0x11, 0x1F, 0x15, 0x00};
//unsigned char Character3[8] = {0x00,0x1E,0x0B,0x07,0x0F,0x1E,0x00,0x00};
void LCDBuildChar(unsigned char, unsigned char*);


int main(void)
{
	lcd_init(LCD_DISP_ON);

	LCDBuildChar(0,Character1);
	LCDBuildChar(1,Character2);
	//LCDBuildChar(2,Character3);
	lcd_putc(0x00);
	lcd_gotoxy(0,1);
	lcd_putc(0x01);
//	Timer0_init(CTC,Timer0_Prescaler_64,Toggle_On_Comp_Match);
//	OCR0=250;
//	TIMER0_COMP_Interrupt_ON;
//	sei();

	while(1);
	return 0;
}

void LCDBuildChar(unsigned char loc, unsigned char *p)
{
 unsigned char i;
 if(loc<8) //If valid address
 {
  lcd_command(0x40+(loc*8)); //Write to CGRAM
  for(i=0;i<8;i++)
  put_kin(p[i]); //escribo el caracter personalizado de la CCRAM
 }
 lcd_command(0x80); //cambia de nuevo a la ubicacion cero de la DDRAM
}

