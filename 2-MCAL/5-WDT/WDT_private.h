/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 15 Jul 2021                             */
/* Version     : V01                                     */
/* Brief       : WDT driver                              */
/*********************************************************/

#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

#define WDTOE   4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0

#define WDTCR    *((volatile u8*) 0x21)

#endif // !WDT_PRIVATE_H
