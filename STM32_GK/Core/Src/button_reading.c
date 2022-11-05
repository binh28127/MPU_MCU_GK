/*
 * button_reading.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "button_reading.h"

int button_state[NO_OF_BUTTONS] = { 0, 0, 0 };
int button_flag[NO_OF_BUTTONS] = { 0, 0, 0 };
int button_flag_3s[NO_OF_BUTTONS] = { 0, 0, 0 };
int button_flag_time_out[NO_OF_BUTTONS] = { 0, 0, 0 };
GPIO_PinState key_reg[NO_OF_BUTTONS][4];
int counterForKeyPress[NO_OF_BUTTONS];

int isButtonPressed(int button) {
	if (button_flag[button]) {
		button_flag[button] = 0;
		return 1;
	}
	else return 0;
}

int isButtonPressed3s(int button) {
	if (button_flag_3s[button]) {
		button_flag_3s[button] = 0;
		return 1;
	}
	else return 0;
}

int isButtonTimeOut(int button) {
	return (button_flag_time_out[button] == 1);
}

void setTimerForButton3s(int button) {
	counterForKeyPress[button] = timerForKeyPress3s / timerCycle;
}

void setTimerForButton1s(int button) {
	counterForKeyPress[button] = timerForKeyPress1s / timerCycle;
}

void setTimerForTimeOut(int button) {
	counterForKeyPress[button] = timerForTimeOut / timerCycle;
}

void fsmButtonProcessing(int button) {
	switch (button_state[button]) {
		case BUTTON_IS_RELEASED:
			// Press button
			if (key_reg[button][2] == PRESSED_STATE) {
				key_reg[button][3] = PRESSED_STATE;
				button_state[button] = BUTTON_IS_PRESSED;
				button_flag[button] = 1;
				setTimerForButton3s(button);
			}
			else {
				counterForKeyPress[button]--;
				if (!counterForKeyPress[button]) {
					button_flag_time_out[button] = 1;
					setTimer(1, timerForCountAuto);
				}
			}
			break;

		case BUTTON_IS_PRESSED:
			// Press button, then release
			if (key_reg[button][2] == NORMAL_STATE) {
				key_reg[button][3] = NORMAL_STATE;
				button_state[button] = BUTTON_IS_RELEASED;
				setTimerForTimeOut(button);
			}

			// Press and hold button 3s - long press
			else {
				counterForKeyPress[button]--;
				if (!counterForKeyPress[button]) {
					button_state[button] = BUTTON_IS_PRESSED_3s;
					button_flag_3s[button] = 1;
					setTimerForButton1s(button);
				}
			}
			break;

		case BUTTON_IS_PRESSED_3s:
			// Release button while long press
			if (key_reg[button][2] == NORMAL_STATE) {
				key_reg[button][3] = NORMAL_STATE;
				button_state[button] = BUTTON_IS_RELEASED;
				setTimerForTimeOut(button);
			}

			// Count 1s while long press
			else {
				counterForKeyPress[button]--;
				if (!counterForKeyPress[button]) {
					button_flag_3s[button] = 1;
					setTimerForButton1s(button);
				}
			}

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
