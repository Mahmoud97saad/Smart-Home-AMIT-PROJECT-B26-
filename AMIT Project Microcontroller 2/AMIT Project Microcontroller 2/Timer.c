/*
 * Timer.c
 *
 * Created: 11/13/2020 5:22:08 PM
 *  Author: mahmo
 */ 


#include "Timer.h"


uint32 NUM_OVF = 0;
uint32 Init_value = 0;


//uint32 Timer1_Num_Comp = 0;



void Timer0_Init(void)
{
	/*select Normal mode*/
	CLR_BIT(TCCR0 , 3);
	CLR_BIT(TCCR0 , 6);
	/*enable Interrupts*/
	SET_BIT(SREG , 7);  /* enable global interrupts*/
	SET_BIT(TIMSK , 0);  // enable Timer0 OVF Interrupts
}

void Timer0_Start(void)
{
	SET_BIT(TCCR0 , 0);
	CLR_BIT(TCCR0 , 1);
	SET_BIT(TCCR0 , 2);
}

void Timer0_Stop(void)
{
	CLR_BIT(TCCR0 , 0);
	CLR_BIT(TCCR0 , 1);
	CLR_BIT(TCCR0 , 2);
}

void Timer0_SetDelay(uint32 Delay_ms )
{
	uint8 Tick_Time = (1024 / Freq );
	
	uint32 Total_Tick = (Delay_ms * 1000 ) / Tick_Time ;
	
	NUM_OVF = Total_Tick / 256 ;
	
	Init_value = 256 - (Total_Tick %256 );
	
	TCNT0 = Init_value ;
	
	NUM_OVF++;
	
	 
}

/*void Timer1_Init(void)
{
	// SELECT MODE 4 OF TIMER1
	SET_BIT(TCCR1B , 3);
	//GENERAL INT ENABLE
	SET_BIT(SREG , 7);
	//PREIPHERAL INT ENABLE
	SET_BIT(TIMSK , 4);
	
	
}

void Timer1_Start(void)
{
	//SET PRESCALER 1024
	SET_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B , 1);
	SET_BIT(TCCR1B , 2);
}

void Timer1_Stop(void)
{
	CLR_BIT(TCCR1B , 0);
	CLR_BIT(TCCR1B , 0);
	CLR_BIT(TCCR1B , 0);
}

void Timer1_SetDelay(uint32 Delay_ms )
{
	if ( Delay_ms <= 4000 )
	{
		uint8 tick_time = 1024/16;
		uint32 num_ticks = (Delay_ms * 1000) / tick_time;
		
		OCR1A = num_ticks - 1 ;
		
		Timer1_Num_Comp ++;
		
	}
}

void PWN0_Init(void)
{
	//Set direction of bit 3 in register output 
	SET_BIT(DDRB , 3);
	
	//fast PWM
	SET_BIT(TCCR0 , 3);
	SET_BIT(TCCR0 , 6);
	
	//Non inverted
	SET_BIT(TCCR0 , 5);
	
	
}

void PWN0_StartDutyCycle(uint8 Duty_Cycle)
{
	OCR0  = ( (Duty_Cycle * 256) / 100) - 1;
}

void PWN0_Start(void)
{
	//select Prescaler 256
	SET_BIT(TCCR0 , 2);
}*/
