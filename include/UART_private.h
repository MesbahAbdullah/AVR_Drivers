/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 3 Sep 2021                              */
/* Version     : V02                                     */
/* Brief       : uart driver                             */
/*********************************************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define SYNCHRONOUS_MODE    0
#define ASYNCHRONOUS_MODE   1

#define ONE_STOP_BIT       0
#define TWO_STOP_BITS      1

#define DISABLE_PARITY_BIT 0
#define EVEN_PARITY_BIT    1
#define ODD_PARITY_BIT     2

#define CHAR_SIZE_5BIT     0
#define CHAR_SIZE_6BIT     1
#define CHAR_SIZE_7BIT     2
#define CHAR_SIZE_8BIT     3
#define CHAR_SIZE_9BIT     4
 
#define BAUDRATE_9600      0
#define BAUDRATE_115200    1
#define BAUDRATE_4800      2
#define BAUDRATE_2400      3

#define ENABLE_MULTIPROCESSOR_MODE        0
#define DISABLE_MULTIPROCESSOR_MODE       1

#define ENABLE_DOUBLE_SPEED_MODE          0
#define DISABLE_DOUBLE_SPEED_MODE         1

#define ENABLE_TRANSMITTING_INTERRUPT     0
#define DISABLE_TRANSMITTING_INTERRUPT    1

#define ENABLE_RECEIVING_INTERRUPT        0
#define DISABLE_RECEIVING_INTERRUPT       1

#define ENABLE_UDR_INTERRUPT              0
#define DISABLE_UDR_INTERRUPT             1


#define  UDR    *((volatile u8*) 0x2C)
#define  UCSRA  *((volatile u8*) 0x2B)    
#define  UCSRB  *((volatile u8*) 0x2A)
#define  UBRRL  *((volatile u8*) 0x29)
#define  UBRRH  *((volatile u8*) 0x40)
#define  UCSRC  *((volatile u8*) 0x40)  

#endif 
