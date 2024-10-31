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

int TimeOutForKeyPress[3] = {200,200,200};	//Time for PRESS_OVER
int button_flag[3] = {0};			//Flag for button signal

int pressType[3] = {ZERO, ZERO, ZERO};

void getKeyInput1();
void getKeyInput2();
void getKeyInput3();



void getKeyInput(){
	for(int i=0; i<3; i++){
		switch(i){
		case 0:
			getKeyInput1();
			break;
		case 1:
			getKeyInput2();
			break;
		case 2:
			getKeyInput3();
			break;
		default:
			break;
		}
	}
}


void getKeyInput1() {
    // BUTTON 1
    switch(pressType[0]) {
    case ZERO:
        if (HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == NORMAL_STATE) {
            return;
        }
        pressType[0] = PRESS_RELEASE_1;
        break;
    case PRESS_RELEASE_1:
        if (HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == NORMAL_STATE) {
            pressType[0] = ZERO;
            return;
        }
        pressType[0] = PRESS_RELEASE_2;
        break;
    case PRESS_RELEASE_2:
        if (HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == NORMAL_STATE) {
            pressType[0] = ZERO;
            return;
        }
        button_flag[0] = 1;
        pressType[0] = PRESS_OVER;
        TimeOutForKeyPress[0] = 200;
        break;
    case PRESS_OVER:
        --TimeOutForKeyPress[0];
        if (TimeOutForKeyPress[0] == 0) {
            TimeOutForKeyPress[0] = 200;
            button_flag[0] = 1;
        }
        if (HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == NORMAL_STATE) {
            pressType[0] = ZERO;
        }
        break;
    default:
        break;
    }
}

void getKeyInput2(){
    // BUTTON 2
    switch(pressType[1]) {
    case ZERO:
        if (HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin) == NORMAL_STATE) {
            return;
        }
        pressType[1] = PRESS_RELEASE_1;
        break;
    case PRESS_RELEASE_1:
        if (HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin) == NORMAL_STATE) {
            pressType[1] = ZERO;
            return;
        }
        pressType[1] = PRESS_RELEASE_2;
        break;
    case PRESS_RELEASE_2:
        if (HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin) == NORMAL_STATE) {
            pressType[1] = ZERO;
            return;
        }
        button_flag[1] = 1;
        pressType[1] = PRESS_OVER;
        TimeOutForKeyPress[1] = 200;
        break;
    case PRESS_OVER:
        --TimeOutForKeyPress[1];
        if (TimeOutForKeyPress[1] == 0) {
            TimeOutForKeyPress[1] = 200;
            button_flag[1] = 1;
        }
        if (HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin) == NORMAL_STATE) {
            pressType[1] = ZERO;
        }
        break;
    default:
        break;
    }
}

void getKeyInput3(){
    // BUTTON 3
    switch(pressType[2]) {
    case ZERO:
        if (HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin) == NORMAL_STATE) {
            return;
        }
        pressType[2] = PRESS_RELEASE_1;
        break;
    case PRESS_RELEASE_1:
        if (HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin) == NORMAL_STATE) {
            pressType[2] = ZERO;
            return;
        }
        pressType[2] = PRESS_RELEASE_2;
        break;
    case PRESS_RELEASE_2:
        if (HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin) == NORMAL_STATE) {
            pressType[2] = ZERO;
            return;
        }
        button_flag[2] = 1;
        pressType[2] = PRESS_OVER;
        TimeOutForKeyPress[2] = 200;
        break;
    case PRESS_OVER:
        --TimeOutForKeyPress[2];
        if (TimeOutForKeyPress[2] == 0) {
            TimeOutForKeyPress[2] = 200;
            button_flag[2] = 1;
        }
        if (HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin) == NORMAL_STATE) {
            pressType[2] = ZERO;
        }
        break;
    default:
        break;
    }
}


//void getKeyInput() {
//    // BUTTON 1
//    switch(pressType[0]) {
//    case ZERO:
//        if (HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == NORMAL_STATE) {
//            return;
//        }
//        pressType[0] = PRESS_RELEASE_1;
//        break;
//    case PRESS_RELEASE_1:
//        if (HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == NORMAL_STATE) {
//            pressType[0] = ZERO;
//            return;
//        }
//        pressType[0] = PRESS_RELEASE_2;
//        break;
//    case PRESS_RELEASE_2:
//        if (HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == NORMAL_STATE) {
//            pressType[0] = ZERO;
//            return;
//        }
//        button_flag[0] = 1;
//        pressType[0] = PRESS_OVER;
//        TimeOutForKeyPress[0] = 200;
//        break;
//    case PRESS_OVER:
//        --TimeOutForKeyPress[0];
//        if (TimeOutForKeyPress[0] == 0) {
//            TimeOutForKeyPress[0] = 200;
//            button_flag[0] = 1;
//        }
//        if (HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin) == NORMAL_STATE) {
//            pressType[0] = ZERO;
//        }
//        break;
//    default:
//        break;
//    }
//
//    // BUTTON 2
//    switch(pressType[1]) {
//    case ZERO:
//        if (HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin) == NORMAL_STATE) {
//            return;
//        }
//        pressType[1] = PRESS_RELEASE_1;
//        break;
//    case PRESS_RELEASE_1:
//        if (HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin) == NORMAL_STATE) {
//            pressType[1] = ZERO;
//            return;
//        }
//        pressType[1] = PRESS_RELEASE_2;
//        break;
//    case PRESS_RELEASE_2:
//        if (HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin) == NORMAL_STATE) {
//            pressType[1] = ZERO;
//            return;
//        }
//        button_flag[1] = 1;
//        pressType[1] = PRESS_OVER;
//        TimeOutForKeyPress[1] = 200;
//        break;
//    case PRESS_OVER:
//        --TimeOutForKeyPress[1];
//        if (TimeOutForKeyPress[1] == 0) {
//            TimeOutForKeyPress[1] = 200;
//            button_flag[1] = 1;
//        }
//        if (HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin) == NORMAL_STATE) {
//            pressType[1] = ZERO;
//        }
//        break;
//    default:
//        break;
//    }
//}



