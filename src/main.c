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

static TIM_HandleTypeDef TIMER2 = {
			.Instance = TIM2
	};
void init_timer2();

int main(void)
{
	HAL_Init();
	HAL_InitTick(1);
	HAL_SetTickFreq(HAL_TICK_FREQ_1KHZ);
	init_leds();
	init_timer2();
//	turn_on_led(1);
//	turn_on_led(8);
//
//	HAL_Delay(2000);
//
//	turn_off_led(1);
//	turn_off_led(8);
	for(;;){}
}

void init_timer2(){
	__TIM2_CLK_ENABLE();
	TIMER2.Init.Prescaler = 16000; //Set TIMCLK to count every ms
	TIMER2.Init.Period = 1000; //Set timer to overflow at 1s
	TIMER2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TIMER2.Init.CounterMode = TIM_COUNTERMODE_UP;
	TIMER2.Init.RepetitionCounter = 0; //Not used by tim2 set to 0
	HAL_TIM_Base_Init(&TIMER2);
	HAL_TIM_Base_Start_IT(&TIMER2);
	HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	HAL_NVIC_ClearPendingIRQ(TIM2_IRQn);

}

void TIM2_IRQHandler(void){
	HAL_TIM_IRQHandler(&TIMER2);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_10);
}
