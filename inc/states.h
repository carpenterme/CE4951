/*
 * LED_driver.h
 *
 *  Created on: Sep 18, 2018
 *      Author: TableMaster
 */

#ifndef STATES_H_
#define STATES_H_

#include "boolean.h"

typedef enum{
	IDLE,
	BUSY,
	COLLISION
}State;

volatile State cState;
volatile bool updateState;

#endif /* STATES_H_ */
