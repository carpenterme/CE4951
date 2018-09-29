/*
 * GPIO_driver.h
 *
 *  Created on: Sep 29, 2018
 *      Author: Mitchell Carpenter
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"
#include "stm32f4xx_it.h"

extern void configureGPIO();
extern void EXTI15_10_IRQHandler(void);

#endif /* GPIO_DRIVER_H_ */
