/*
 * MyDefs.h
 *
 *  Created on: 8 de may. de 2017
 *      Author: xtian23
 */

#ifndef MYDEFS_H_
#define MYDEFS_H_

#define SetBit(reg,bit)	reg|=(1<<bit)
#define ClrBit(reg,bit)	reg&=~(1<<bit)
#define TglBit(reg,bit) reg^=(1<<bit)
#define TestBit(reg,bit) (reg&(1<<bit))	// devuelve 0 si el bit es 0
#define LED4_ON ClrBit(PORTD,4)
#define LED4_OFF SetBit(PORTD,4)
#define LED4_TGL TglBit(PORTD,4)
#define LED7_TGL TglBit(PORTD,7)
#define LED7_ON ClrBit(PORTD,7)
#define LED7_OFF SetBit(PORTD,7)

#define SET_INT7_RISING EICRB|=(1<<ISC71)|(1<<ISC70)			// ASCENDENTE
#define SET_INT7_FALLING EICRB|=(1<<ISC71); EICRB&=~(1<<ISC70)	// DESCENDENTE
#define SET_INT7_ON	EIMSK|=(1<<INT7)
#define SET_INT7_OFF EIMSK&=~(1<<INT7)

#define SET_INT6_RISING EICRB|=(1<<ISC61)|(1<<ISC60)			// ASCENDENTE
#define SET_INT6_FALLING EICRB|=(1<<ISC61); EICRB&=~(1<<ISC60)	// DESCENDENTE
#define SET_INT6_ON	EIMSK|=(1<<INT6)
#define SET_INT6_OFF EIMSK&=~(1<<INT6)

#define SET_INT5_RISING EICRB|=(1<<ISC51)|(1<<ISC50)			// ASCENDENTE
#define SET_INT5_FALLING EICRB|=(1<<ISC51); EICRB&=~(1<<ISC50)	// DESCENDENTE
#define SET_INT5_ON	EIMSK|=(1<<INT5)
#define SET_INT5_OFF EIMSK&=~(1<<INT5)

#define SET_INT4_RISING EICRB|=(1<<ISC41)|(1<<ISC40)			// ASCENDENTE
#define SET_INT4_FALLING EICRB|=(1<<ISC41); EICRB&=~(1<<ISC40)	// DESCENDENTE
#define SET_INT4_ON	EIMSK|=(1<<INT4)
#define SET_INT4_OFF EIMSK&=~(1<<INT4)

#define SET_MY_INTERRUPTS	SET_INT4_FALLING; SET_INT5_FALLING; SET_INT6_FALLING; SET_INT7_FALLING; EIMSK|=(1<<INT7)|(1<<INT6)|(1<<INT5)|(1<<INT4)


#endif /* MYDEFS_H_ */
