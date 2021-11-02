/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 9 Sep 2021                              */
/* Version     : V01                                     */
/* Brief       : INT  driver                             */
/*********************************************************/
#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

/* interrupt triggering options */
#define INT_TRIGGER_RISING_EDGE          0
#define INT_TRIGGER_FALLING_EDGE         1
#define INT_TRIGGER_ANY_CHANGE           2
#define INT_TRIGGER_LOW_LEVEL            3

/* interrupt operatoin registers */
#define SREG            *((volatile u8*) 0x5F )
#define GICR            *((volatile u8*) 0x5B )
#define MCUCR           *((volatile u8*) 0x55 )
#define MCUCSR          *((volatile u8*) 0x54 )

#endif 
