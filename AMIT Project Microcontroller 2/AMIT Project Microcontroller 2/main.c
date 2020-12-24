/*
 * AMIT Project Microcontroller 2.c
 *
 * Created: 12/24/2020 6:16:33 PM
 * Author : mahmo
 */ 




#define  F_CPU    8000000
#include "SPI.h"
#include "LCD.h"
#include "LED.h"
#include "Buzzer.h"
#include "Timer.h"
#include <avr/interrupt.h>
#include <util/delay.h>

extern uint32 NUM_OVF ;
extern uint32 Init_value;




int main(void)
{
	uint8 REC_DATA_SPI = 0;
	uint8 any_data = 1;
	uint8 LED_STATE = 0;
	uint8 BUZZER_STATE = 0;
	
	
	SPI_Slave_Init();
	LCD_Init();
	LED_Init();
	Buzzer_Init();
	Timer0_Init();
	Timer0_SetDelay(Disered_Time_Timer0);
	
	
	

	while (1)
	{
		REC_DATA_SPI = SPI_Transiver(any_data);
		
		switch(REC_DATA_SPI)
		{
			case '1' :
			if(LED_STATE == 0)
			{
				LCD_Clear();
				LED_Toggle();
				LCD_WriteString("Led  ON");
				LED_STATE = 1;
			}
			else
			{
				LCD_Clear();
				LED_Toggle();
				LCD_WriteString("Led  OFF");
				LED_STATE = 0;
			}
			
			break;
			
			case '2' :
			if(BUZZER_STATE == 0)
			{
				LCD_Clear();
				Buzzer_Start();
				LCD_WriteString("BUZZER is ON");
				BUZZER_STATE = 1;
			}
			else
			{
				LCD_Clear();
				Buzzer_Stop();
				LCD_WriteString("BUZZER is OFF");
				BUZZER_STATE = 0;
		    }
			
			break;
			
			case '3' :
			LCD_Clear();
			Timer0_Start();
			LCD_WriteString("Timer is Start");
			
			break;
			
			case '4' :
			LCD_Clear();
			Timer0_Stop();
			LCD_WriteString("Timer is Stop");
			
			break;	
			
			default:
			break;
			
		}
	}
}






ISR (TIMER0_OVF_vect)
{
	static uint32 cnt = 0;
	
	cnt++;
	
	if (cnt == NUM_OVF)
	{
		LED_Toggle();
		Buzzer_Buzz_NUM_Times();
		cnt = 0;
		TCNT0 = Init_value ;
		
	}
	
	
}


