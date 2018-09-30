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
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitButton;
	GPIO_InitButton.Pin = GPIO_PIN_13;
	GPIO_InitButton.Mode = GPIO_MODE_IT_RISING_FALLING;
	GPIO_InitButton.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOC, &GPIO_InitButton);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void){
	stop_timer2();
    if(cState != BUSY){
        cState = BUSY;
        updateState = TRUE;
    }
    __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_13);
    start_timer2();
}
