/*
 * software_timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "software_timer.h"

int timer_counter[NO_OF_TIMERS];
int timer_flag[NO_OF_TIMERS];

int currentCounter(int timer) {
	return timer_counter[timer];
}

int isTimerUp(int timer) {
	return (timer_flag[timer] == 1);
}

void setTimer(int timer, int duration){
	timer_counter[timer] = duration / timerCycle;
	timer_flag[timer] = 0;
}
void timerRun(){
	for (int timer = 0; timer < NO_OF_TIMERS; timer++) {
		if(timer_counter[timer] > 0){
			timer_counter[timer]--;
			if(timer_counter[timer] == 0) {
				timer_flag[timer] = 1;
			}
		}
	}
}
