/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 9 Sep 2021                              */
/* Version     : V01                                     */
/* Brief       : INT  driver                             */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "INT_interface.h"
#include "INT_private.h"
#include "INT_config.h"

void INT0_voidInit()
{
	/* Global interrupt enable */
	SET_BIT(SREG, 7);

	/* Enable INT0 */
	SET_BIT(GICR, 6);

#if EXTERNAL_INT0_TRIGGER == INT_TRIGGER_RISING_EDGE
	SET_BIT(MCUCR, 0);
	SET_BIT(MCUCR, 1);

#elif EXTERNAL_INT0_TRIGGER == INT_TRIGGER_FALLING_EDGE
	SET_BIT(MCUCR, 1);
	CLR_BIT(MCUCR, 0);

#elif EXTERNAL_INT0_TRIGGER == INT_TRIGGER_LOW_LEVEL
	CLR_BIT(MCUCR, 0);
	CLR_BIT(MCUCR, 1);

#elif EXTERNAL_INT0_TRIGGER == INT_TRIGGER_ANY_CHANGE
	SET_BIT(MCUCR, 0);
	CLR_BIT(MCUCR, 1);

#endif
}

void INT1_voidInit()
{
	/* Global interrupt enable */
	SET_BIT(SREG, 7);

	/* Enable INT1 */
	SET_BIT(GICR, 7);

#if EXTERNAL_INT1_TRIGGER == INT_TRIGGER_RISING_EDGE
	SET_BIT(MCUCR, 2);
	SET_BIT(MCUCR, 3);

#elif EXTERNAL_INT1_TRIGGER == INT_TRIGGER_FALLING_EDGE
	CLR_BIT(MCUCR, 2);
	SET_BIT(MCUCR, 3);

#elif EXTERNAL_INT1_TRIGGER == INT_TRIGGER_LOW_LEVEL
	CLR_BIT(MCUCR, 2);
	CLR_BIT(MCUCR, 3);

#elif EXTERNAL_INT1_TRIGGER == INT_TRIGGER_ANY_CHANGE
	SET_BIT(MCUCR, 2);
	CLR_BIT(MCUCR, 3);

#endif
}

void INT2_voidInit()
{
	/* Global interrupt enable */
	SET_BIT(SREG, 7);

	/* Enable INT2 */
	SET_BIT(GICR, 5);

#if EXTERNAL_INT2_TRIGGER == INT_TRIGGER_FALLING_EDGE
	CLR_BIT(MCUCSR, 6);

#elif EXTERNAL_INT2_TRIGGER == INT_TRIGGER_RISING_EDGE
	SET_BIT(MCUCSR, 6);

#endif
}