/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 9 Sep 2021                              */
/* Version     : V01                                     */
/* Brief       : INT  driver                             */
/*********************************************************/

#ifndef INT_CONFIG_H
#define INT_CONFIG_H

/*********************************************************/
/*1-INT_TRIGGER_LOW_LEVEL                                */
/*2-INT_TRIGGER_ANY_CHANGE                               */
/*3-INT_TRIGGER_FALLING_EDGE                             */
/*4-INT_TRIGGER_RISING_EDGE                              */
/*********************************************************/
#define EXTERNAL_INT0_TRIGGER    INT_TRIGGER_RISING_EDGE

/*********************************************************/
/*1-INT_TRIGGER_LOW_LEVEL                                */
/*2-INT_TRIGGER_ANY_CHANGE                               */
/*3-INT_TRIGGER_FALLING_EDGE                             */
/*4-INT_TRIGGER_RISING_EDGE                              */
/*********************************************************/
#define EXTERNAL_INT1_TRIGGER    INT_TRIGGER_RISING_EDGE
/*********************************************************/
/*1-INT_TRIGGER_FALLING_EDGE                             */
/*2-INT_TRIGGER_RISING_EDGE                              */
/*********************************************************/
#define EXTERNAL_INT2_TRIGGER    INT_TRIGGER_RISING_EDGE

#endif 
