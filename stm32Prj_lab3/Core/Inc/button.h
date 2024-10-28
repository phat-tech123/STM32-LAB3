/*
 * button.h
 *
 *  Created on: Oct 3, 2024
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void getKeyInput();

extern int button_flag[3];

#endif /* INC_BUTTON_H_ */
