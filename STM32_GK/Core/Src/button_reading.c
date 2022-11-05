/*
 * button_reading.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "button_reading.h"

int button_state[NO_OF_BUTTONS] = { 0, 0, 0 };
int button_flag[NO_OF_BUTTONS] = { 0, 0, 0 };
GPIO_PinState key_reg[NO_OF_BUTTONS][4];

int isButtonPressed(int button) {
	if (button_flag[button]) {
		button_flag[button] = 0;
		return 1;
	}
	else return 0;
}

void fsmButtonProcessing(int button) {
	switch (button_state[button]) {
		case BUTTON_IS_RELEASED:
			// Press button
			if (key_reg[button][2] == PRESSED_STATE) {
				key_reg[button][3] = PRESSED_STATE;
				button_state[button] = BUTTON_IS_PRESSED;
				button_flag[button] = 1;
			}
			break;

		case BUTTON_IS_PRESSED:
			// Press button, then release
			if (key_reg[button][2] == NORMAL_STATE) {
				key_reg[button][3] = NORMAL_STATE;
				button_state[button] = BUTTON_IS_RELEASED;
			}
			break;

		default:
			break;
	}
}

void getKeyInput() {
	for (int button = 0; button < NO_OF_BUTTONS; button++) {
		key_reg[button][0] = key_reg[button][1];
		key_reg[button][1] = key_reg[button][2];
		switch (button) {
			case BUTTON_RESET:
				key_reg[button][2] = HAL_GPIO_ReadPin(BUTTON_RESET_GPIO_Port, BUTTON_RESET_Pin);
				break;
			case BUTTON_INC:
				key_reg[button][2] = HAL_GPIO_ReadPin(BUTTON_INC_GPIO_Port, BUTTON_INC_Pin);
				break;
			case BUTTON_DEC:
				key_reg[button][2] = HAL_GPIO_ReadPin(BUTTON_DEC_GPIO_Port, BUTTON_DEC_Pin);
				break;
			default:
				break;
		}

		if ((key_reg[button][0] == key_reg[button][1]) && (key_reg[button][1] == key_reg[button][2])) {
			fsmButtonProcessing(button);
		}
	}
}
