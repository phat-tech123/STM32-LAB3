/*
 * fsm_setting.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */


#include "fsm_setting.h"

void fsm_setting_run(){
//	if(status == RED_SETTING || status == YELLOW_SETTING || status == GREEN_SETTING){
//		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
//		setTimer(3, 500);
//	}

	switch(status){
	case INIT_SETTING:
		status = RED_SETTING;
		setTimer(3, 500);
		break;
	case RED_SETTING:
		//LED ON
		if(timer_flag[3] == 1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
			setTimer(3, 500);
		}
		break;
	case YELLOW_SETTING:
		//LED ON
		if(timer_flag[3] == 1){
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);
			setTimer(3, 500);
		}
		break;
	case GREEN_SETTING:
		//LED ON
		if(timer_flag[3] == 1){
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
			setTimer(3, 500);
		}
		break;
	default:
		break;
	}
}
