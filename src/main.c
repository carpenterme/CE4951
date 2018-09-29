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
#include "TIM2_driver.h"
#include "boolean.h"
#include "states.h"

const double DELAY_TIME = 1.11; // in milliseconds

int main(void)
{
	HAL_Init(); // Initialize HAL
	HAL_InitTick(1); // Initialize Systick
	HAL_SetTickFreq(HAL_TICK_FREQ_1KHZ);

	cState = IDLE;
	updateState = TRUE;

	init_leds();
	init_timer2(DELAY_TIME);

	while (1){
		if(updateState){
			switch(cState){
	        	case IDLE:
	        		turn_on_led(0);
	        		turn_off_led(1);
	        		turn_off_led(2);
					updateState = FALSE;
					break;
				case BUSY:
					turn_off_led(0);
					turn_on_led(1);
					turn_off_led(2);
					updateState = FALSE;
					break;
				case COLLISION:
					turn_off_led(0);
					turn_off_led(1);
					turn_on_led(2);
					updateState = FALSE;
					break;
			}
		}
		//HAL_Delay(10);
	}






//	turn_on_led(1);
//	turn_on_led(8);
//
//	HAL_Delay(2000);
//
//	turn_off_led(1);
//	turn_off_led(8);
}

