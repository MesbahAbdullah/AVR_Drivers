/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 4 Sep 2021                              */
/* Version     : V02                                     */
/* Brief       : SPI  driver                             */
/*********************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define SPI_INTERRUPT_MODE    DISABLE_SPI_INTERRUPT

#define SPI_DATA_ORDER        SEND_MSB_FIRST

#define SPI_CLOCK_POLARITY    IDLE_LOW_POLARITY

#define SPI_CLOCK_PHASE       READ_WRITE_PHASE

#define DOUBLE_SPEED_MODE     DISABLE_DOUBLE_SPEED_MODE

#define SPI_PRESCALER_VALUE   PRESCALLER_128

#endif 
