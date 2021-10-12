/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 3 Sep 2021                              */
/* Version     : V02                                     */
/* Brief       : uart driver                             */
/*********************************************************/

#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#define F_CPU 8000000UL

/*********************************************************/
/*1-SYNCHRONOUS_MODE                                     */
/*2-ASYNCHRONOUS_MODE                                    */
/*********************************************************/
#define UART_MODE ASYNCHRONOUS_MODE

/*********************************************************/
/*1-ONE_STOP_BIT                                         */
/*2-TWO_STOP_BITS                                        */
/*********************************************************/
#define STOP_BITS ONE_STOP_BIT

/*********************************************************/
/*1-DISABLE_PARITY_BIT                                   */
/*2-EVEN_PARITY_BIT                                      */
/*3-ODD_PARITY_BIT                                       */
/*********************************************************/
#define PARITY_BIT_MODE DISABLE_PARITY_BIT

/*********************************************************/
/*1-CHAR_SIZE_5BIT                                       */
/*2-CHAR_SIZE_6BIT                                       */
/*3-CHAR_SIZE_7BIT                                       */
/*4-CHAR_SIZE_8BIT                                       */
/*5-CHAR_SIZE_9BIT                                       */
/*********************************************************/
#define CHARACTER_SIZE CHAR_SIZE_8BIT

/*********************************************************/
/*1-BAUDRATE_2400                                        */
/*2-BAUDRATE_4800                                        */
/*3-BAUDRATE_9600                                        */
/*4-BAUDRATE_115200                                      */
/*********************************************************/
#define BAUDRATE_VALUE BAUDRATE_9600

/*********************************************************/
/*1-ENABLE_MULTIPROCESSOR_MODE                           */
/*2-DISABLE_MULTIPROCESSOR_MODE                          */
/*********************************************************/
#define MULTI_PROCESSOR_MODE DISABLE_MULTIPROCESSOR_MODE

/*********************************************************/
/*1-ENABLE_DOUBLE_SPEED_MODE                             */
/*2-DISABLE_DOUBLE_SPEED_MODE                            */
/*********************************************************/
#define DOUBLE_SPEED_MODE ENABLE_DOUBLE_SPEED_MODE

/*********************************************************/
/*1-ENABLE_TRANSMITTING_INTERRUPT                        */
/*2-DISABLE_TRANSMITTING_INTERRUPT                       */
/*********************************************************/
#define TRANSMITTING_INTERRUPT DISABLE_TRANSMITTING_INTERRUPT

/*********************************************************/
/*1-ENABLE_RECEIVING_INTERRUPT                           */
/*2-DISABLE_RECEIVING_INTERRUPT                          */
/*********************************************************/
#define RECEIVING_INTERRUPT DISABLE_RECEIVING_INTERRUPT

/*********************************************************/
/*1-ENABLE_UDR_INTERRUPT                                 */
/*2-DISABLE_UDR_INTERRUPT                                */
/*********************************************************/
#define UDR_INTERRUPT DISABLE_UDR_INTERRUPT

#endif // !UART_CONFIG_H