/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 4 Sep 2021                              */
/* Version     : V02                                     */
/* Brief       : SPI  driver                             */
/*********************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H



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



void SPI_voidInitMaster(void);
void SPI_voidInitSlave (void);

void SPI_voidSendByte    (u8  Copy_u8Data);
u8   SPI_u8ReceiveByte  (void);

void SPI_voidSendString   (u8* Copy_DataString);
void SPI_voidReceiveString(u8* Copy_DataString);

void SPI_voidMasterTransmit(u8 Copy_u8Data);
void SPI_voidSendReceiveSynch(u8 Copy_u8DataToTransmit,u8 *Copy_DataToReceive);

u8 SPI_SendReceiveSynch(u8 Copy_u8DataToTransmit);

#endif