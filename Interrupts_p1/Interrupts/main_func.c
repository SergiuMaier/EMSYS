/*
 * main_func.c
 *
 * Created: 9/9/2021 2:46:37 PM
 *  Author: z0043zwt
 */ 

// ****************************************************************************************
// Header includes
// ***************************************************************************************/
#include "main_func.h"

// ****************************************************************************************
// Function definition
// ***************************************************************************************/

/*  @brief       Toggles the value of the specified pin.
 *  @param[in]   port: the port whose pin value is to be toggled.
 *  @param[in]   pin: the pin which will be toggled.
 *  @return      none.
 */
void pinToggle(volatile uint8_t *port, uint8_t pin)
{
	*port ^=  1 << pin;
}

/*  @brief       Set the value of the specified pin.
 *  @param[in]   port: the port whose pin value is to be configured.
 *  @param[in]   pin: the pin which will be configured.
 *  @return      none.
 */
void setPin(volatile uint8_t *port, uint8_t pin)
{
	*port |=  1 << pin;
}

/*  @brief       Reset the value of the specified pin.
 *  @param[in]   port: the port whose pin value is to be configured.
 *  @param[in]   pin: the pin which will be configured.
 *  @return      none.
 */
void resetPin(volatile uint8_t *port, uint8_t pin)
{
	*port &=  ~(1 << pin);
}