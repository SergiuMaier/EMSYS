/*
 * main_mcu_init.h
 *
 * Created: 9/9/2021 2:47:03 PM
 *  Author: z0043zwt
 */ 


#ifndef MAIN_MCU_INIT_H_
#define MAIN_MCU_INIT_H_

// ****************************************************************************************
// Header includes
// ****************************************************************************************
#include "main_config.h"
#include "main_defines.h"

#include <avr/wdt.h>

// ****************************************************************************************
// Function declaration
// ****************************************************************************************
void port_init(void);
void init_devices(void);


#endif /* MAIN_MCU_INIT_H_ */