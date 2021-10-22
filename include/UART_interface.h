/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 3 Sep 2021                              */
/* Version     : V02                                     */
/* Brief       : uart driver                             */
/*********************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_private.h"
#include "UART_config.h"
#include "GPIO_interface.h"

void UART_voidInit();

void UART_voidSendByte(u8 Copy_u8Data);
u8   UART_u8ReceveByte();

void UART_voidSendString  (u8 * Copy_ptrString  );
void UART_voidReceveString(u8 * Copy_u8DataString );

#endif 
