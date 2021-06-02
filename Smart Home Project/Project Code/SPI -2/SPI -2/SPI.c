/*
 * SPI.c
 *
 * Created: 4/24/2021 11:51:20 AM
 *  Author: Ali
 */ 


#include "SPI.h"


void SPI_Master_Init(void)
{
	/*MISO*/
	DIO_SetPinDir(DIO_PORTB , DIO_PIN6 , DIO_PIN_INPUT);
	/*MOSI*/
	DIO_SetPinDir(DIO_PORTB , DIO_PIN5 , DIO_PIN_OUTPUT);
	/*CLK*/
	DIO_SetPinDir(DIO_PORTB , DIO_PIN7 , DIO_PIN_OUTPUT);
	/*SS*/
	DIO_SetPinDir(DIO_PORTB , DIO_PIN4 , DIO_PIN_OUTPUT);
	
	        /*0b 0101 0011*/
	SPI->SPCR |= 0x53 ;
	
	/*SS pin no Init Trans*/
	DIO_SetPinValue(DIO_PORTB , DIO_PIN4 , DIO_PIN_HIGH);
}
void SPI_Slave_Init(void)
{
	/*MISO*/
	DIO_SetPinDir(DIO_PORTB , DIO_PIN6 , DIO_PIN_OUTPUT);
	/*MOSI*/
	DIO_SetPinDir(DIO_PORTB , DIO_PIN5 , DIO_PIN_INPUT);
	/*CLK*/
	DIO_SetPinDir(DIO_PORTB , DIO_PIN7 , DIO_PIN_INPUT);
	/*SS*/
	DIO_SetPinDir(DIO_PORTB , DIO_PIN4 , DIO_PIN_INPUT);
	
		     /*0b 0100 0000*/
	 SPI->SPCR |= 0x40 ;
	
}

void SPI_Master_InitTrans(void)
{
	DIO_SetPinValue(DIO_PORTB , DIO_PIN4 , DIO_PIN_LOW);
}
void SPI_Master_TermTrans(void)
{
	DIO_SetPinValue(DIO_PORTB , DIO_PIN4 , DIO_PIN_HIGH);
}

uint8 SPI_TranSiver(void)
{
	uint8 rec_data = 0;
	
	SPI->SPDR = 0;
	
	while(GET_BIT(SPI->SPSR , 7) == 0);
	
	rec_data  = SPI->SPDR ;
	
	return rec_data;
}