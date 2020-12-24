/*
 * AMIT Project Microcontroller 1.c
 *
 * Created: 12/24/2020 5:41:26 PM
 * Author : mahmo
 */ 

#define  F_CPU    8000000
#include <util/delay.h>
#include "UART.h"
#include "SPI.h"
#include "LCD.h"


int main(void)
{
    uint8 data_uart = 0;
	
	UART_Init();
	SPI_Master_Init();
	SPI_Master_Init_Trans();
	LCD_Init();
	_delay_ms(1000);
	
    while (1) 
    {
	   
		data_uart = UART_Rx();
		
		_delay_ms(1000);
		
		if(data_uart)
		{
			SPI_Transiver(data_uart);
			LCD_WriteChar(data_uart);  // to display the data came from bluetooth
			                           //    Before Sent it to Another Microcontroller bt SPI 
		
			
		}
		_delay_ms(1000);

    }
}


