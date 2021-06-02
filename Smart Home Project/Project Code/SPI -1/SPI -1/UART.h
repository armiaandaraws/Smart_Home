/*
 * UART.h
 *
 * Created: 4/23/2021 1:57:44 PM
 *  Author: v-armiae
 */ 


#ifndef UART_H_
#define UART_H_

#include "MCU.h"
#include "BIT_Math.h"
#include "STD.h"

void UART_Init(void);

void UART_Tx(uint8 data);

void UART_TxString(uint8* str);

uint8 UART_Rx(void);


#endif /* UART_H_ */