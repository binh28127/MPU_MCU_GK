/*
 * LED_blinking.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include "LED_blinking.h"

void LEDBlinking() {
	if (isTimerUp(0)) {
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer(0, LED_blinking_time);
	}
}
