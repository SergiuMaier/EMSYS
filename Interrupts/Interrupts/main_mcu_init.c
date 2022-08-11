/*
 * main_mcu_init.c
 *
 * Created: 9/9/2021 2:47:13 PM
 *  Author: z0043zwt
 */ 

// ****************************************************************************************
// Header includes
// ***************************************************************************************/
#include "main_mcu_init.h"


// ****************************************************************************************
// Function definition
// ***************************************************************************************/

/*  @brief       Initialize port settings (direction, pull-ups).
 *  @return      none.
 */
void port_init(void)
{
	// Output port
	DDRB  = 0xFF;
	PORTB  = 0x00;
	
	// Input port
	DDRD  = 0x00;
	PORTD  = 0xFF;
}

/*  @brief       Init MCU peripherals and any devices connected to the MCU.
 *  @return      none.
 */
void init_devices(void)
{
	port_init();
}