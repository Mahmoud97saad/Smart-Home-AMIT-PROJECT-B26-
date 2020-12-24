/*
 * LED.c
 *
 * Created: 12/22/2020 8:23:51 PM
 *  Author: mahmo
 */ 

#include "LED.h"

/*IF YOU HAVE MORE THAN ONE LED TO CONTROL 
  YOU HAVE TO COPY THE DIO_SetPinDir & DIO_TogglePin FOR THE NUMBER THAT YOU WANT
  WITH CONSIDERING MACROS IN Project_cfg FILE AT LED_cfg */

void LED_Init(void)
{
	DIO_SetPinDir(LED_PORT , LED1_PIN ,DIO_PIN_OUTPUT); // SET DIRECTION OUTPUT OF LED 1 
	DIO_SetPinDir(LED_PORT , LED2_PIN ,DIO_PIN_OUTPUT); // SET DIRECTION OUTPUT OF LED 2

}

void LED_Toggle(void)
{
	DIO_TogglePin(LED_PORT , LED1_PIN); // CONTROL LED 1 ON OR OFF
	DIO_TogglePin(LED_PORT , LED2_PIN); // CONTROL LED 2 ON OR OFF

}