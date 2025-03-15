/*
 * MyInt.h
 *
 *  Created on: 14 de may. de 2018
 *      Author: crixt
 */

#ifndef MYINT_H_
#define MYINT_H_


#define SET_INT5_ON EIMSK|=(1<<INT5)
#define SET_INT5_OFF EIMSK&=~(1<<INT5)
#define SET_INT5_FALLING EICRB|=(1<<ISC51);EICRB&=~(1<<ISC50)
#define SET_INT5_RISING EICRB|=(1<<ISC51)|(1<<ISC50)
#define SET_INT5_ANY_CHANGE EICRB|=(1<<ISC50);EICRB&=~(1<<ISC51)
#define SET_INT5_LOW_LEVEL EICRB&=~(1<<ISC51);EICRB&=~(1<<ISC50)

#define SET_INT6_ON EIMSK|=(1<<INT6)
#define SET_INT6_OFF EIMSK&=~(1<<INT6)
#define SET_INT6_FALLING EICRB|=(1<<ISC61);EICRB&=~(1<<ISC60)
#define SET_INT6_RISING EICRB|=(1<<ISC61)|(1<<ISC60)
#define SET_INT6_ANY_CHANGE EICRB|=(1<<ISC60);EICRB&=~(1<<ISC61)
#define SET_INT6_LOW_LEVEL EICRB&=~(1<<ISC61);EICRB&=~(1<<ISC60)

#define SET_INT7_ON EIMSK|=(1<<INT7)
#define SET_INT7_OFF EIMSK&=~(1<<INT7)
#define SET_INT7_FALLING EICRB|=(1<<ISC71);EICRB&=~(1<<ISC70)
#define SET_INT7_RISING EICRB|=(1<<ISC71)|(1<<ISC70)
#define SET_INT7_ANY_CHANGE EICRB|=(1<<ISC70);EICRB&=~(1<<ISC71)
#define SET_INT7_LOW_LEVEL EICRB&=~(1<<ISC71);EICRB&=~(1<<ISC70)

#define SET_INT567_ON EIMSK|=(1<<INT5)|(1<<INT6)|(1<<INT7)

#endif /* MYINT_H_ */
