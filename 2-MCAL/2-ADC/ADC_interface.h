/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 24 JAN 2021                             */
/* Version     : V01                                     */
/* Brief       : ADC  driver                             */
/*********************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define CHANNEL0            0
#define CHANNEL1            1
#define CHANNEL2            2
#define CHANNEL3            3
#define CHANNEL4            4
#define CHANNEL5            5
#define CHANNEL6            6
#define CHANNEL7            7


void ADC_voidInit();
u16 ADC_u16ReadChannel(u8 copy_channelNumber);


#endif 
