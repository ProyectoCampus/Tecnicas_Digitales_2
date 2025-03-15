
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "MyDefs.h"
#include "lcd_alfa.h"
#include "TWI_driver.h"

#define SLAVE_ADD 0xD0

int main (void)
{
	lcd_init(LCD_DISP_ON);

	Init_TWI();

	while(1)
	{

	}
	return 0;
}


