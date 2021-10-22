/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 24 JAN 2021                             */
/* Version     : V01                                     */
/* Brief       : ADC  driver                             */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_voidInit(void)
{
	ADMUX = 0; /* initial value for ADMUX */

#if ADC_VOLTAGE_REFERNCE == AVCC_SOURCE

	SET_BIT(ADMUX, 6);
	CLR_BIT(ADMUX, 7);

#elif ADC_VOLTAGE_REFERNCE == INTERNAL_SOURCE

	SET_BIT(ADMUX, 6);
	SET_BIT(ADMUX, 7);

#elif ADC_VOLTAGE_REFERNCE == AREF_SOURCE

	CLR_BIT(ADMUX, 6);
	CLR_BIT(ADMUX, 7);
#endif

#if ADC_ADjUST == RIGHT_ADJUST

	CLR_BIT(ADMUX, 5);

#elif ADC_ADjUST == LEFT_ADJUST

	SET_BIT(ADMUX, 5);
#endif

#if ADC_CONVERSION_TRIGGER == AUTO_RUNNING_MODE

	SET_BIT(ADCSRA, 5);

#elif ADC_CONVERSION_TRIGGER == EXTERNAL_INT0
	SET_BIT(SFIOR, 6);
#endif

#if ADC_PRESCALER == PRESCALER128

	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);

#elif ADC_PRESCALER == PRESCALER16

	SET_BIT(ADCSRA, 2);

#elif ADC_PRESCALER == PRESCALER8

	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);

#elif ADC_PRESCALER == PRESCALER4

	SET_BIT(ADCSRA, 1);

#elif ADC_PRESCALER == PRESCALER2
#endif

#if ADC_INTERRUPT_STATUS == ADC_INT_DISABLED

	CLR_BIT(ADCSRA, 3);

#elif ADC_INTERRUPT_STATUS == ADC_INT_ENABLED

	SET_BIT(SREG, 7);
	SET_BIT(ADCSRA, 3);
#endif

	/* Enable  ADC */
	SET_BIT(ADCSRA, 7);
}

u16 ADC_u16ReadChannel(u8 copy_channelNumber)
{
	copy_channelNumber &= 0x07;			/* channel number must be from 0 --> 7 */
	ADMUX &= 0xE0;						/* clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | copy_channelNumber; /* choose the correct channel by setting the channel number in MUX4:0 bits */
	u8 VALUE = 0;
	SET_BIT(ADCSRA, 6);
	while (GET_BIT(ADCSRA, 4) == 0)
		;
	VALUE = ADC_VAL;
	return VALUE;
}