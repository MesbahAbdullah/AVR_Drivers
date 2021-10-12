/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 3 Sep 2021                              */
/* Version     : V02                                     */
/* Brief       : uart driver                             */
/*********************************************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define  UDR    *((volatile u8*) 0x2C)
#define  UCSRA  *((volatile u8*) 0x2B)    
#define  UCSRB  *((volatile u8*) 0x2A)
#define  UBRRL  *((volatile u8*) 0x29)
#define  UBRRH  *((volatile u8*) 0x40)
#define  UCSRC  *((volatile u8*) 0x40)  


#endif // !UART_PRIVATE_H
