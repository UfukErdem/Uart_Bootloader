/*
 * gpioConfig.c
 *
 *  Created on: Feb 15, 2025
 *      Author: L
 */
#include "gpioConfig.h"
#include "main.h"


void gpioInit(void)
{
	  GPIO_InitTypeDef GPIO_InitStruct = {0};
	/* USER CODE BEGIN MX_GPIO_Init_1 */
	/* USER CODE END MX_GPIO_Init_1 */

	  /* GPIO Ports Clock Enable */
	  __HAL_RCC_GPIOH_CLK_ENABLE();
	  __HAL_RCC_GPIOA_CLK_ENABLE();
	  __HAL_RCC_GPIOD_CLK_ENABLE();

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

	  /*Configure GPIO pins : PD12 PD13 PD14 PD15 */
	  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);

	  GPIO_InitStruct.Pin = GPIO_PIN_0;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);



}

