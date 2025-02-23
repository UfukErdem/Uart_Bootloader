/*
 * uartConfig.h
 *
 *  Created on: Feb 15, 2025
 *      Author: L
 */

#ifndef MY_UART_INC_UARTCONFIG_H_
#define MY_UART_INC_UARTCONFIG_H_

#include "main.h"
#include "uartMessageTypedef.h"

void uart_Init(UART_HandleTypeDef *uart, uint32_t baudrate);



#endif /* MY_UART_INC_UARTCONFIG_H_ */
