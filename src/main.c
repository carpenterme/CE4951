/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "stm32f4xx_nucleo.h"
#include "LED_driver.h"

int main(void)
{
	HAL_InitTick(1);
	HAL_SetTickFreq(HAL_TICK_FREQ_1KHZ);
	init_leds();

	turn_on_led(1);
	turn_on_led(8);

	HAL_Delay(2000);

	turn_off_led(1);
	turn_off_led(8);

}
