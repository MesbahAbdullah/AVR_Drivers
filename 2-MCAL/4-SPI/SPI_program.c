/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 4 Sep 2021                              */
/* Version     : V02                                     */
/* Brief       : SPI  driver                             */
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidInitMaster()
{

    GPIO_voidSetPinDirection(GPIO_PORTB, PIN4, OUTPUT); //SS   PIN
    GPIO_voidSetPinDirection(GPIO_PORTB, PIN5, OUTPUT); //MOSI PIN
    GPIO_voidSetPinDirection(GPIO_PORTB, PIN6, INPUT);  //MISO PIN
    GPIO_voidSetPinDirection(GPIO_PORTB, PIN7, OUTPUT); //SCK  PIN

    SET_BIT(SPCR, 6); // ENABLE SPI MODULE
    SET_BIT(SPCR, 4); // MASTER MODE

#if SPI_INTERRUPT_MODE == ENABLE_SPI_INTERRUPT

    SET_BIT(SPCR, 7);

#elif SPI_INTERRUPT_MODE == DISABLE_SPI_INTERRUPT

    CLR_BIT(SPCR, 7);
#endif

#if SPI_DATA_ORDER == SEND_LSB_FIRST

    SET_BIT(SPCR, 5);

#elif SPI_DATA_ORDER == SEND_MSB_FIRST

    CLR_BIT(SPCR, 5);
#endif

#if SPI_CLOCK_POLARITY == IDLE_HIGH_POLARITY

    SET_BIT(SPCR, 3);

#elif SPI_CLOCK_POLARITY == IDLE_LOW_POLARITY

    CLR_BIT(SPCR, 3);
#endif

#if SPI_CLOCK_PHASE == READ_WRITE_PHASE

    CLR_BIT(SPCR, 2);

#elif SPI_CLOCK_PHASE == WRITE_READ_PHASE

    SET_BIT(SPCR, 2);
#endif

#if DOUBLE_SPEED_MODE == ENABLE_DOUBLE_SPEED_MODE

    SET_BIT(SPSR, 0);

#elif DOUBLE_SPEED_MODE == DISABLE_DOUBLE_SPEED_MODE

    CLR_BIT(SPSR, 0);
#endif

#if SPI_PRESCALER_VALUE == PRESCALLER_4

    CLR_BIT(SPCR, 0);
    CLR_BIT(SPCR, 1);

#elif SPI_PRESCALER_VALUE == PRESCALLER_16

    SET_BIT(SPCR, 0);
    CLR_BIT(SPCR, 1);
#elif SPI_PRESCALER_VALUE == PRESCALLER_64

    CLR_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);

#elif SPI_PRESCALER_VALUE == PRESCALLER_128

    SET_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);
#endif
}

void SPI_voidInitSlave()
{

    GPIO_voidSetPinDirection(GPIO_PORTB, PIN4, INPUT);  //SS   PIN
    GPIO_voidSetPinDirection(GPIO_PORTB, PIN5, INPUT);  //MOSI PIN
    GPIO_voidSetPinDirection(GPIO_PORTB, PIN6, OUTPUT); //MISO PIN
    GPIO_voidSetPinDirection(GPIO_PORTB, PIN7, INPUT);  //SCK  PIN

    /* CHOOSE SLAVE MODE */
    CLR_BIT(SPCR, 4);

    /* ENABLE SPI MODULE */
    SET_BIT(SPCR, 6);

#if SPI_INTERRUPT_MODE == ENABLE_SPI_INTERRUPT

    SET_BIT(SPCR, 7);

#elif SPI_INTERRUPT_MODE == DISABLE_SPI_INTERRUPT

    CLR_BIT(SPCR, 7);
#endif

#if SPI_DATA_ORDER == SEND_LSB_FIRST

    SET_BIT(SPCR, 5);

#elif SPI_DATA_ORDER == SEND_MSB_FIRST

    CLR_BIT(SPCR, 5);
#endif

#if SPI_CLOCK_POLARITY == IDLE_HIGH_POLARITY

    SET_BIT(SPCR, 3);

#elif SPI_CLOCK_POLARITY == IDLE_LOW_POLARITY

    CLR_BIT(SPCR, 3);
#endif

#if SPI_CLOCK_PHASE == READ_WRITE_PHASE

    CLR_BIT(SPCR, 2);

#elif SPI_CLOCK_PHASE == WRITE_READ_PHASE

    SET_BIT(SPCR, 2);
#endif

#if DOUBLE_SPEED_MODE == ENABLE_DOUBLE_SPEED_MODE

    SET_BIT(SPSR, 0);

#elif DOUBLE_SPEED_MODE == DISABLE_DOUBLE_SPEED_MODE

    CLR_BIT(SPSR, 0);
#endif

#if SPI_PRESCALER_VALUE == PRESCALLER_4

    CLR_BIT(SPCR, 0);
    CLR_BIT(SPCR, 1);

#elif SPI_PRESCALER_VALUE == PRESCALLER_16

    SET_BIT(SPCR, 0);
    CLR_BIT(SPCR, 1);
#elif SPI_PRESCALER_VALUE == PRESCALLER_64

    CLR_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);

#elif SPI_PRESCALER_VALUE == PRESCALLER_128

    SET_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);
#endif
}

void SPI_voidSendByte(u8 Copy_u8Data)
{
    SPDR = Copy_u8Data;
    while (GET_BIT(SPSR, 7) == 0);
}

u8 SPI_u8ReceiveByte()
{
    while (GET_BIT(SPSR, 7) == 0);
    return SPDR;
}

void SPI_voidSendString(u8 *Copy_DataString)
{
    u8 LOC_u8Iterator = 0;
    while (Copy_DataString[LOC_u8Iterator] != '\0')
    {
        SPI_voidSendByte(Copy_DataString[LOC_u8Iterator++]);
    }
}

void SPI_voidReceiveString(u8 *Copy_DataString)
{
    u8 LOC_u8Iterator = 0;
    Copy_DataString[LOC_u8Iterator] = SPI_u8ReceiveByte();
    while (Copy_DataString[LOC_u8Iterator] != '#')
    {
        Copy_DataString[++LOC_u8Iterator] = SPI_u8ReceiveByte();
    }
    Copy_DataString[LOC_u8Iterator] = '\0';
}

u8 SPI_SendReceiveSynch(u8 Copy_u8DataToTransmit)
{
    SPDR = Copy_u8DataToTransmit;
    /*  wait busy flage to finish*/
    while (GET_BIT(SPSR, 7) == 0);
    /* Return to receive data */
    return SPSR;
}
