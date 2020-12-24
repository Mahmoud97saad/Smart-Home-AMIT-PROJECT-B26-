/*
 * UART.h
 *
 * Created: 12/17/2020 11:24:37 PM
 *  Author: mahmo
 */ 


#ifndef UART_H_
#define UART_H_

#include "ATmega32_Regiosters.h"
#include "BIT_Math.h"
#include "Project_cfg.h"

void UART_Init(void);

void UART_Tx(uint8 data);

void UART_TxString(uint8* str);

uint8 UART_Rx(void);





#endif /* UART_H_ */