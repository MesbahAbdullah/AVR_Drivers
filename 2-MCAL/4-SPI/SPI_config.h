/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 4 Sep 2021                              */
/* Version     : V02                                     */
/* Brief       : SPI  driver                             */
/*********************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/*********************************************************/
/*1-ENABLE_SPI_INTERRUPT                                 */
/*2-DISABLE_SPI_INTERRUPT                                */
/*********************************************************/
#define SPI_INTERRUPT_MODE    DISABLE_SPI_INTERRUPT

/*********************************************************/
/*1-SEND_LSB_FIRST                                       */
/*2-SEND_MSB_FIRST                                       */
/*********************************************************/
#define SPI_DATA_ORDER        SEND_MSB_FIRST

/*********************************************************/
/*1-IDLE_HIGH_POLA                                       */
/*2-IDLE_LOW_POLARITY                                    */
/*********************************************************/
#define SPI_CLOCK_POLARITY    IDLE_LOW_POLARITY

/*********************************************************/
/*1-READ_WRITE_PHASE                                     */
/*2-WRITE_READ_PHASE                                     */
/*********************************************************/
#define SPI_CLOCK_PHASE       READ_WRITE_PHASE

/*********************************************************/
/*1-ENABLE_DOUBLE_SPEED_MODE                             */
/*2-DISABLE_DOUBLE_SPEED_MODE                            */
/*********************************************************/
#define DOUBLE_SPEED_MODE     DISABLE_DOUBLE_SPEED_MODE

/*********************************************************/
/*1-PRESCALLER_4                                         */
/*1-PRESCALLER_16                                        */
/*1-PRESCALLER_64                                        */
/*1-PRESCALLER_128                                       */
/*********************************************************/
#define SPI_PRESCALER_VALUE   PRESCALLER_128

#endif 
