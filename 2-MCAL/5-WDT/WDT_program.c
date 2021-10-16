/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 15 Jul 2021                             */
/* Version     : V01                                     */
/* Brief       : WDT driver                              */
/*********************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"

void WDT_voidON(void)
{
	SET_BIT(WDTCR, WDE);

#if WDT_TIME == 2
	SET_BIT(WDTCR, WDP2);
	SET_BIT(WDTCR, WDP1);
	SET_BIT(WDTCR, WDP0);

#elif WDT_TIME == 1
	SET_BIT(WDTCR, WDP2);
	SET_BIT(WDTCR, WDP1);
	CLR_BIT(WDTCR, WDP0);

#elif WDT_TIME == 52
	SET_BIT(WDTCR, WDP2);
	CLR_BIT(WDTCR, WDP1);
	SET_BIT(WDTCR, WDP0);

#elif WDT_TIME == 26
	SET_BIT(WDTCR, WDP2);
	CLR_BIT(WDTCR, WDP1);
	CLR_BIT(WDTCR, WDP0);

#elif WDT_TIME == 13
	CLR_BIT(WDTCR, WDP2);
	SET_BIT(WDTCR, WDP1);
	SET_BIT(WDTCR, WDP0);

#elif WDT_TIME == 65
	CLR_BIT(WDTCR, WDP2);
	SET_BIT(WDTCR, WDP1);
	CLR_BIT(WDTCR, WDP0);

#elif WDT_TIME == 32
	CLR_BIT(WDTCR, WDP2);
	CLR_BIT(WDTCR, WDP1);
	SET_BIT(WDTCR, WDP0);

#elif WDT_TIME == 16
	CLR_BIT(WDTCR, WDP2);
	CLR_BIT(WDTCR, WDP1);
	CLR_BIT(WDTCR, WDP0);
#endif
}

void WDT_voidOFF(void)
{

	/* turning WDT off sequence */
	WDTCR = (1 << WDTOE) | (1 << WDE);
	WDTCR = 0x00;
}
