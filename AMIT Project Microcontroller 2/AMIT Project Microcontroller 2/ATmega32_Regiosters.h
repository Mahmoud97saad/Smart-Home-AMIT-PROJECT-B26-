/*
 * ATmega32_Regiosters.h
 *
 * Created: 23/10/2020 07:41:38 م
 *  Author: Ali
 */ 


#ifndef ATMEGA32_REGIOSTERS_H_
#define ATMEGA32_REGIOSTERS_H_

#include "STD.h"


#define PORTA (*(volatile uint8*)(0x3B))
#define PINA  (*(volatile uint8*)(0x39))
#define DDRA  (*(volatile uint8*)(0x3A))

#define PORTB (*(volatile uint8*)(0x38))
#define PINB  (*(volatile uint8*)(0x36))
#define DDRB  (*(volatile uint8*)(0x37))

#define PORTC (*((volatile uint8*)(0x35)))
#define PINC  (*((volatile uint8*)(0x33)))
#define DDRC  (*((volatile uint8*)(0x34)))

#define PORTD (*(volatile uint8*)(0x32))
#define PIND  (*(volatile uint8*)(0x30))
#define DDRD  (*(volatile uint8*)(0x31))

/**************************************EXTERNAL_INTERRUPT_RGS*******************************************/

#define   SREG     (*(volatile uint8*)(0x5F))

#define   GICR     (*(volatile uint8*)(0x5B))

#define   GIFR     (*(volatile uint8*)(0x5A))

#define   MCUCR    (*(volatile uint8*)(0x55))

#define   MCUSCR    (*(volatile uint8*)(0x54))

/**************************************Timer0_RGS*******************************************/
#define   TCNT0     (*(volatile uint8*)(0x52))

#define   TCCR0     (*(volatile uint8*)(0x53))

#define   OCR0     (*(volatile uint8*)(0x5C))

#define   TIMSK   (*(volatile uint8*)(0x59))

/**************************************Timer1_RGS*******************************************/

#define   TCCR1A     (*(volatile uint8*)(0x4F))

#define   TCCR1B     (*(volatile uint8*)(0x4E))

#define   OCR1A      (*(volatile uint16*)(0x4A))

#define   ICR1       (*(volatile uint16*)(0x46))

/**************************************UART_RGS*******************************************/

#define   UBRRH      (*(volatile uint8*)(0x40))

#define   UBRRL      (*(volatile uint8*)(0x29))

#define   UCSRA      (*(volatile uint8*)(0x2B))

#define   UCSRB      (*(volatile uint8*)(0x2A))

#define   UCSRC      (*(volatile uint8*)(0x40))

#define   UDR        (*(volatile uint8*)(0x2C))





/**************************************SPI_RGS*******************************************/

typedef struct
{
	uint8 SPCR ;
	uint8 SPSR;
	uint8 SPDR;
}SPI_REGS;

#define  SPI    ((volatile SPI_REGS*)(0x2D))

/**************************************I2C_RGS*******************************************/

#define   TWCR      (*(volatile uint8*)(0x56))

#define   TWDR      (*(volatile uint8*)(0x23))

#define   TWAR      (*(volatile uint16*)(0x22))

#define   TWBR      (*(volatile uint16*)(0x20))

#define   TWSR      (*(volatile uint16*)(0x21))
 





#endif /* ATMEGA32_REGIOSTERS_H_ */