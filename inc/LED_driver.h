/*
 * LED_driver.h
 *
 *  Created on: Sep 18, 2018
 *      Author: TableMaster
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"
#include "stm32f4xx_it.h"

// Initializes the clock and mode for the leds
extern void init_leds();
// Given led (0-9), turns on the corresponding LED on the Board
extern void turn_on_led(int led);
// Given led (0-9), turns off the corresponding LED on the Board
extern void turn_off_led(int led);

#endif /* LED_DRIVER_H_ */
