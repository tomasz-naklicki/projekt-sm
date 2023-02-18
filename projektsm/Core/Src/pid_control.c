/*
 * pid_control.c
 *
 *  Created on: Feb 18, 2023
 *      Author: tomas
 */


#include "pid_control.h"

void PID_Init(PID_HandleTypeDef* hpid){
	hpid->e_prev = 0.0f;
	hpid->e_int = 0.0f;
	hpid->d_prev = 0.0f;
}

float PID_GET_SIGNAL(PID_HandleTypeDef* hpid, float yref, float v, float current_error){
	float u;
	float u_sat;
	float e = yref + v* hpid->Ts;

	/*Integral*/
	hpid->e_int += hpid->Ki * hpid->Ts * e;


	/*Derivative*/
	hpid->d_prev = (hpid->Kd * hpid->N) * (e - hpid->e_prev) + (1.0f - hpid->N * hpid->Ts) * hpid->d_prev;
	hpid->e_prev = e;

	/*Output"*/
	u = (hpid->Kp * e) + hpid->e_int + hpid->d_prev;

	/*Saturation*/
	if(u > hpid->LimitUpper) u_sat = hpid->LimitUpper;
	else if(u < hpid->LimitLower) u_sat = hpid->LimitLower;
	else u_sat = u;

	/*Anti wind-up*/
	if(u != u_sat) hpid->e_int -= hpid->Ki * hpid->Ts * e;

	//if(current_error<=0) return abs((u_sat+34.0f)/0.7);
	//else return -((abs(u_sat)+34.0f)/0.7);
	if(current_error>=0) return -(abs(u_sat)+34)/0.7;
	else return (u_sat+34)/0.7;
}
