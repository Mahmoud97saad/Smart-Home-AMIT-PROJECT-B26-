/*
 * Buzzer.c
 *
 * Created: 12/22/2020 11:11:34 PM
 *  Author: mahmo
 */ 


#include "Buzzer.h"

void Buzzer_Init(void)
{
	DIO_SetPinDir(Buzzer_PORT , Buzzer_PIN , DIO_PIN_OUTPUT);
}

void Buzzer_Start(void)
{
	DIO_SetPinVal(Buzzer_PORT , Buzzer_PIN , DIO_PIN_HIGH);
}

void Buzzer_Stop(void)
{
	DIO_SetPinVal(Buzzer_PORT , Buzzer_PIN , DIO_PIN_LOW);

}

void Buzzer_Buzz_NUM_Times(void) 
{
	uint8 data = 0;
	uint8 STATE_Buzzer = 0;
	

		while ( data <= Num_Buzz )
{
					if ( STATE_Buzzer == 1)
{
						Buzzer_Start();
						STATE_Buzzer = 0;
						data++;
}
					
					else if (STATE_Buzzer == 0)
{
						Buzzer_Stop();
						STATE_Buzzer = 1;
}

}
		
		data = 0;
		

}