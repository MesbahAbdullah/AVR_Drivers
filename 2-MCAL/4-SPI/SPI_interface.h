/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 4 Sep 2021                              */
/* Version     : V02                                     */
/* Brief       : SPI  driver                             */
/*********************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_voidInitMaster();
void SPI_voidInitSlave();

void SPI_voidSendByte(u8 Copy_u8Data);
u8 SPI_u8ReceiveByte();

void SPI_voidSendString(u8 *Copy_DataString);
void SPI_voidReceiveString(u8 *Copy_DataString);

void SPI_voidMasterTransmit(u8 Copy_u8Data);
void SPI_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive);

u8 SPI_SendReceiveSynch(u8 Copy_u8DataToTransmit);

#endif