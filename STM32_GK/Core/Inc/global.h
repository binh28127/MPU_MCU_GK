/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"

// define for timer
// Timer0 for...
#define NO_OF_TIMERS		4

// define for button
#define NO_OF_BUTTONS		3

#define BUTTON_1			0
#define BUTTON_2			1
#define BUTTON_3			2

#define NORMAL_STATE		GPIO_PIN_SET
#define PRESSED_STATE 		GPIO_PIN_RESET

// global variables
extern int timerCycle;
extern int timerForKeyPress;

#endif /* INC_GLOBAL_H_ */
