/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 24 JAN 2021                             */
/* Version     : V01                                     */
/* Brief       : ADC  driver                             */
/*********************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H


/*********************************************************/
/* 1-AREF_SOURCE                                         */
/* 2-AVCC_SOURCE                                         */
/* 3-INTERNAL_SOURCE                                     */
/*********************************************************/
#define   ADC_VOLTAGE_REFERNCE         AREF_SOURCE   

/*********************************************************/
/* 1-RIGHT_ADJUST                                        */
/* 2-LEFT_ADJUST                                         */
/*********************************************************/
#define   ADC_ADjUST                   RIGHT_ADJUST      

/*********************************************************/
/* 1-CHANNEL0                                            */
/* 2-CHANNEL1                                            */
/* 3-CHANNEL2                                            */
/* 4-CHANNEL3                                            */
/* 5-CHANNEL4                                            */
/* 6-CHANNEL5                                            */
/* 7-CHANNEL6                                            */
/* 8-CHANNEL7                                            */
/*********************************************************/
#define   ADC_CHANNEL                  CHANNEL1          

/*********************************************************/
/* 1-PRESCALER2                                          */
/* 2-PRESCALER4                                          */
/* 3-PRESCALER8                                          */
/* 4-PRESCALER16                                         */
/* 5-PRESCALER128                                        */
/*********************************************************/
#define   ADC_PRESCALER                PRESCALER128      

/*********************************************************/
/* 1-ADC_INT_ENABLED                                     */
/* 2-ADC_INT_DISABLED                                    */
/*********************************************************/
#define   ADC_INTERRUPT_STATUS         ADC_INT_DISABLED  

/*********************************************************/
/* 1-AUTO_RUNNING_MODE                                   */
/* 2-EXTERNAL_INT0                                       */
/*********************************************************/
#define   ADC_CONVERSION_TRIGGER       AUTO_RUNNING_MODE   

#endif 
