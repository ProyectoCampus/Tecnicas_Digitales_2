/*
 * MyDefs.h
 *
 *  Created on: 29 de abr. de 2019
 *      Author: crixt
 */

#ifndef MYDEFS_H_
#define MYDEFS_H_

#define SetBit(reg,bit)	reg|=(1<<bit)
#define ClrBit(reg,bit)	reg&=~(1<<bit)
#define TglBit(reg,bit)	reg^=(1<<bit)
#define TestBit(reg,bit)	(reg & (1<<bit))	// devuelve '0' si el bit es '0'
#define LED4_ON	ClrBit(PORTD,4)
#define LED4_OFF	SetBit(PORTD,4)
#define LED4_CHG	TglBit(PORTD,4)
#define LED7_ON	ClrBit(PORTD,7)
#define LED7_OFF	SetBit(PORTD,7)
#define LED7_CHG	TglBit(PORTD,7)

#endif /* MYDEFS_H_ */
