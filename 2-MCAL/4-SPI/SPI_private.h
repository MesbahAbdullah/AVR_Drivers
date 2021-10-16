/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 4 Sep 2021                              */
/* Version     : V02                                     */
/* Brief       : SPI  driver                             */
/*********************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define ENABLE_SPI_INTERRUPT      0
#define DISABLE_SPI_INTERRUPT     1

#define SEND_LSB_FIRST            0
#define SEND_MSB_FIRST            1

#define IDLE_HIGH_POLARITY        0
#define IDLE_LOW_POLARITY         1

#define READ_WRITE_PHASE          0
#define WRITE_READ_PHASE          1

#define ENABLE_DOUBLE_SPEED_MODE  0
#define DISABLE_DOUBLE_SPEED_MODE 1

#define PRESCALLER_4              0
#define PRESCALLER_16             1
#define PRESCALLER_64             2
#define PRESCALLER_128            3

/*     SPI REGISTERS      */
#define SPDR            *((volatile u8*) 0x2F )
#define SPSR            *((volatile u8*) 0x2D )
#define SPCR            *((volatile u8*) 0x2E )

#endif //  !SPI_PRIVATE_H
