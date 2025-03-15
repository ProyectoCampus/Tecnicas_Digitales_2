/*
 * MyDefs.h
 *
 *  Created on: 7 de may. de 2018
 *      Author: crixt
 */

#ifndef MYDEFS_H_
#define MYDEFS_H_

#define ClrBit(reg,bit) reg&=~(1<<bit)
#define SetBit(reg,bit)	reg|=(1<<bit)
#define TglBit(reg,bit)	reg^=(1<<bit)
#define TestBit(reg,bit) (reg&(1<<bit))

#define LED7_ON		ClrBit(PORTD,7)
#define LED7_OFF 	SetBit(PORTD,7)
#define LED7_CHG	TglBit(PORTD,7)

#define LED5_ON		ClrBit(PORTD,5)
#define LED5_OFF 	SetBit(PORTD,5)
#define LED5_CHG	TglBit(PORTD,5)

#define LED4_ON		ClrBit(PORTD,4)
#define LED4_OFF 	SetBit(PORTD,4)
#define LED4_CHG	TglBit(PORTD,4)

#define SW7_PRESIONADO !TestBit(PINE,7)

#endif /* MYDEFS_H_ */
