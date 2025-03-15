/*
 * MyDefs.h
 *
 *  Created on: 29 de mar. de 2016
 *      Author: xtian23
 */

#ifndef MYDEFS_H_
#define MYDEFS_H_

typedef struct{
	unsigned char B0:1;
	unsigned char B1:1;
	unsigned char B2:1;
	unsigned char B3:1;
	unsigned char B4:1;
	unsigned char B5:1;
	unsigned char B6:1;
	unsigned char B7:1;
}bit_t;

#define RegBit(reg,bit) ((volatile bit_t*)&reg)->B##bit
#define LED6 RegBit(PORTD,6)

#define SetBit(reg,bit) reg|=(1<<bit)
#define ClrBit(reg,bit) reg&=~(1<<bit)
#define TglBit(reg,bit) reg^=(1<<bit)
#define TestBit(reg,bit)	(reg&(1<<bit))

#define LED4_OFF SetBit(PORTD,4)
#define LED4_ON ClrBit(PORTD,4)
#define LED5_OFF SetBit(PORTD,5)
#define LED5_ON ClrBit(PORTD,5)
#define LED6_OFF SetBit(PORTD,6)
#define LED6_ON ClrBit(PORTD,6)
#define LED7_OFF SetBit(PORTD,7)
#define LED7_ON ClrBit(PORTD,7)

#endif /* MYDEFS_H_ */
