/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 18 Jul 2021                             */
/* Version     : V01                                     */
/* Brief       : DHT11 driver                            */
/*********************************************************/
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "UART_interface.h"
#include "WDT_interface.h"

#include "DHT11_interface.h"

/* Microcontroller send start pulse/request */
void Request()
{
	GPIO_voidSetPinDirection(GPIO_PORTD, DHT11_PIN, OUTPUT); /* set pin as output */
	GPIO_voidSetPinValue(GPIO_PORTD, DHT11_PIN, LOW);		/* set pin to low  */
	_delay_ms(18);										/* wait for 20ms   */
	GPIO_voidSetPinValue(GPIO_PORTD, DHT11_PIN, LOW);		/* set pin to high */
}

/* receive response from DHT11 */
void Response()
{
	WDT_voidON();
	GPIO_voidSetPinDirection(GPIO_PORTD, DHT11_PIN, INPUT); /* set pin as input */
	while (GPIO_u8GetPinValue(GPIO_PORTD,DHT11_PIN))
		;
	while ((GPIO_u8GetPinValue(GPIO_PORTD,DHT11_PIN)) == 0)
		;
	while (GPIO_u8GetPinValue(GPIO_PORTD,DHT11_PIN))
		;
	WDT_voidOFF();
}

u8 Receive_data() /* receive data */
{
	u8 c = 0;
	for (int q = 0; q < 8; q++)
	{
		while ((GPIO_u8GetPinValue(GPIO_PORTD,DHT11_PIN)) == 0) /* signal high start */
			;
		/* check received bit 0 or 1 */
		_delay_us(30);
		if (GPIO_u8GetPinValue(GPIO_PORTD,DHT11_PIN)) /* if high pulse is greater than 30ms */
			c = (c << 1) | (0x01);	 /* then its logic HIGH */
		else						 /* otherwise its logic LOW */
			c = (c << 1);
		while (GPIO_u8GetPinValue(GPIO_PORTD,DHT11_PIN)) /* signal high start */
			;
	}
	return c;
}

void DHT11_voidStart(void)
{
	char data[5];
	u8 I_RH, D_RH, I_Temp, D_Temp, CheckSum;
	UART_voidSendString("Humidity =");
	UART_voidSendString("Temp = ");

	Request();	/* send start pulse */
	Response(); /* receive response */
	GPIO_voidSetPinValue(GPIO_PORTC, PIN7, LOW);

	I_RH = Receive_data();	   /* store first eight bit in I_RH    */
	D_RH = Receive_data();	   /* store next eight bit in D_RH     */
	I_Temp = Receive_data();   /* store next eight bit in I_Temp   */
	D_Temp = Receive_data();   /* store next eight bit in D_Temp   */
	CheckSum = Receive_data(); /* store next eight bit in CheckSum */

	if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum)
	{
		UART_voidSendString("Error");
	}

	else
	{
		itoa(I_RH, data, 10);
		UART_voidSendString(data);
		UART_voidSendString(".");

		itoa(D_RH, data, 10);
		UART_voidSendString(data);
		UART_voidSendString("%");

		itoa(I_Temp, data, 10);
		UART_voidSendString(data);
		UART_voidSendString(".");

		itoa(D_Temp, data, 10);
		UART_voidSendString(data);
		UART_voidSendString("C ");

		itoa(CheckSum, data, 10);
		UART_voidSendString(data);
		UART_voidSendString(" ");
	}

	_delay_ms(10);
}