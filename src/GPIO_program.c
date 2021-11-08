/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 23 JAN 2021                             */
/* Version     : V01                                     */
/* Brief       : GPIO  driver                            */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

/* seeting the direction of the pin to be input or output */
void GPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8DIR)
{
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        if (Copy_u8DIR == INPUT)
            CLR_BIT(DDRA, Copy_u8Pin);
        else if (Copy_u8DIR == OUTPUT)
            SET_BIT(DDRA, Copy_u8Pin);
        break;
    case GPIO_PORTB:
        if (Copy_u8DIR == INPUT)
            CLR_BIT(DDRB, Copy_u8Pin);
        else if (Copy_u8DIR == OUTPUT)
            SET_BIT(DDRB, Copy_u8Pin);
        break;
    case GPIO_PORTC:
        if (Copy_u8DIR == INPUT)
            CLR_BIT(DDRC, Copy_u8Pin);
        else if (Copy_u8DIR == OUTPUT)
            SET_BIT(DDRC, Copy_u8Pin);
        break;
    case GPIO_PORTD:
        if (Copy_u8DIR == INPUT)
            CLR_BIT(DDRD, Copy_u8Pin);
        else if (Copy_u8DIR == OUTPUT)
            SET_BIT(DDRD, Copy_u8Pin);
        break;
    default:
        break;
    }
}

/* seeting the direction of the whole port to input or output */
void GPIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8DIR)
{
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        if (Copy_u8DIR == INPUT)
            DDRA = 0;
        else if (Copy_u8DIR == OUTPUT)
            DDRA = 0xff;
        break;
    case GPIO_PORTB:
        if (Copy_u8DIR == INPUT)
            DDRB = 0;
        else if (Copy_u8DIR == OUTPUT)
            DDRB = 0xff;
        break;
    case GPIO_PORTC:
        if (Copy_u8DIR == INPUT)
            DDRC = 0;
        else if (Copy_u8DIR == OUTPUT)
            DDRC = 0xff;
        break;
    case GPIO_PORTD:
        if (Copy_u8DIR == INPUT)
            DDRD = 0;
        else if (Copy_u8DIR == OUTPUT)
            DDRD = 0xff;
        break;
    default:
        break;
    }
}

/* setting the value to pin to be High or low */
void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        if (Copy_u8Value == LOW)
            CLR_BIT(PORTA, Copy_u8Pin);
        else if (Copy_u8Value == HIGH)
            SET_BIT(PORTA, Copy_u8Pin);
        break;
    case GPIO_PORTB:
        if (Copy_u8Value == LOW)
            CLR_BIT(PORTB, Copy_u8Pin);
        else if (Copy_u8Value == HIGH)
            SET_BIT(PORTB, Copy_u8Pin);
        break;
    case GPIO_PORTC:
        if (Copy_u8Value == LOW)
            CLR_BIT(PORTC, Copy_u8Pin);
        else if (Copy_u8Value == HIGH)
            SET_BIT(PORTC, Copy_u8Pin);
        break;
    case GPIO_PORTD:
        if (Copy_u8Value == LOW)
            CLR_BIT(PORTD, Copy_u8Pin);
        else if (Copy_u8Value == HIGH)
            SET_BIT(PORTD, Copy_u8Pin);
        break;
    default:
        break;
    }
}

/* getting the value of pin */
u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    u8 LOC_u8Result = 0;
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        LOC_u8Result = GET_BIT(PINA, Copy_u8Pin);
        break;
    case GPIO_PORTB:
        LOC_u8Result = GET_BIT(PINB, Copy_u8Pin);
        break;
    case GPIO_PORTC:
        LOC_u8Result = GET_BIT(PINC, Copy_u8Pin);
        break;
    case GPIO_PORTD:
        LOC_u8Result = GET_BIT(PIND, Copy_u8Pin);
        break;
    default:
        break;
    }
    return LOC_u8Result;
}
/* the internal pullup option */
void GPIO_voidSetPullUps(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        SET_BIT(PORTA, Copy_u8Pin);
        break;

    case GPIO_PORTB:
        SET_BIT(PORTB, Copy_u8Pin);
        break;

    case GPIO_PORTC:
        SET_BIT(PORTC, Copy_u8Pin);
        break;

    case GPIO_PORTD:
        SET_BIT(PORTD, Copy_u8Pin);
        break;

    default:
        break;
    }
}
