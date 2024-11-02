/*
 * fsm_automatic.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#include "fsm_automatic.h"


int idx = 0;

int new = 0;
int status = INIT;
int led_buffer[4] = {0};
void fsm_automatic_run(){
	if(idx == 4){
		idx = 0;
	}
	if(timer_flag[3] == 1){
		update7SEG(idx++);
		setTimer(3,250);
	}
	if(timer_flag[2] == 1){
		led_buffer[3]--;
		led_buffer[1]--;
		setTimer(2, 1000);
	}
	switch(status){
	case INIT:
		status = RED1_GREEN;
		setTimer(1, 3000);
		setTimer(2, 1000);
		setTimer(3, 250);
		new = 1;
		break;
	case RED1_GREEN:
		if(new == 1){
			turn_red();
			turn_green_2();
			led_buffer[1] = 4;
			led_buffer[3] = 2;
			new = 0;
		}
		if(timer_flag[1] == 1){
			led_buffer[3] = 1;
			status = RED1_YELLOW;
			new = 1;
			setTimer(1, 2000);
		}
		break;
	case RED1_YELLOW:
		if(new == 1){
			turn_yellow_2();
			led_buffer[3] = 1;
			new = 0;
		}
		if(timer_flag[1] == 1){
			led_buffer[1] = 2;
			led_buffer[3] = 4;
			status = RED2_GREEN;
			new = 1;
			setTimer(1, 3000);
		}
		break;
	case RED2_GREEN:
		if(new == 1){
			turn_red_2();
			turn_green();
			led_buffer[3] = 4;
			led_buffer[1] = 2;
			new = 0;
		}
		if(timer_flag[1] == 1){
			led_buffer[1] = 1;
			status = RED2_YELLOW;
			new = 1;
			setTimer(1, 2000);
		}
		break;
	case RED2_YELLOW:
		if(new == 1){
			turn_yellow();
			led_buffer[1] = 1;
			new = 0;
		}
		if(timer_flag[1] == 1){
			status = RED1_GREEN;
			new = 1;
			setTimer(1, 3000);
		}
		break;
	default:
		break;
	}

	if(button_flag[0] == 1){
		status = MAN_RED;
	}

}






