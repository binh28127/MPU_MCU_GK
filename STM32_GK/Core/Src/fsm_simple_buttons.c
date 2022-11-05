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

			// Press button INC
			if (isButtonPressed(BUTTON_INC)) {
				state = COUNT_UP;

				// Increase 1 unit
				counter++;
				if (counter >= 10) counter = 0;
			}

			// Press button DEC
			if (isButtonPressed(BUTTON_DEC)) {
				state = COUNT_DOWN;

				// Decrease 1 unit
				counter--;
				if (counter <= 0) counter = 9;
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
			if (isButtonPressed(BUTTON_INC)) {
				// Increase 1 unit
				counter++;
				if (counter >= 10) counter = 0;
			}

			// Press button DEC
			if (isButtonPressed(BUTTON_DEC)) {
				state = COUNT_DOWN;

				// Decrease 1 unit
				counter--;
				if (counter <= 0) counter = 9;
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
				if (counter >= 10) counter = 0;
			}

			if (isButtonPressed(BUTTON_DEC)) {
				// Decrease 1 unit
				counter--;
				if (counter <= 0) counter = 9;
			}

			break;

		default:
			break;
	}
}
