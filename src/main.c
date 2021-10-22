
/***********************************************************************************/
/* Author      : Mesbah Abdullah                                                   */
/* Date        : 1 Jul 2021                                                        */
/* Version     : V01                                                               */
/* Brief       : graduation project faculty of electronic engineering (smart city) */
/***********************************************************************************/
#undef F_CPU
#define F_CPU 16000000UL
#include <stdio.h>
#include "STD_TYPES.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
#include "DHT11_interface.h"
#include "ESP_interface.h"
#include "ADC_interface.h"
#include "WDT_interface.h"
// it has delay function
/***********************************temperature sensor variables**********************************/
#define TEMP_PIN 1
u16 adc_result1;
s16 temp;
s16 far;
u8 buffer[10];

/*This function is to read an analogue value from temp sensor lm-35 and send the data using UART */
void TEMP_voidReadValue()
{
    adc_result1 = ADC_u16ReadChannel(TEMP_PIN); // read ADC value
    temp = adc_result1 * 4.88;                  // finding the temperature
    temp = temp / 10.0;
    itoa(temp, buffer, 10);
    UART_voidSendString((u8 *)"Temp="); // display temperature
    UART_voidSendString(buffer);
    UART_voidSendString((u8 *)"C\r\n");
    _delay_ms(1000);
}
// u8 *x;
/***********************************GAS Sensor variables******************************************/
#define GAS_PIN 2
u16 adc_result0 = 0;
u8 tempBuffer[10];
/*This function is to read an analogue value from gas sensor MQ-135 and send the data using uart */
void GAS_voidReadValue()
{
    adc_result0 = ADC_u16ReadChannel(GAS_PIN);
    itoa(adc_result0, tempBuffer, 10);
    UART_voidSendString((u8 *)tempBuffer);
}

/******This function is to read an digital value from PIR sensor and send the data using uart*****/
void PIR_voidReadValue()
{
    // u8 localVariable=GPIO_u8GetPinValue(GPIO_PORTB,PIN0);	//test that line for ma
    if (GPIO_u8GetPinValue(GPIO_PORTB, PIN0) == 1)
        UART_voidSendString((u8 *)"there is someone moving around");
    else
        UART_voidSendString((u8 *)"No one is moving");
}

/******This function is to read an digital value from IR sensor and send the data using uart*****/
void IR_voidReadValue(int *ptr)
{
    *ptr = 3;
}
int main(void)
{
    GPIO_voidSetPinDirection(GPIO_PORTB, PIN0, INPUT); // This pin is for operating the PIR sensor
    UART_voidInit();
    ADC_voidInit();
    ESP8266_voidInit();
    ESP8266_voidConnectToWiFi("ssid", "pass");

    while (1)
    {
        /* DHT11 operating */
        DHT11_voidStart();
        _delay_ms(2000); // to call the DHT11_voidStart() again

        /* MQ-135 operating */
        GAS_voidReadValue();
        _delay_ms(2000);
        /*lm-35 operating */
        TEMP_voidReadValue();
        _delay_ms(2000);

        /*PIR operating */
        PIR_voidReadValue();
        _delay_ms(2000);
    }
}