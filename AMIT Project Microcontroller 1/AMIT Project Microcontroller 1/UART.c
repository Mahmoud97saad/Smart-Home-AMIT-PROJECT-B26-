/*
 * UART.c
 *
 * Created: 12/17/2020 11:24:17 PM
 *  Author: mahmo
 */ 
#include "UART.h"



void UART_Init(void)
{
	uint32 BR_Value = 0 ;
	DIO_SetPinDir(TX_PORT , TX_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(RX_PORT , RX_PIN , DIO_PIN_INPUT);
	
	BR_Value = ((FREQ) / (16 *(Desired_BR))) - 1;
	
	UBRRL = BR_Value;
	//enable RX & TX
	SET_BIT(UCSRB , 3);
	SET_BIT(UCSRB , 4);
	// disable parity & chosse one stop bit & how much bits data consists of
	UCSRC = 0x86 ;
	
	
}

void UART_Tx(uint8 data)
{
	UDR = data;
	while (GET_BIT(UCSRA , 5) == 0);
}

void UART_TxString(uint8* str)
{
	uint8 i = 0;
	
	while(str[i] != '\0')
	{
		UART_Tx(str[i]);
		i++;
	}
}

uint8 UART_Rx(void)
{
	while (GET_BIT(UCSRA , 7) == 0);
	
	return UDR;
}