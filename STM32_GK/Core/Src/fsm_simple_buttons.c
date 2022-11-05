/*
 * fsmSimpleButtons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include "fsm_simple_buttons.h"

void fsmSimpleButtonsRun() {
	switch (state) {
		case INIT:
			state = COUNT_RESET;
			break;

		case COUNT_RESET:
			updateBuffer();

			// Press button RESET
			if (isButtonPressed(BUTTON_RESET)) {
				break;
			}

			// Press button INC
			if (isButtonPressed(BUTTON_INC)) {
				state = COUNT_UP;

				// Increase 1 unit
				counter++;
				if (counter > 9) counter = 0;
			}

			// Press button DEC
			if (isButtonPressed(BUTTON_DEC)) {
				state = COUNT_DOWN;

				// Decrease 1 unit
				counter--;
				if (counter < 0) counter = 9;
			}

			break;

		case COUNT_UP:
			updateBuffer();

			// Press button RESET
			if (isButtonPressed(BUTTON_RESET)) {
				state = COUNT_RESET;

				// Set counter to 0
				counter = 0;
			}

			// Press button INC
			if (isButtonPressed(BUTTON_INC) || isButtonPressed3s(BUTTON_INC)) {
				// Increase 1 unit
				counter++;
				if (counter > 9) counter = 0;
			}

			// Press button DEC
			if (isButtonPressed(BUTTON_DEC)) {
				state = COUNT_DOWN;

				// Decrease 1 unit
				counter--;
				if (counter < 0) counter = 9;
			}

			// Button event after 10s
			if (isButtonTimeOut(BUTTON_INC)) {
				state = COUNT_AUTO;
				if (counter > 0) {
					counter--;
				}
			}

			break;

		case COUNT_DOWN:
			updateBuffer();

			// Press button RESET
			if (isButtonPressed(BUTTON_RESET)) {
				state = COUNT_RESET;

				// Set counter to 0
				counter = 0;
			}

			// Press button INC
			if (isButtonPressed(BUTTON_INC)) {
				state = COUNT_UP;

				// Increase 1 unit
				counter++;
				if (counter > 9) counter = 0;
			}

			// Press button DEC
			if (isButtonPressed(BUTTON_DEC) || isButtonPressed3s(BUTTON_DEC)) {
				// Decrease 1 unit
				counter--;
				if (counter < 0) counter = 9;
			}

			// Button event after 10s
			if (isButtonTimeOut(BUTTON_DEC)) {
				state = COUNT_AUTO;
				if (counter > 0) {
					counter--;
				}
			}

			break;

		case COUNT_AUTO:
			updateBuffer();

			//Press button RESET
			if (isButtonPressed(BUTTON_RESET)) {
				state = COUNT_RESET;

				// Set counter to 0
				counter = 0;
				break;
			}

			// Press button INC
			if (isButtonPressed(BUTTON_INC)) {
				state = COUNT_UP;

				// Increase 1 unit
				counter++;
				if (counter > 9) counter = 0;
				break;
			}

			// Press button DEC
			if (isButtonPressed(BUTTON_DEC)) {
				state = COUNT_DOWN;

				// Decrease 1 unit
				counter--;
				if (counter < 0) counter = 9;
				break;
			}

			// Button event after 10s, count down every 1s
			if (isTimerUp(1)) {
				if (counter > 0) {
					counter--;
					setTimer(1, timerForCountAuto);
				}
			}

			break;

		default:
			break;
	}
}
