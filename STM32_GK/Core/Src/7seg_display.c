/*
 * 7seg_display.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "7seg_display.h"

int index_seg = 0;
int seg_buffer[NO_OF_7SEGS] = { 1, 2, 3, 4 };

void display7SEG(int num) {
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(PORT_7SEG, 0B0111111, SEG_ON);
			HAL_GPIO_WritePin(PORT_7SEG, 0B1000000, SEG_OFF);
			break;
		case 1:
			HAL_GPIO_WritePin(PORT_7SEG, 0B0000110, SEG_ON);
			HAL_GPIO_WritePin(PORT_7SEG, 0B1111001, SEG_OFF);
			break;
		case 2:
			HAL_GPIO_WritePin(PORT_7SEG, 0B1011011, SEG_ON);
			HAL_GPIO_WritePin(PORT_7SEG, 0B0100100, SEG_OFF);
			break;
		case 3:
			HAL_GPIO_WritePin(PORT_7SEG, 0B1001111, SEG_ON);
			HAL_GPIO_WritePin(PORT_7SEG, 0B0110000, SEG_OFF);
			break;
		case 4:
			HAL_GPIO_WritePin(PORT_7SEG, 0B1100110, SEG_ON);
			HAL_GPIO_WritePin(PORT_7SEG, 0B0011001, SEG_OFF);
			break;
		case 5:
			HAL_GPIO_WritePin(PORT_7SEG, 0B1101101, SEG_ON);
			HAL_GPIO_WritePin(PORT_7SEG, 0B0010010, SEG_OFF);
			break;
		case 6:
			HAL_GPIO_WritePin(PORT_7SEG, 0B1111101, SEG_ON);
			HAL_GPIO_WritePin(PORT_7SEG, 0B0000010, SEG_OFF);
			break;
		case 7:
			HAL_GPIO_WritePin(PORT_7SEG, 0B0000111, SEG_ON);
			HAL_GPIO_WritePin(PORT_7SEG, 0B1111000, SEG_OFF);
			break;
		case 8:
			HAL_GPIO_WritePin(PORT_7SEG, 0B1111111, SEG_ON);
			break;
		case 9:
			HAL_GPIO_WritePin(PORT_7SEG, 0B1101111, SEG_ON);
			HAL_GPIO_WritePin(PORT_7SEG, 0B0010000, SEG_OFF);
			break;
		default:
			HAL_GPIO_WritePin(PORT_7SEG, 0B1111111, SEG_OFF);
			break;
	}
}

void update7SEG(int index){
    switch (index){
        case 0:
            //Display the first 7SEG with led_buffer[0]
            display7SEG(seg_buffer[0]);
            break;
        case 1:
            //Display the second 7SEG with led_buffer[1]
            display7SEG(seg_buffer[1]);
            break;
        case 2:
            //Display the third 7SEG with led_buffer[2]
            display7SEG(seg_buffer[2]);
            break;
        case 3:
            //Display the forth 7SEG with led_buffer[3]
            display7SEG(seg_buffer[3]);
            break;
        default:
            break;
    }
}
