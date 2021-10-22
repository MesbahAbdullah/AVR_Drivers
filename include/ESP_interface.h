/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 28 JAN 2021                             */
/* Version     : V01                                     */
/* Brief       : ESP8266 driver                          */
/*********************************************************/

#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_h

void ESP8266_voidInit();
u8   ESP8266_u8ValidateCmd();
void ESP8266_voidConnectToWiFi   ( u8 * SSID , u8 * Password );
void ESP8266_voidConnectToSrvTcp ( u8 * Copy_u8Domain , u8 * Copy_u8Port );
void ESP8266_voidSendHttpReq     ( u8 * Copy_u8Key , u8 * Copy_u8Data , u8 * Copy_u8Length );
u8   ESP8266_u8ReceiveHttpReq    ( u8 * Copy_u8ChannelID , u8 * Copy_u8Length );

#endif 
