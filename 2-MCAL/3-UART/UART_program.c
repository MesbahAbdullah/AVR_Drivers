/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 3 Sep 2021                              */
/* Version     : V02                                     */
/* Brief       : uart driver                             */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_voidInit()
{

	SET_BIT(UCSRB, 3);
	SET_BIT(UCSRB, 4);

	/* read UCSRC */
	SET_BIT(UCSRC, 7);

#if UART_MODE == SYNCHRONOUS_MODE
#define U2X_VALUE 2
	SET_BIT(UCSRC, 6);
#endif

#if UART_MODE == ASYNCHRONOUS_MODE

	CLR_BIT(UCSRC, 6);

#if DOUBLE_SPEED_MODE == ENABLE_DOUBLE_SPEED_MODE
#define U2X_VALUE 8
	SET_BIT(UCSRA, 1);

#elif DOUBLE_SPEED_MODE == DISABLE_DOUBLE_SPEED_MODE
#define U2X_VALUE 16
	CLR_BIT(UCSRA, 1);
#endif
#endif

#if MULTI_PROCESSOR_MODE == ENABLE_MULTIPROCESSOR_MODE

	SET_BIT(UCSRA, 0);

#elif MULTI_PROCESSOR_MODE == DISABLE_MULTIPROCESSOR_MODE

	CLR_BIT(UCSRA, 0);
#endif

#if RECEIVING_INTERRUPT == ENABLE_RECEIVING_INTERRUPT

	SET_BIT(UCSRB, 7);

#elif RECEIVING_INTERRUPT == DISABLE_RECEIVING_INTERRUPT

	CLR_BIT(UCSRB, 7);
#endif

#if TRANSMITTING_INTERRUPT == ENABLE_TRANSMITTING_INTERRUPT

	SET_BIT(UCSRB, 6);

#elif TRANSMITTING_INTERRUPT == DISABLE_TRANSMITTING_INTERRUPT

	CLR_BIT(UCSRB, 6);
#endif

#if UDR_INTERRUPT == ENABLE_UDR_INTERRUPT

	SET_BIT(UCSRB, 5);

#elif UDR_INTERRUPT == DISABLE_UDR_INTERRUPT

	CLR_BIT(UCSRB, 5);
#endif

#if CHARACTER_SIZE == CHAR_SIZE_5BIT

	CLR_BIT(UCSRC, 1);
	CLR_BIT(UCSRC, 2);
	CLR_BIT(UCSRB, 2);

#elif CHARACTER_SIZE == CHAR_SIZE_6BIT

	SET_BIT(UCSRC, 1);
	CLR_BIT(UCSRC, 2);
	CLR_BIT(UCSRB, 2);

#elif CHARACTER_SIZE == CHAR_SIZE_7BIT

	CLR_BIT(UCSRC, 1);
	SET_BIT(UCSRC, 2);
	CLR_BIT(UCSRB, 2);

#elif CHARACTER_SIZE == CHAR_SIZE_8BIT

	SET_BIT(UCSRC, 1);
	SET_BIT(UCSRC, 2);
	CLR_BIT(UCSRB, 2);

#elif CHARACTER_SIZE == CHAR_SIZE_9BIT

	SET_BIT(UCSRC, 1);
	SET_BIT(UCSRC, 2);
	SET_BIT(UCSRB, 2);
#endif

#if PARITY_BIT_MODE == DISABLE_PARITY_BIT

	CLR_BIT(UCSRC, 4);
	CLR_BIT(UCSRC, 5);

#elif PARITY_BIT_MODE == EVEN_PARITY_BIT

	CLR_BIT(UCSRC, 4);
	SET_BIT(UCSRC, 5);

#elif PARITY_BIT_MODE == ODD_PARITY_BIT

	SET_BIT(UCSRC, 4);
	SET_BIT(UCSRC, 5);
#endif

#if STOP_BITS == ONE_STOP_BIT

	CLR_BIT(UCSRC, 3);

#elif STOP_BITS == TWO_STOP_BITS

	SET_BIT(UCSRC, 3);
#endif
#if BAUDRATE_VALUE == BAUDRATE_2400

	u16 BR_VALUE = 0;
	BR_VALUE = ((F_CPU) / (U2X_VALUE * 2400)) - 1;
	UBRRL = BR_VALUE;

#elif BAUDRATE_VALUE == BAUDRATE_4800

	u16 BR_VALUE = 0;
	BR_VALUE = ((F_CPU) / (U2X_VALUE * 4800)) - 1;
	UBRRL = BR_VALUE;

#elif BAUDRATE_VALUE == BAUDRATE_9600

	u16 BR_VALUE = 0;
	BR_VALUE = ((F_CPU) / (U2X_VALUE * 9600)) - 1;
	UBRRL = BR_VALUE;

#elif BAUDRATE_VALUE == BAUDRATE_115200

	u16 BR_VALUE = 0;
	BR_VALUE = ((F_CPU) / (U2X_VALUE * 115200)) - 1;
	UBRRL = BR_VALUE;

#endif
}

void UART_voidSendByte(u8 Copy_u8Data)
{
	/* Put data into buffer, sends the data */
	while (BIT_IS_CLEAR(UCSRA, 5))
		;
	UDR = Copy_u8Data;
}
u8 UART_u8ReceveByte()
{
	/* Wait for data to be received */
	while (GET_BIT(UCSRA, 7) == 0)
		;
	/* Get and return received data from buffer */
	return UDR;
}

void UART_voidSendString(u8 *Copy_ptrString)
{

	u8 LOC_u8Iterator = 0;

	while (Copy_ptrString[LOC_u8Iterator] != '\0')
	{

		UART_voidSendByte(Copy_ptrString[LOC_u8Iterator]);
		LOC_u8Iterator++;
	}
}
void UART_voidReceveString(u8 *Copy_u8DataString)
{
	u8 LOC_u8Iterator = 0;

	Copy_u8DataString[LOC_u8Iterator] = UART_u8ReceveByte();
	while (Copy_u8DataString[LOC_u8Iterator] != '#')
	{
		LOC_u8Iterator++;
		Copy_u8DataString[LOC_u8Iterator] = UART_u8ReceveByte();
	}
	Copy_u8DataString[LOC_u8Iterator] = '\0';
}
