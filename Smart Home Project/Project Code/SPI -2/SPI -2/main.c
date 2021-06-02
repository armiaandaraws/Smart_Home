/*
 * F19_SPI_Driver.c
 *
 * Created: 4/24/2021 11:50:28 AM
 * Author : Ali
 */ 

#include "SPI.h"
#define F_CPU 16000000
#include <util/delay.h>
#include "LCD.h"

int main(void)
{
   
	uint8 rx_data = 0;
	uint8 LCD_Counter = 0;
	
	/*Init LCD*/
	LCD_Init();
	
	
	/*Init LED 1 and LED 2 Pins*/
	DIO_SetPinDir(DIO_PORTC , DIO_PIN1 , DIO_PIN_OUTPUT); // LED 1 Pin
	DIO_SetPinDir(DIO_PORTC , DIO_PIN0 , DIO_PIN_OUTPUT); // LED 2 Pin
	
	/*Init SPI as Slave*/
	SPI_Slave_Init();
	
	
    while (1) 
    {
		rx_data = SPI_TranSiver();
		
		switch (rx_data)
		{
			case '1':
				DIO_TogglePin(DIO_PORTC , DIO_PIN1);
				break;
			
			case '2':
				DIO_TogglePin(DIO_PORTC , DIO_PIN0);
				break;
				
			default:
				break;
		}
		
		
		/* Clear screen after displaying 16 Character */
		LCD_Counter++;
		LCD_WriteChar(rx_data);
		
		if (LCD_Counter == 16)
		{
			LCD_Clear();
			LCD_Counter = 0;
		}
			
		
    }
}

