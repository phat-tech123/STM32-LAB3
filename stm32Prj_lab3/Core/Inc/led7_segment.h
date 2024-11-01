/*
 * led7_segment.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

#include "global.h"


extern int led_buffer[4];

void display7SEG(int num);
void update7SEG(int index);
void enableLed(int index);


#endif /* INC_LED7_SEGMENT_H_ */
