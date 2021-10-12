/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 24 JAN 2021                             */
/* Version     : V01                                     */
/* Brief       : ADC  driver                             */
/*********************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H



#define  AREF_SOURCE      0
#define  AVCC_SOURCE      1
#define  INTERNAL_SOURCE  2


#define CHANNEL0            0
#define CHANNEL1            1
#define CHANNEL2            2
#define CHANNEL3            3
#define CHANNEL4            4
#define CHANNEL5            5
#define CHANNEL6            6
#define CHANNEL7            7

#define AUTO_RUNNING_MODE   0
#define EXTERNAL_INT0       1

#define  RIGHT_ADJUST       0
#define  LEFT_ADJUST        1

#define ADC_INT_ENABLED     0
#define ADC_INT_DISABLED    1


#define PRESCALER2          0
#define PRESCALER4          1
#define PRESCALER8          2
#define PRESCALER16         3
#define PRESCALER128        4


void ADC_voidInit(void);
u16 ADC_u16ReadChannel(u8 copy_channelNumber);


#endif // !ADC_INTERFACE_H
