/*
 * pid_control.h
 *
 *  Created on: Feb 18, 2023
 *      Author: tomas
 */

#ifndef INC_PID_CONTROL_H_
#define INC_PID_CONTROL_H_

#include "main.h"
#include "stdlib.h"

typedef struct {
  float Kp;        // Proportional gain
  float Ki;        // Integral gain
  float Kd;        // Derivative gain
  float N;         // Derivative filter constant
  float Ts;        // Sample time [s]
  float e_prev;    // Previous input (control error)
  float e_int;     // Input integral
  float d_prev;    // Previous derivative
  float LimitUpper;     // Output upper saturation
  float LimitLower;     // Output lower saturation
} PID_HandleTypeDef;


void PID_Init(PID_HandleTypeDef* hpid);

float PID_GET_SIGNAL(PID_HandleTypeDef* hpid, float yref, float v, float current_error);

#endif /* INC_PID_CONTROL_H_ */
