/*
 * fsm_setting.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */


#include "fsm_setting.h"

void fsm_setting_run(){
	if(idx == 4){
		idx = 0;
	}
	if(timer_flag[3] == 1){
		update7SEG(idx++);
		setTimer(3,250);
	}
	switch(status){
	case RED_SETTING:
		//When just turn status
		if(New == 1){
			led_buffer[3] = mode2;
			led_buffer[1] = red_time;
			New = 0;
		}

		//TOGGLE PARTICULAR RED LIGHTS
		if(timer_flag[4] == 1){
			setTimer(4, 500);
			toggleRed();
		}

		//INCREASE TIME DURATION
		if(button_flag[1] == 1){
			button_flag[1] = 0;
			HAL_GPIO_TogglePin(test_button_GPIO_Port, test_button_Pin);
			++led_buffer[1];
		}
		if(led_buffer[1] >= 10){
			led_buffer[0]++;
			led_buffer[1] = 0;
		}
		if((led_buffer[0]*10 + led_buffer[1]) >= 100){
			led_buffer[0] = 9;
			led_buffer[1] = 9;
		}

		//SETTING TIME DURATION
		if(button_flag[2] == 1){
			button_flag[2] = 0;
			red_time = led_buffer[0]*10 + led_buffer[1];
			HAL_GPIO_TogglePin(test_button_GPIO_Port, test_button_Pin);
		}

		//FIX
		if(red_time >= 100){
			red_time = 99;
			led_buffer[0] = 9;
			led_buffer[1] = 9;
		}

		//CHANGE STATUS
		if(button_flag[0] == 1){
			button_flag[0] = 0;
			clearLed();
			clear_light();
			setTimer(3, 250);
			setTimer(4, 500);
			New = 1;
			status = YELLOW_SETTING;
		}
		break;
	case YELLOW_SETTING:
		//When just turn status
		if(New == 1){
			led_buffer[3] = mode3;
			led_buffer[1] = yellow_time;
			New = 0;
		}

		//TOGGLE PARTICULAR RED LIGHTS
		if(timer_flag[4] == 1){
			setTimer(4, 500);
			toggleYellow();
		}

		//INCREASE TIME DURATION
		if(button_flag[1] == 1){
			button_flag[1] = 0;
			HAL_GPIO_TogglePin(test_button_GPIO_Port, test_button_Pin);
			++led_buffer[1];
		}
		if(led_buffer[1] >= 10){
			led_buffer[0]++;
			led_buffer[1] = 0;
		}
		if((led_buffer[0]*10 + led_buffer[1]) >= 100){
			led_buffer[0] = 9;
			led_buffer[1] = 9;
		}

		//SETTING TIME DURATION
		if(button_flag[2] == 1){
			button_flag[2] = 0;
			yellow_time = led_buffer[0]*10 + led_buffer[1];
		}

		//FIX
		if(yellow_time >= 100){
			yellow_time = 99;
			led_buffer[0] = 9;
			led_buffer[1] = 9;
		}

		//CHANGE STATUS
		if(button_flag[0] == 1){
			button_flag[0] = 0;
			clearLed();
			clear_light();
			setTimer(3, 250);
			setTimer(4, 500);
			New = 1;
			status = GREEN_SETTING;
		}
		break;
	case GREEN_SETTING:
		//When just turn status
		if(New == 1){
			led_buffer[3] = mode4;
			led_buffer[1] = green_time;
			New = 0;
		}

		//TOGGLE PARTICULAR RED LIGHTS
		if(timer_flag[4] == 1){
			setTimer(4, 500);
			toggleGreen();
		}

		//INCREASE TIME DURATION
		if(button_flag[1] == 1){
			button_flag[1] = 0;
			HAL_GPIO_TogglePin(test_button_GPIO_Port, test_button_Pin);
			++led_buffer[1];
		}
		if(led_buffer[1] >= 10){
			led_buffer[0]++;
			led_buffer[1] = 0;
		}
		if((led_buffer[0]*10 + led_buffer[1]) >= 100){
			led_buffer[0] = 9;
			led_buffer[1] = 9;
		}

		//SETTING TIME DURATION
		if(button_flag[2] == 1){
			button_flag[2] = 0;
			green_time = led_buffer[0]*10 + led_buffer[1];
		}

		//FIX
		if(green_time >= 100){
			green_time = 99;
			led_buffer[0] = 9;
			led_buffer[1] = 9;
		}

		//CHANGE STATUS
		if(button_flag[0] == 1){
			button_flag[0] = 0;
			clearLed();
			clear_light();
			status = INIT;
		}
		break;
	default:
		break;
	}
}
