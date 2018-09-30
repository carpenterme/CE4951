/*
 * GPIO_driver.c
 *
 *  Created on: Sep 29, 2018
 *      Author: Mitchell Carpenter
 */

#include "GPIO_driver.h"
#include "TIM2_driver.h"
#include "states.h"

void configureGPIO(){
	GPIO_InitTypeDef GPIO_InitButton;
	GPIO_InitButton.Pin = GPIO_PIN_13;
	GPIO_InitButton.Mode = GPIO_MODE_IT_RISING_FALLING;
	GPIO_InitButton.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOC, &GPIO_InitButton);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

void EXTI15_10_IRQHandler(void){
	HAL_NVIC_ClearPendingIRQ(EXTI15_10_IRQn);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_13);
	// HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9);

	set_cnt_timer2(0);
	start_timer2();

    if(cState != BUSY){
        cState = BUSY;
        updateState = TRUE;
    }
}
