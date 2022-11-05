/*
 * button_reading.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#ifndef INC_BUTTON_READING_H_
#define INC_BUTTON_READING_H_

#include "global.h"
#include "main.h"

#define BUTTON_IS_RELEASED		0
#define BUTTON_IS_PRESSED		1
#define BUTTON_IS_PRESSED_3s	2

int isButtonPressed(int button);
int isButtonPressed3s(int button);
void getKeyInput();

#endif /* INC_BUTTON_READING_H_ */
