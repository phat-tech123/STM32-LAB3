/*
 * traffic_light.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "global.h"

/* 	FOR AUTOMATIC AND MANUAL	*/
void turn_red();
void turn_green();
void turn_yellow();
void turn_red_2();
void turn_green_2();
void turn_yellow_2();
void clear_light();

/*	FOR SETTING	*/
void toggleRed();
void toggleYellow();
void toggleGreen();

#endif /* INC_TRAFFIC_LIGHT_H_ */
