/*
 * Interrupts.c
 *
 * Created: 9/10/2021 10:43:30 AM
 * Author : z0043zwt
 */ 

#include "main_config.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#include "main_defines.h"
#include "main_mcu_init.h"
#include "main_func.h"

int main(void)
{
	// LED0-output port (toggle led) / LED1-output port (button pressed led) / BUTTON1-input port (button)
	init_devices();
	
	do
	{
		// toggle pin
		pinToggle(&LED0_PORT, LED0_PIN);
		// long time delay - 2 seconds
		_delay_ms(2000);		
		
		// read button state. When the button is pressed -> set LED1. When the button is not pressed -> reset LED1.
		if ( (PIND & (1 << BUTTON1_PIN)) == 0x00 ) 
		{
			// pin is high
			setPin(&LED1_PORT, LED1_PIN);
		} else 
		{
			// pin is low
			resetPin(&LED1_PORT, LED1_PIN);
		}
		
		// TODO: change the code in order to get a fast response from MCU when the button is pressed.
	}
	while (1);
}


