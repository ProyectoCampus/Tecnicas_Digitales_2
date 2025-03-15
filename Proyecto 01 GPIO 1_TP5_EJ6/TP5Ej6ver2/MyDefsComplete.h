/*
 * MyDefsComplete.h
 *
 *  Created on: 24 de jul. de 2019
 *      Author: natalia
 */

#ifndef MYDEFSCOMPLETE_H_
#define MYDEFSCOMPLETE_H_

#define SetBit(reg,bit)	reg|=(1<<bit)
#define ClrBit(reg,bit)	reg&=~(1<<bit)
#define TglBit(reg,bit)	reg^=(1<<bit)	// xor cambia un estado del bit que sea de ese registro
#define TestBit(reg,bit) (reg&(1<<bit))	// devuelve '0' si el bit es '0'

//leds en el puerto d

#define LED5_ON		ClrBit(PORTD,4)
#define LED5_OFF	SetBit(PORTD,4)
#define LED5_CHG	TglBit(PORTD,4)
#define LED6_ON		ClrBit(PORTD,5)
#define LED6_OFF	SetBit(PORTD,5)
#define LED6_CHG	TglBit(PORTD,5)
#define LED7_ON		ClrBit(PORTD,6)
#define LED7_OFF	SetBit(PORTD,6)
#define LED7_CHG	TglBit(PORTD,6)
#define LED8_ON		ClrBit(PORTD,7)
#define LED8_OFF	SetBit(PORTD,7)
#define LED8_CHG	TglBit(PORTD,7)

//leds en el puerto e

#define LED1_ON		ClrBit(PORTE,0)
#define LED1_OFF	SetBit(PORTE,0)
#define LED1_CHG	TglBit(PORTE,0)
#define LED2_ON		ClrBit(PORTE,1)
#define LED2_OFF	SetBit(PORTE,1)
#define LED2_CHG	TglBit(PORTE,1)
#define LED3_ON		ClrBit(PORTE,2)
#define LED3_OFF	SetBit(PORTE,2)
#define LED3_CHG	TglBit(PORTE,2)
#define LED4_ON		ClrBit(PORTE,3)
#define LED4_OFF	SetBit(PORTE,3)
#define LED4_CHG	TglBit(PORTE,3)

//configuracion de interreupciones

//int0~3 en el puerto d

#define SET_INT0_RISING EICRA|=(1<<ISC01)|(1<<ISC00)//ASCENDENTE
#define SET_INT0_FALLING EICRA|=(1<<ISC01); EICRB&=~(1<<ISC00) //DESCENDENTE
#define SET_INT0_ON EIMSK|=(1<<INT0)
#define SET_INT0_OFF EIMSK&=~(1<<INT0)

#define SET_INT1_RISING EICRA|=(1<<ISC11)|(1<<ISC10)//ASCENDENTE
#define SET_INT1_FALLING EICRA|=(1<<ISC11); EICRB&=~(1<<ISC10) //DESCENDENTE
#define SET_INT1_ON EIMSK|=(1<<INT1)
#define SET_INT1_OFF EIMSK&=~(1<<INT1)

#define SET_INT2_RISING EICRA|=(1<<ISC21)|(1<<ISC20)//ASCENDENTE
#define SET_INT2_FALLING EICRA|=(1<<ISC21); EICRB&=~(1<<ISC20) //DESCENDENTE
#define SET_INT2_ON EIMSK|=(1<<INT2)
#define SET_INT2_OFF EIMSK&=~(1<<INT2)

#define SET_INT3_RISING EICRA|=(1<<ISC31)|(1<<ISC30)//ASCENDENTE
#define SET_INT3_FALLING EICRA|=(1<<ISC31); EICRB&=~(1<<ISC30) //DESCENDENTE
#define SET_INT3_ON EIMSK|=(1<<INT3)
#define SET_INT3_OFF EIMSK&=~(1<<INT3)

//int4~7 en el puerto e

#define SET_INT4_RISING EICRB|=(1<<ISC41)|(1<<ISC40)//ASCENDENTE
#define SET_INT4_FALLING EICRB|=(1<<ISC41); EICRB&=~(1<<ISC40) //DESCENDENTE
#define SET_INT4_ANYCHG EICRB|=(1<<ISC40)//ANY CHANGE
#define SET_INT4_ON EIMSK|=(1<<INT4)
#define SET_INT4_OFF EIMSK&=~(1<<INT4)

#define SET_INT5_RISING EICRB|=(1<<ISC51)|(1<<ISC50)//ASCENDENTE
#define SET_INT5_FALLING EICRB|=(1<<ISC51); EICRB&=~(1<<ISC50) //DESCENDENTE
#define SET_INT5_ANYCHG EICRB|=(1<<ISC50)//ANY CHANGE
#define SET_INT5_ON EIMSK|=(1<<INT5)
#define SET_INT5_OFF EIMSK&=~(1<<INT5)

#define SET_INT6_RISING EICRB|=(1<<ISC61)|(1<<ISC60)//ASCENDENTE
#define SET_INT6_FALLING EICRB|=(1<<ISC61); EICRB&=~(1<<ISC60) //DESCENDENTE
#define SET_INT6_ANYCHG EICRB|=(1<<ISC60)//ANY CHANGE
#define SET_INT6_ON EIMSK|=(1<<INT6)
#define SET_INT6_OFF EIMSK&=~(1<<INT6)

#define SET_INT7_RISING EICRB|=(1<<ISC71)|(1<<ISC70)//ASCENDENTE
#define SET_INT7_FALLING EICRB|=(1<<ISC71); EICRB&=~(1<<ISC70) //DESCENDENTE
#define SET_INT7_ANYCHG EICRB|=(1<<ISC70)//ANY CHANGE
#define SET_INT7_ON EIMSK|=(1<<INT7)
#define SET_INT7_OFF EIMSK&=~(1<<INT7)

//Configuracion de Timers

#define CLEAR_TIMER_INTERRUPT TIMSK=0 //dehabilito las interrupciones de los timers

//timer0

#define TIMER0_NORMAL TCCR0&=~(1<<WGM00);TCCR0&=~(1<<WGM01)
#define TIMER0_CTC TCCR0&=~(1<<WGM00);TCCR0|=(1<<WGM01)
#define TIMER0_PWM TCCR0|=(1<<WGM00);TCCR0|=(1<<WGM01)

#define OC0_OFF TCCR0&=~(1<<COM00);TCCR0&=~(1<<COM01)
#define OC0_CHG TCCR0|=(1<<COM00);TCCR0&=~(1<<COM01) //es la toggle en non-PWM mode y reservada en fast PWM mode
#define OC0_CLEAR_PWMNOR TCCR0&=~(1<<COM00);TCCR0|=(1<<COM01)
#define OC0_SET_PWRINV TCCR0|=(1<<COM00);TCCR0|=(1<<COM01)

#define TIMER0_CLKOFF TCCR0&=0xF8
#define TIMER0_CLK TCCR0&=0xF8; TCCR0|=0x01
#define TIMER0_CLK_8 TCCR0&=0xF8; TCCR0|=0x02
#define TIMER0_CLK_32 TCCR0&=0xF8; TCCR0|=0x03
#define TIMER0_CLK_64 TCCR0&=0xF8; TCCR0|=0x04
#define TIMER0_CLK_128 TCCR0&=0xF8; TCCR0|=0x05
#define TIMER0_CLK_256 TCCR0&=0xF8; TCCR0|=0x06
#define TIMER0_CLK_1024 TCCR0&=0xF8; TCCR0|=0x07

#define TIMER0_EOVERFLOW TIMSK&=~0xFD; TIMSK|=(1<<TOIE0)
#define TIMER0_ECOMPARE TIMSK&=~0xFD; TIMSK|=(1<<OCIE0)

//timer2

#define TIMER2_NORMAL TCCR0&=~(1<<WGM20);TCCR0&=~(1<<WGM21)
#define TIMER2_CTC TCCR0&=~(1<<WGM20);TCCR0|=(1<<WGM21)
#define TIMER2_PWM TCCR0|=(1<<WGM20);TCCR01|=(1<<WGM21)

#define OC2_OFF TCCR2&=~(1<<COM20);TCCR2&=~(1<<COM21)
#define OC2_CHG TCCR2|=(1<<COM20);TCCR2&=~(1<<COM21)
#define OC2_CLEAR_PWMNOR TCCR2&=~(1<<COM00);TCCR2|=(1<<COM21)
#define OC2_SET_PWRINV TCCR2|=(1<<COM20);TCCR2|=(1<<COM21)

#define TIMER2_CLKOFF TCCR2&=0xF8
#define TIMER2_CLK TCCR2&=0xF8; TCCR2|=0x01
#define TIMER2_CLK_8 TCCR2&=0xF8; TCCR2|=0x02
#define TIMER2_CLK_32 TCCR2&=0xF8; TCCR2|=0x03
#define TIMER2_CLK_64 TCCR2&=0xF8; TCCR2|=0x04
#define TIMER2_CLK_128 TCCR2&=0xF8; TCCR2|=0x05
#define TIMER2_CLK_256 TCCR2&=0xF8; TCCR2|=0x06
#define TIMER2_CLK_1024 TCCR2&=0xF8; TCCR2|=0x07

#define TIMER2_EOVERFLOW TIMSK&=~0x3F; TIMSK|=(1<<TOIE2)
#define TIMER2_ECOMPARE TIMSK&=~0x3F; TIMSK|=(1<<OCIE2)

#endif /* MYDEFSCOMPLETE_H_ */


//#endif /* MYDEFS_H_ */
