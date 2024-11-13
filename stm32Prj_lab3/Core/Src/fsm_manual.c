/*
 * fsm_manual.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */


#include "fsm_manual.h"


void fsm_manual_run(){
	switch(status){
	case RED_MAN:
		if(New == 1){
			New = 0;
			led_buffer[0] = led_buffer[2] = 0;
			led_buffer[1] = led_buffer[3] = 5;
		}

		//7-SEGMENT LEDS
		if(idx == 4){
			idx = 0;
		}
		if(timer_flag[3] == 1){
			update7SEG(idx++);
			setTimer(3,250);
		}

		turn_red();
		turn_red_2();
		if(button_flag[1] == 1){
			HAL_GPIO_TogglePin(test_button_GPIO_Port, test_button_Pin);
			New = 1;
			button_flag[1] = 0;
			clear_light();
			status = YELLOW_MAN;
		}
		if(button_flag[2] == 1){
			HAL_GPIO_TogglePin(test_button_GPIO_Port, test_button_Pin);
			button_flag[2] = 0;
			status = INIT;
		}
		break;
	case YELLOW_MAN:
		if(New == 1){
			New = 0;
			led_buffer[0] = led_buffer[2] = 0;
			led_buffer[1] = led_buffer[3] = 6;
		}

		//7-SEGMENT LEDS
		if(idx == 4){
			idx = 0;
		}
		if(timer_flag[3] == 1){
			update7SEG(idx++);
			setTimer(3,250);
		}

		turn_yellow();
		turn_yellow_2();
		if(button_flag[1] == 1){
			HAL_GPIO_TogglePin(test_button_GPIO_Port, test_button_Pin);
			New = 1;
			button_flag[1] = 0;
			clear_light();
			status = GREEN_MAN;
		}
		if(button_flag[2] == 1){
			HAL_GPIO_TogglePin(test_button_GPIO_Port, test_button_Pin);
			button_flag[2] = 0;
			status = INIT;
		}
		break;
	case GREEN_MAN:
		if(New == 1){
			New = 0;
			led_buffer[0] = led_buffer[2] = 0;
			led_buffer[1] = led_buffer[3] = 7;
		}

		//7-SEGMENT LEDS
		if(idx == 4){
			idx = 0;
		}
		if(timer_flag[3] == 1){
			update7SEG(idx++);
			setTimer(3,250);
		}

		turn_green();
		turn_green_2();
		if(button_flag[1] == 1){
			HAL_GPIO_TogglePin(test_button_GPIO_Port, test_button_Pin);
			New = 1;
			button_flag[1] = 0;
			clear_light();
			status = RED_MAN;
		}
		if(button_flag[2] == 1){
			HAL_GPIO_TogglePin(test_button_GPIO_Port, test_button_Pin);
			button_flag[2] = 0;
			status = INIT;
		}
		break;
	default:
		break;
	}

}
