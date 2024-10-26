/*
 * button.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Admin
 */

#include "button.h"

#define NO_PRESS 0
#define PRESS_RELEASE 1
#define PRESS_OVER 2

//3 keyreg for avoiding vibrate
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

//Normal state before
int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  200;	//Time for PRESS_OVER
int button1_flag = 0;			//Flag for button signal

//void getKeyInput(){
//	KeyReg0 = KeyReg1;
//	KeyReg1 = KeyReg2;
//	KeyReg2 = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
//	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
//		if(KeyReg3 != KeyReg2){	//Case PRESS_RELEASE
//			KeyReg3 = KeyReg2;
//			if(KeyReg3 == PRESSED_STATE){
//				TimeOutForKeyPress = 200;
//				button1_flag = 1;
//			}
//		}else{	//Case PRESS_OVER
//			TimeOutForKeyPress--;
//			if(TimeOutForKeyPress == 0){
//				TimeOutForKeyPress = 200;
//				if(KeyReg3 == PRESSED_STATE){
//					button1_flag = 1;
//				}
//			}
//		}
//	}
//}

int pressType = NO_PRESS;
void getKeyInput(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		switch(pressType){
		case NO_PRESS:
			if(KeyReg3 != KeyReg2){
				KeyReg3 = KeyReg2;
				pressType = PRESS_RELEASE;
			}else{
				pressType = PRESS_OVER;
			}

			if(KeyReg3 == NORMAL_STATE){
				pressType = NO_PRESS;
			}
			break;
		case PRESS_RELEASE:
				TimeOutForKeyPress = 200;
				button1_flag = 1;
				pressType = NO_PRESS;
			break;
		case PRESS_OVER:
			TimeOutForKeyPress--;
			if(TimeOutForKeyPress == 0){
				TimeOutForKeyPress = 200;
				button1_flag = 1;
				pressType = NO_PRESS;
			}
			break;
		default:
			break;
		}
	}
}
