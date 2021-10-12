/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 4 Sep 2021                              */
/* Version     : V02                                     */
/* Brief       : SPI  driver                             */
/*********************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/*     SPI REGISTERS      */
#define SPDR            *((volatile u8*) 0x2F )
#define SPSR            *((volatile u8*) 0x2D )
#define SPCR            *((volatile u8*) 0x2E )

#endif //  !SPI_PRIVATE_H
