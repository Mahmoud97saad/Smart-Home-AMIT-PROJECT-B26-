/*
 * LCD.c
 *
 * Created: 10/30/2020 6:10:01 PM
 *  Author: mahmo
 */ 


#include "LCD.h"



void LCD_Init(void)
{
	#if  LCD_MODE  ==  8
	
	DIO_SetPinDir(LCD_8BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);
	
	DIO_SetPortDir(LCD_8BIT_DATA_PORT , DIO_PORT_OUTPUT);
	
	_delay_ms(100);
	
	LCD_WriteCommand(0X38);
	
	LCD_WriteCommand(0X0C);
	
	LCD_WriteCommand(0X01);
	
	LCD_WriteCommand(0X06);
	
	LCD_WriteCommand(0X02);
	
	
	#elif  LCD_MODE  ==  4
	
	DIO_SetPinDir(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(LCD_4BIT_DATA_PORT , D4_PIN ,  DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT , D5_PIN ,  DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT , D6_PIN ,  DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT , D7_PIN ,  DIO_PIN_OUTPUT);
	
	_delay_ms(100);
	
	LCD_WriteCommand(0X33);
	LCD_WriteCommand(0X32);
	LCD_WriteCommand(0X28);
	
	LCD_WriteCommand(0X0C);
	LCD_WriteCommand(0X01);
	LCD_WriteCommand(0X06);
	LCD_WriteCommand(0X02);
	
	
	#endif
}

void LCD_WriteCommand(uint8 cmd)
{
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (cmd & 0xf0) | (PORTA & 0X0f);
	
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (cmd << 4) | (PORTA & 0X0f);
	
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	_delay_ms(5);
	
	
}

void LCD_WriteChar(uint8 chr)
{
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_HIGH);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (chr & 0xf0) | (PORTA & 0X0f);
	
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (chr << 4) | (PORTA & 0X0f);
	
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	_delay_ms(5);
	
	
}

void LCD_WriteString(uint8* str)
{
	uint8 i = 0;
	
	while (str[i] != '\0')
	{
		LCD_WriteChar(str[i]);
		i++;
	}
}

void LCD_GoTo(uint8 row , uint8 col)
{
	uint8 pos[2] = {0x80 , 0xC0};
		
		LCD_WriteCommand(pos[row]+col);
		
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0X01);
}

void LCD_WriteInteger(sint32 num)
{
	
	
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_HIGH);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	LCD_WriteCommand(0X40);
	
	PORTA = (num & 0xf0) | (PORTA & 0X0f);
	
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (num << 4) | (PORTA & 0X0f);
	
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	_delay_ms(5);
	
}
