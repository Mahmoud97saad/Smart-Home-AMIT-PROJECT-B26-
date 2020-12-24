/*
 * Project_cfg.h
 *
 * Created: 12/22/2020 8:31:18 PM
 *  Author: mahmo
 */ 


#ifndef PROJECT_CFG_H_
#define PROJECT_CFG_H_

#include "DIO.h"

//*****************************************LCD_cfg**************************************************//
#define   LCD_MODE     4


#define LCD_8BIT_CMD_PORT    DIO_PORTD
#define LCD_8BIT_DATA_PORT   DIO_PORTC

#define LCD_4BIT_CMD_PORT    DIO_PORTB
#define LCD_4BIT_DATA_PORT   DIO_PORTA

#define LCD_RS_PIN       DIO_PIN1
#define LCD_RW_PIN       DIO_PIN2
#define LCD_E_PIN        DIO_PIN3

#define  D0_PIN        DIO_PIN0
#define  D1_PIN        DIO_PIN1
#define  D2_PIN        DIO_PIN2
#define  D3_PIN        DIO_PIN3
#define  D4_PIN        DIO_PIN4
#define  D5_PIN        DIO_PIN5
#define  D6_PIN        DIO_PIN6
#define  D7_PIN        DIO_PIN7

//*****************************************LED_cfg**************************************************//

#define LED_PORT     DIO_PORTD
#define LED1_PIN     DIO_PIN0
#define LED2_PIN     DIO_PIN1
#define LED3_PIN     DIO_PIN2
#define LED4_PIN     DIO_PIN3
#define LED5_PIN     DIO_PIN4
#define LED6_PIN     DIO_PIN5
#define LED7_PIN     DIO_PIN6
#define LED8_PIN     DIO_PIN7

//*****************************************UART_cfg**************************************************//

#define  FREQ  160000
#define  Desired_BR  1152     // Baud Rate is variable value depending on the device connected to the micro controller

#define  TX_PORT     DIO_PORTD
#define  TX_PIN      DIO_PIN1

#define  RX_PORT     DIO_PORTD
#define  RX_PIN      DIO_PIN0

//*****************************************Buzzer_cfg**************************************************//

#define Buzzer_PORT     DIO_PORTD
#define Buzzer_PIN      DIO_PIN3
#define Num_Buzz      2            


//*****************************************Timer0_cfg**************************************************//

#define  Freq        8     // This Value of Frequency in MHZ
#define  Disered_Time_Timer0        3000






#endif /* PROJECT_CFG_H_ */