/*
 * fsm_automatic.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#include "fsm_automatic.h"

int status = INIT;
void fsm_automatic_run(){
	switch(status){
	case INIT:
		status = RED1_GREEN;
		setTimer(1, 3000);
		setTimer(2, 1000);
		setTimer(3, 250);
		New = 1;
		break;
	case RED1_GREEN:
		//When just turn status
		if(New == 1){
			turn_red();
			turn_green_2();
			led_buffer[1] = red_time - 1;
			led_buffer[3] = green_time -1;
			New = 0;
		}

		//COUNTDOWN TRAFFIC LIGHTS
		if(timer_flag[1] == 1){
			led_buffer[3] = 1;
			status = RED1_YELLOW;
			New = 1;
			setTimer(1, 2000);
		}

		//7-SEGMENT LEDS
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

		//SETTING TRAFFIC LIGHTS
		if(button_flag[0] == 1){
			button_flag[0] = 0;
			New = 1;
			clearLed();
			clear_light();
			setTimer(3, 250);
			setTimer(4, 500);
			status = RED_SETTING;
		}
		break;
	case RED1_YELLOW:
		//When just turn status
		if(New == 1){
			turn_yellow_2();
			led_buffer[3] = yellow_time - 1;
			New = 0;
		}

		//COUNTDOWN TRAFFIC LIGHTS
		if(timer_flag[1] == 1){
			led_buffer[1] = 2;
			led_buffer[3] = 4;
			status = RED2_GREEN;
			New = 1;
			setTimer(1, 3000);
		}

		//7-SEGMENT LEDS
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

		//SETTING TRAFFIC LIGHTS
		if(button_flag[0] == 1){
			button_flag[0] = 0;
			New = 1;
			clearLed();
			clear_light();
			setTimer(3, 250);
			setTimer(4, 500);
			status = RED_SETTING;
		}
		break;
	case RED2_GREEN:
		//When just turn status
		if(New == 1){
			turn_red_2();
			turn_green();
			led_buffer[3] = red_time - 1;
			led_buffer[1] = green_time -1;
			New = 0;
		}

		//COUNTDOWN TRAFFIC LIGHTS
		if(timer_flag[1] == 1){
			led_buffer[1] = 1;
			status = RED2_YELLOW;
			New = 1;
			setTimer(1, 2000);
		}

		//7-SEGMENT LEDS
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

		//SETTING TRAFFIC LIGHTS
		if(button_flag[0] == 1){
			button_flag[0] = 0;
			New = 1;
			clearLed();
			clear_light();
			setTimer(3, 250);
			setTimer(4, 500);
			status = RED_SETTING;
		}
		break;
	case RED2_YELLOW:
		//When just turn status
		if(New == 1){
			turn_yellow();
			led_buffer[1] = yellow_time - 1;
			New = 0;
		}

		//COUNTDOWN TRAFFIC LIGHTS
		if(timer_flag[1] == 1){
			status = RED1_GREEN;
			New = 1;
			setTimer(1, 3000);
		}

		//7-SEGMENT LEDS
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

		//SETTING TRAFFIC LIGHTS
		if(button_flag[0] == 1){
			button_flag[0] = 0;
			New = 1;
			clearLed();
			clear_light();
			setTimer(3, 250);
			setTimer(4, 500);
			status = RED_SETTING;
		}
		break;
	default:
		break;
	}
}






