/*
 * global.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "fsm_automatic.h"

#define INIT			0
#define RED1_GREEN		1
#define RED1_YELLOW		2
#define RED2_GREEN		3
#define RED2_YELLOW		4

extern int status;

extern int led_buffer[4];


#endif /* INC_GLOBAL_H_ */
