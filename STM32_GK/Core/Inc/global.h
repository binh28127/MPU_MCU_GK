/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button_reading.h"
#include "7seg_display.h"
#include "LED_blinking.h"

// define for timer
// Timer0 for LED blinking
#define NO_OF_TIMERS		4

// define for button
#define NO_OF_BUTTONS		3

#define BUTTON_RESET		0
#define BUTTON_INC			1
#define BUTTON_DEC			2

#define NORMAL_STATE		GPIO_PIN_SET
#define PRESSED_STATE 		GPIO_PIN_RESET

// define for single LEDs

// define for 7seg LEDs
#define NO_OF_7SEGS			1

// define for fsm_simple_buttons
#define INIT				0
#define COUNT_RESET			1
#define COUNT_UP			2
#define COUNT_DOWN			3

// global variables
extern int timerCycle;
extern int timerForKeyPress3s;
extern int timerForKeyPress1s;

extern int LED_blinking_time;

extern int counter;
extern int state;

#endif /* INC_GLOBAL_H_ */
