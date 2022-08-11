/*
 * main_func.h
 *
 * Created: 9/9/2021 2:46:48 PM
 *  Author: z0043zwt
 */ 


#ifndef MAIN_FUNC_H_
#define MAIN_FUNC_H_

// ****************************************************************************************
// Header includes
// ****************************************************************************************
#include "main_config.h"
#include "main_defines.h"

#include <avr/io.h>

// ****************************************************************************************
// Function declaration
// ****************************************************************************************
void pinToggle(volatile uint8_t *port, uint8_t pin);
void setPin(volatile uint8_t *port, uint8_t pin);
void resetPin(volatile uint8_t *port, uint8_t pin);


#endif /* MAIN_FUNC_H_ */