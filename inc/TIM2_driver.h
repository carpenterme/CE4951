/*
 * LED_driver.h
 *
 *  Created on: Sep 18, 2018
 *      Author: TableMaster
 */

#ifndef TIM2_DRIVER_H_
#define TIM2_DRIVER_H_

#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"
#include "stm32f4xx_it.h"

extern void init_timer2(double period_ms);
extern void start_timer2(void);
extern void stop_timer2(void);
void set_cnt_timer2(uint32_t cnt);
extern void TIM2_IRQHandler(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* TIM2_DRIVER_H_ */
