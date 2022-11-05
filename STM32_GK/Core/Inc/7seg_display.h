/*
 * 7seg_display.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#ifndef INC_7SEG_DISPLAY_H_
#define INC_7SEG_DISPLAY_H_

#include "global.h"

#define PORT_7SEG			GPIOB
#define SEG_ON				GPIO_PIN_RESET
#define SEG_OFF				GPIO_PIN_SET

void update7SEG();
void updateBuffer();

#endif /* INC_7SEG_DISPLAY_H_ */
