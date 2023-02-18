/*
 * control.c
 *
 *  Created on: Feb 10, 2023
 *      Author: tomas
 */

#include "control.h"

void control_INIT(struct Controller* controller, float MAX_SIGNAL, float MIN_SIGNAL, float MAX_ERROR, float MIN_ERROR){
	controller->MAX_SIGNAL = MAX_SIGNAL;
	controller->MIN_SIGNAL = MIN_SIGNAL;
	controller->MAX_ERROR = MAX_ERROR;
	controller->MIN_ERROR = MIN_ERROR;
	controller->prev_error = 0;
	controller->prev_distance = 0;
	controller->current_velocity = 0;
}

float control_GET_SIGNAL(struct Controller* controller, float y, float y_ref){
	float error = y_ref - y;

	if(abs(error) <= controller->MIN_ERROR){
		return 0;
	}
	else if(abs(control_GET_VELOCITY(controller, y)) != 0 ){

		if(error >= controller->MAX_ERROR){
			return controller->MAX_SIGNAL;
		}
		else if(error <= -1*controller->MAX_ERROR){
			return controller->MAX_SIGNAL * -1;
		}
		else if(abs(error*10.0f) < controller->MIN_SIGNAL && error > 0){
			return controller->MIN_SIGNAL;
		}
		else if(abs(error*10.0f) < controller->MIN_SIGNAL && error<0){
			return controller->MIN_SIGNAL * -1;
		}

		return error*10.0f;
	}
	else if(error<0) return -controller->MAX_SIGNAL;
	else return controller->MAX_SIGNAL;

}


float control_GET_VELOCITY(struct Controller* controller, float distance){
	if(controller->prev_distance == 0) controller->prev_distance = distance;
	float velocity  = (distance-controller->prev_distance)/0.1;
	controller->prev_distance = distance;
	controller->current_velocity = velocity;
	return velocity;
}


