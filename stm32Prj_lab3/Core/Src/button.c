/*
 * button.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Admin
 */

#include "button.h"

#define NoPress 0
#define PressRelease 1
#define PressOver 2

//3 key reg for avoiding vibrate
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

//Normal state before
int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  200;	//Time for PressOver
int button1_flag = 0;			//Flag for button signal

void getKeyInput(){
	KeyReg2 = KeyReg1;
	KeyReg1 = KeyReg0;
	KeyReg0 = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){	//Case PressRelease
			KeyReg3 = KeyReg2;
			if(KeyReg3 == PRESSED_STATE){
				TimeOutForKeyPress = 200;
				button1_flag = 1;
			}
		}else{	//Case PressOver
			TimeOutForKeyPress--;
			if(TimeOutForKeyPress == 0){
				TimeOutForKeyPress = 200;
				if(KeyReg3 == PRESSED_STATE){
					button1_flag = 1;
				}
			}
		}
	}
}

int typePress = NoPress;
void getKeyInput(){
	KeyReg2 = KeyReg1;
	KeyReg1 = KeyReg0;
	KeyReg0 = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){

	}
}
