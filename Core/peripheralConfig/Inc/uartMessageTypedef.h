/*
 * uartMessageTypedef.h
 *
 *  Created on: Feb 15, 2025
 *      Author: L
 */

#ifndef MY_UART_INC_UARTMESSAGETYPEDEF_H_
#define MY_UART_INC_UARTMESSAGETYPEDEF_H_

typedef struct receiveMessage
{
	uint8_t data;
}receiveMessage;

typedef struct transmiteMessage
{
	uint8_t data;
}transmiteMessage;

typedef struct uartMessages
{
	receiveMessage receivedMessage;
	transmiteMessage transmitedMessage;
}uartMessages;

#endif /* MY_UART_INC_UARTMESSAGETYPEDEF_H_ */
