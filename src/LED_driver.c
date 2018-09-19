/*
 * LED_driver.c
 *
 * Created on: Dec 5, 2016
 * Author: kallenbergermd
 * This code is the LED driver. It provides basic functions
 * and interactions with the LEDs.
 */

#include "LED_driver.h"

// set values for LED OFFSETS for GPIOA_ODR and GPIOB_ODR
const uint16_t LED_NUM[10] = {GPIO_PIN_7,GPIO_PIN_8,GPIO_PIN_9,GPIO_PIN_10,GPIO_PIN_11,GPIO_PIN_8,GPIO_PIN_9,GPIO_PIN_10,GPIO_PIN_12,GPIO_PIN_13};

// Initializes the clock and mode for the leds
void init_leds(){
	// Enable clocks for GPIOA and GPIOB
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	// Enable output mode for GPIOA LED pins
	GPIO_InitTypeDef LED_A;
	LED_A.Mode = GPIO_MODE_OUTPUT_PP;
	LED_A.Pin = GPIO_PIN_11 | GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7;
	HAL_GPIO_Init(GPIOA, &LED_A);

	// Enable output mode for GPIOB LED pins
	GPIO_InitTypeDef LED_B;
	LED_B.Mode = GPIO_MODE_OUTPUT_PP;
	LED_B.Pin = GPIO_PIN_13 | GPIO_PIN_12 | GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8;
	HAL_GPIO_Init(GPIOB, &LED_B);
}

// Given led (0-9), turns on the corresponding LED on the Board
void turn_on_led(int led){
	// Check if the LED is GPIOA
	if((led >= 0) && (led <=4)){
		// Use the LED offset of the led to set it high in the ODR
		HAL_GPIO_WritePin(GPIOA, LED_NUM[led], GPIO_PIN_SET);
	}
	// Check if the LED is GPIOB
	else if((led >= 5) && (led <=9)){
		// Use the LED offset of the led to set it high in the ODR
		HAL_GPIO_WritePin(GPIOB, LED_NUM[led], GPIO_PIN_SET);
	}
}

// Given led (0-9), turns off the corresponding LED on the Board
void turn_off_led(int led){
	// Check if the LED is GPIOA
	if((led >= 0) && (led <=4)){
		// Use the LED offset of the led to set it low in the ODR
		HAL_GPIO_WritePin(GPIOA, LED_NUM[led], GPIO_PIN_RESET);
	}
	// Check if the LED is GPIOB
	else if((led >= 5) && (led <=9)){
		// Use the LED offset of the led to set it low in the ODR
		HAL_GPIO_WritePin(GPIOB, LED_NUM[led], GPIO_PIN_RESET);
	}
}
