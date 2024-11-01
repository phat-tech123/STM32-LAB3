/*
 * traffic_light.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#include "traffic_light.h"

void turn_red();
void turn_green();
void turn_yellow();
void turn_red_2();
void turn_green_2();
void turn_yellow_2();

int new = 0;
int status = INIT;
int led_buffer[4] = {0};
void automatic_traffic_light_run(){
	switch(status){
	case INIT:
		status = RED1_GREEN;
		setTimer(1, 3000);
		setTimer(2, 1000);
		setTimer(3, 250);
		led_buffer[1] = 4;
		led_buffer[3] = 2;
		new = 1;
		break;
	case RED1_GREEN:
		if(new == 1){
			turn_red();
			turn_green_2();
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
}


void turn_red(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
}
void turn_green(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
}
void turn_yellow(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
}
void turn_red_2(){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}
void turn_green_2(){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
}
void turn_yellow_2(){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
}
