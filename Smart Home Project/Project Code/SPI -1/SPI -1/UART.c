/*
 * UART.c
 *
 * Created: 4/23/2021 1:57:35 PM
 *  Author: v-armiae
 */ 

#include "UART.h"

void UART_Init(void)
{
	uint32 UBRR_Val = 0;
	//uint8 UBBRL ;
	
	// Set Tx pint to Output
	SET_BIT(DDRD, 1);
	
	// Set Rx pin to Input
	CLR_BIT(DDRD, 0);
	
	// enable Tx
	SET_BIT(UCSRB, 4);
	
	//enable Rx
	SET_BIT(UCSRB, 3);
	
	//Set data bit
	UCSRC |= 0x86;
	
	// Set Baud Rate 
	UBRR_Val = ((160000) / (16 * 96)) - 1;
	UBRRL = UBRR_Val;
	
	//Set Stop Bit (already set to 0)
	
	
	//Set Parity (already set to 0)
	
}

void UART_Tx(uint8 data)
{
	UDR = data;
	while (GET_BIT(UCSRA, 5) == 0);
	
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
	uint8 data = 0;
	
	while (GET_BIT(UCSRA, 7) == 0);
	
	data = UDR;
	
	return data;
}
