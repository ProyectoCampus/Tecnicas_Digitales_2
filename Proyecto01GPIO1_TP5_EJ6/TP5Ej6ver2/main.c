/*
 * main.c
 * 6- En base al punto anterior implementar una versi�n del conocido juego Pac-Man. Con
las INT5, INT6 e INT7 moveremos nuestro personaje en el Display LCD alfanum�rico
intentando evitar al fantasma, el juego debe constar de 5 niveles, para pasar de nivel
hay durar 15 segundos sin que el fantasma nos �atrape�, cuando se avanza de nivel
debe aumentar la velocidad en la que se mueve el fantasma.
INT5=Izquierda
INT6=Derecha
INT7= Cambiar de l�nea
 * */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "lcd_alfa.h"
#include "MyDefsComplete.h"



volatile unsigned int pospacka=0,pospackb=0,k=0,t=0,q=0;
volatile unsigned int posgosta=12,posgostb=0;

volatile unsigned int Px=0,Py=0,Gx=12,Gy=0;
volatile unsigned int k=0,t=0,q=0;
//INT5=Izquierda
//INT6=Derecha
//INT7= Cambiar de l�nea

ISR(TIMER0_COMP_vect)					//Rutina de Interrupcion por compare correcta del Timer0
{

  q++;
  if(q==100){
  q=0;
	int p1,p2;
	p1= rand()%16;
	p2= rand()% 2;


	posgosta=p1;
	posgostb=p2;
	lcd_clrscr();

    lcd_gotoxy(pospacka,pospackb);
	if(t==0)
	lcd_putc(0x00);
	else
	lcd_putc(0x02);
	lcd_gotoxy(posgosta,posgostb);
	lcd_putc(0x01);
              }

}

 /* q++;
  if(q==100){
  q=0;
	int p1,p2;
	p1= rand()%16;
	p2= rand()% 2;


	Gx=p1;
	Gy=p2;
	lcd_clrscr();

    lcd_gotoxy(Px,Py);
	if(t==0)
	lcd_putc(0x04);
	else
	lcd_putc(0x06);
	lcd_gotoxy(Gx,Gy);
	lcd_putc(0x05);
              }*/

ISR(INT5_vect){
lcd_clrscr();
pospacka++;

if(k==1){
k=0;
posgosta= rand()%16;
posgostb= rand()% 2;
}
if(pospacka==15){
	if(pospackb == 0){
		pospackb=1;
		pospacka=0;
	                 }
	else{
			pospackb=0;
			pospacka=0;
		                }
}

if((pospacka == posgosta) && (pospackb == posgostb) ){
lcd_clrscr();

lcd_puts("    YOU WIN   ");
k++;
}
else{
lcd_gotoxy(pospacka,pospackb);
lcd_putc(0x00);
t=0;
lcd_gotoxy(posgosta,posgostb);
lcd_putc(0x01);
   }

}
ISR(INT6_vect){
	lcd_clrscr();



	if(pospacka>0){
		pospacka--;
		if(k==1){
		k=0;
		posgosta= rand()%16;
		posgostb= rand()% 2;
		}
	}
	else{
		if(pospackb == 0){
				pospackb=1;
				pospacka=16;
			                 }
			else{
					pospackb=0;
					pospacka=16;
				                }

	}
	if((pospacka == posgosta) && (pospackb == posgostb) ){
	lcd_clrscr();

	lcd_puts("    YOU WIN   ");
	k++;
	}
	else{
	lcd_gotoxy(pospacka,pospackb);
	lcd_putc(0x02);
	t=1;
	lcd_gotoxy(posgosta,posgostb);
	lcd_putc(0x01);
	   }
}

ISR(INT7_vect){

	if(k==1){
			k=0;
			posgosta= rand()%16;
			posgostb= rand()% 2;
			}

if(pospackb==1)
pospackb=0;
else
pospackb=1;
lcd_clrscr();

if((pospacka == posgosta) && (pospackb == posgostb) ){
	lcd_clrscr();

	lcd_puts("    YOU WIN   ");
	k++;
	}
else{
lcd_gotoxy(pospacka,pospackb);
if(t==0)
lcd_putc(0x00);
else
lcd_putc(0x02);
lcd_gotoxy(posgosta,posgostb);
lcd_putc(0x01);
}}

unsigned char Character1[8] = {0x00, 0x0F, 0x1A, 0x1C, 0x1E, 0x0F, 0x00, 0x00};
unsigned char Character2[8] = {0x0E, 0x1F, 0x15, 0x1F, 0x11, 0x1F, 0x15, 0x00};
unsigned char Character3[8] = {0x00,0x1E,0x0B,0x07,0x0F,0x1E,0x00,0x00};
void LCDBuildChar(unsigned char, unsigned char*);


int main(void)
{
	// HABILITACION GENERAL DE INTERRUPCIONES

	lcd_init(LCD_DISP_ON);
	SET_INT5_ON;
	SET_INT5_FALLING;
	SET_INT6_ON;
	SET_INT6_FALLING;
	SET_INT7_ON;
	SET_INT7_FALLING;


	LCDBuildChar(0,Character1);
	LCDBuildChar(1,Character2);
	LCDBuildChar(2,Character3);
	lcd_putc(0x00);
	lcd_gotoxy(posgosta,posgostb);
	lcd_putc(0x01);
	TIMER0_CTC;
	TIMER0_CLK_64;
	OC0_CHG;
	TIMER0_ECOMPARE;
	OCR0=250;

	sei();

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

