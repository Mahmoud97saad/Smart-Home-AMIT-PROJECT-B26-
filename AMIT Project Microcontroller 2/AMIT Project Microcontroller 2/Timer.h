/*
 * Timer.h
 *
 * Created: 11/13/2020 5:21:54 PM
 *  Author: mahmo
 */ 


#ifndef TIMER_H_
#define TIMER_H_

//#include "ATmega32_Regiosters.h"
//#include "BIT_Math.h"
#include "Project_cfg.h"

void Timer0_Init(void);

void Timer0_Start(void);

void Timer0_Stop(void);

void Timer0_SetDelay(uint32 Delay_ms );

/*void Timer1_Init(void);

void Timer1_Start(void);

void Timer1_Stop(void);

void Timer1_SetDelay(uint32 Delay_ms );

void PWN0_Init(void);

void PWN0_StartDutyCycle(uint8 Duty_Cycle);

void PWN0_Start(void);*/






#endif /* TIMER_H_ */