/*
 * TIM2_driver.c
 *
 *  Created on: Sep 29, 2018
 *      Author: TableMaster
 */

#include "TIM2_driver.h"
#include "states.h"

static TIM_HandleTypeDef TIMER2 = {
	.Instance = TIM2
};

void init_timer2(double period_ms){
	__TIM2_CLK_ENABLE();
	TIMER2.Init.Prescaler = 160; //Set TIMCLK to count every ms
	TIMER2.Init.Period = (uint32_t)((16E6 / TIMER2.Init.Prescaler) * (period_ms / 1000)); //Set timer to overflow at 1s
	TIMER2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TIMER2.Init.CounterMode = TIM_COUNTERMODE_UP;
	TIMER2.Init.RepetitionCounter = 0; //Not used by tim2 set to 0
	HAL_TIM_Base_Init(&TIMER2);
	HAL_TIM_Base_Start(&TIMER2);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	stop_timer2();
}

void start_timer2(void){
	HAL_TIM_Base_Start_IT(&TIMER2);
	__HAL_TIM_SET_COUNTER(&TIMER2, 0);
	HAL_TIM_Base_Start(&TIMER2);
}

void stop_timer2(void){
	HAL_TIM_Base_Stop_IT(&TIMER2);
	HAL_TIM_Base_Stop(&TIMER2);
	__HAL_TIM_SET_COUNTER(&TIMER2, 0);
	__HAL_TIM_CLEAR_FLAG(&TIMER2, TIM_IT_UPDATE);
}


void TIM2_IRQHandler(void){
	HAL_TIM_IRQHandler(&TIMER2);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_SET){
		cState = IDLE;
	}
	else{
		cState = COLLISION;
	}
	stop_timer2();
	updateState = TRUE;
}

