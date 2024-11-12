/*
 * fsm_automatic.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#include "fsm_automatic.h"

int status = INIT;
int tmp_red_time;
int tmp_green_time;
int tmp_yellow_time;

void fsm_automatic_run(){
	switch(status){
	case INIT:
		//when something wrong
		if((green_time + yellow_time) != red_time){
			green_time = red_time - yellow_time;
		}

		tmp_red_time = red_time - 1;
		tmp_green_time = green_time - 1;
		tmp_yellow_time = yellow_time - 1;

		setTimer(1, green_time*1000);
		setTimer(2, 1000);
		setTimer(3, 250);
		New = 1;
		status = RED1_GREEN;
		break;
	case RED1_GREEN:
		//When just turn status
		if(New == 1){
			turn_red();
			turn_green_2();
			led_buffer[0] = tmp_red_time / 10;
			led_buffer[1] = tmp_red_time % 10;
			led_buffer[2] = tmp_green_time / 10;
			led_buffer[3] = tmp_green_time % 10;
			New = 0;
		}

		//COUNTDOWN TRAFFIC LIGHTS
		if(timer_flag[1] == 1){
			status = RED1_YELLOW;
			New = 1;
			setTimer(1, yellow_time*1000);
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
			if(led_buffer[3] < 0){
				led_buffer[3] = 9;
				led_buffer[2]--;
			}
			led_buffer[1]--;
			if(led_buffer[1] < 0){
				led_buffer[1] = 9;
				led_buffer[0]--;
			}
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

		//MANUAL TRAFFIC LIGHTS
		if(button_flag[1] == 1){
			New = 1;
			button_flag[1] = 0;
			clearLed();
			clear_light();
			status = RED_MAN;
		}
		break;
	case RED1_YELLOW:
		//When just turn status
		if(New == 1){
			turn_yellow_2();
			led_buffer[2] = tmp_yellow_time / 10;
			led_buffer[3] = tmp_yellow_time % 10;
			New = 0;
		}

		//COUNTDOWN TRAFFIC LIGHTS
		if(timer_flag[1] == 1){
			status = RED2_GREEN;
			New = 1;
			setTimer(1, green_time*1000);
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
			if(led_buffer[3] < 0){
				led_buffer[3] = 9;
				led_buffer[2]--;
			}
			led_buffer[1]--;
			if(led_buffer[1] < 0){
				led_buffer[1] = 9;
				led_buffer[0]--;
			}
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

		//MANUAL TRAFFIC LIGHTS
		if(button_flag[1] == 1){
			New = 1;
			button_flag[1] = 0;
			clearLed();
			clear_light();
			New = 1;
			status = RED_MAN;
		}
		break;
	case RED2_GREEN:
		//When just turn status
		if(New == 1){
			turn_red_2();
			turn_green();
			led_buffer[2] = tmp_red_time / 10;
			led_buffer[3] = tmp_red_time % 10;
			led_buffer[0] = tmp_green_time / 10;
			led_buffer[1] = tmp_green_time % 10;
			New = 0;
		}

		//COUNTDOWN TRAFFIC LIGHTS
		if(timer_flag[1] == 1){
			status = RED2_YELLOW;
			New = 1;
			setTimer(1, yellow_time*1000);
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
			if(led_buffer[3] < 0){
				led_buffer[3] = 9;
				led_buffer[2]--;
			}
			led_buffer[1]--;
			if(led_buffer[1] < 0){
				led_buffer[1] = 9;
				led_buffer[0]--;
			}
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

		//MANUAL TRAFFIC LIGHTS
		if(button_flag[1] == 1){
			New = 1;
			button_flag[1] = 0;
			clearLed();
			clear_light();
			New = 1;
			status = RED_MAN;
		}
		break;
	case RED2_YELLOW:
		//When just turn status
		if(New == 1){
			turn_yellow();
			led_buffer[0] = tmp_yellow_time / 10;
			led_buffer[1] = tmp_yellow_time % 10;
			New = 0;
		}

		//COUNTDOWN TRAFFIC LIGHTS
		if(timer_flag[1] == 1){
			status = RED1_GREEN;
			New = 1;
			setTimer(1, green_time*1000);
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
			if(led_buffer[3] < 0){
				led_buffer[3] = 9;
				led_buffer[2]--;
			}
			led_buffer[1]--;
			if(led_buffer[1] < 0){
				led_buffer[1] = 9;
				led_buffer[0]--;
			}
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

		//MANUAL TRAFFIC LIGHTS
		if(button_flag[1] == 1){
			New = 1;
			button_flag[1] = 0;
			clearLed();
			clear_light();
			setTimer(3, 250);
			status = RED_MAN;
		}
		break;
	default:
		break;
	}
}
