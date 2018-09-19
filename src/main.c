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
#include "stm32f4xx_nucleo.h"
#include "LED_driver.h"

int main(void)
{
	init_leds();

	turn_on_led(1);
	turn_on_led(8);

	for(int i = 0; i < 8000000; i++);

	turn_off_led(1);
	turn_off_led(8);

}
