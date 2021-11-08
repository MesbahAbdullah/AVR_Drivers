/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 24 JAN 2021                             */
/* Version     : V01                                     */
/* Brief       : ADC  driver                             */
/*********************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define  AREF_SOURCE      0
#define  AVCC_SOURCE      1
#define  INTERNAL_SOURCE  2

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

/* ADC registers */
#define ADMUX             *((volatile u8*) 0x27 )
#define ADCSRA            *((volatile u8*) 0x26 )
#define ADCH              *((volatile u8*) 0x25 )
#define ADCL              *((volatile u8*) 0x24 )
#define SFIOR             *((volatile u8*) 0x50 )
#define ADC_VAL           *((volatile u16*) 0x24 )  

#endif
