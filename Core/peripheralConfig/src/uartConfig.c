/*
 * uartConfig.c
 *
 *  Created on: Feb 15, 2025
 *      Author: L
 */
#include "uartConfig.h"


void uart_Init(UART_HandleTypeDef *uart, uint32_t baudrate)
{
	HAL_StatusTypeDef statusUart;
	uart->Instance = UART4;
	uart->Init.BaudRate = baudrate;
	uart->Init.WordLength = UART_WORDLENGTH_8B;
	uart->Init.StopBits = UART_STOPBITS_1;
	uart->Init.Parity = UART_PARITY_NONE;
	uart->Init.Mode = UART_MODE_TX_RX;
	uart->Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart->Init.OverSampling = UART_OVERSAMPLING_16;

	statusUart = HAL_UART_Init(uart);
	if (statusUart != HAL_OK)
	{
		Error_Handler();
	}

}
