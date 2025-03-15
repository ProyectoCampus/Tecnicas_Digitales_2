
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "MyDefs.h"
#include "lcd_alfa.h"
#include "TWI_driver.h"

#define SLAVE_ADD1 0x40

#define SLAVE_ADD2 0x4E

int main (void)
{

	Init_TWI();


	while(1)
	{

	}
	return 0;
}


