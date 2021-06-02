/*
 * F19_SPI_Driver.c
 *
 * Created: 4/24/2021 11:50:28 AM
 * Author : Ali
 */ 

#include "SPI.h"
#define F_CPU 16000000
#include <util/delay.h>
#include "UART.h"

int main(void)
{
    uint8 tx_data = 0;
	
	/*Init UART*/
	UART_Init();
	
	/*Init LED*/
	//DIO_SetPinDir(DIO_PORTC , DIO_PIN1 , DIO_PIN_OUTPUT);
	
	/*Init SPI as Master*/
	SPI_Master_Init();
	SPI_Master_InitTrans();
	_delay_ms(1000);
	
	
    while (1) 
    {
		
		tx_data = UART_Rx();
		if (tx_data)
		{
			// Next line is used for UART communication validation but not essential
			// DIO_TogglePin(DIO_PORTC , DIO_PIN1); 
			
			SPI_TranSiver(tx_data);
		}
		
    }
}

