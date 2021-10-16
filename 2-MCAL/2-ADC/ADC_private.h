/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 24 JAN 2021                             */
/* Version     : V01                                     */
/* Brief       : ADC  driver                             */
/*********************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/*     ADC REGISTERS      */

#define ADMUX             *((volatile u8*) 0x27 )
#define ADCSRA            *((volatile u8*) 0x26 )
#define ADCH              *((volatile u8*) 0x25 )
#define ADCL              *((volatile u8*) 0x24 )
#define SFIOR             (*(volatile u8*) 0x50 )
#define ADC_VAL           (*(volatile u8*) 0x24 )  

#endif
