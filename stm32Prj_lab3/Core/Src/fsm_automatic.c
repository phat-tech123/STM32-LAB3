/*
 * fsm_automatic.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#include "fsm_automatic.h"


int idx = 0;

void fsm_automatic_run(){

	 if(idx == 4){
	 	idx = 0;
	 }
	 if(timer_flag[3] == 1){
		 update7SEG(idx++);
		 setTimer(3,250);
	 }
	 if(timer_flag[2] == 1){
		 led_buffer[3]--;
		 led_buffer[1]--;
		 setTimer(2, 1000);
	 }
	 automatic_traffic_light_run();
}






