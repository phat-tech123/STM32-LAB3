/*
 * button.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Admin
 */

#include "button.h"

#define ZERO 				0
#define PRESS_RELEASE_1 	1
#define PRESS_RELEASE_2 	2
#define PRESS_RELEASE_3 	3
#define PRESS_OVER   		4

int TimeOutForKeyPress =  200;	//Time for PRESS_OVER
int button1_flag = 0;			//Flag for button signal

int pressType = ZERO;
void getKeyInput(){
	switch(pressType){
	case ZERO:
		if(HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == NORMAL_STATE){
			return;
		}
		pressType = PRESS_RELEASE_1;
		break;
	case PRESS_RELEASE_1:
		if(HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == NORMAL_STATE){
			pressType = ZERO;
			return;
		}
		pressType = PRESS_RELEASE_2;
		break;
	case PRESS_RELEASE_2:
		if(HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == NORMAL_STATE){
			pressType = ZERO;
			return;
		}
		button1_flag = 1;
		pressType = PRESS_OVER;
		TimeOutForKeyPress = 200;
		break;
	case PRESS_OVER:
		--TimeOutForKeyPress;
		if(TimeOutForKeyPress == 0){
			TimeOutForKeyPress = 200;
			button1_flag = 1;
		}
		if(HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == NORMAL_STATE){
			pressType = ZERO;
		}
	default:
		break;
	}
}
