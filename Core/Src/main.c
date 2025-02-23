/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
uartMessages uartMessagesMailBox;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */
const uint32_t APPLICATON_START_BASE_ADRESS = 0x08008000;	// SECTOR 1
/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define UART4_BAUDRATE 230400

//SFFSww

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
UART_HandleTypeDef huart4;

uint8_t timCounter = 0;
uint8_t received_data[3];
uint8_t flashSizeByte_Counter = 0;

uint32_t appFlashSize = 0;
uint32_t appStartBaseAdress = APPLICATON_START_BASE_ADRESS;

volatile bool check_jumpApplicationCode = false;

/* USER CODE BEGIN PV */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart == &huart4)
	{

		if(!__HAL_UART_GET_FLAG(&huart4,UART_FLAG_RXNE))
		{

			HAL_UART_Receive_IT(&huart4, received_data, 3);

			uint8_t data = (received_data[0] + received_data[1]) / 2;

			if(check_Sum(&data, &received_data[2]))
			{
				switch (received_data[0])
				{
					case UART_TAKE_BOOTMODE_COMMAND:

						if(received_data[1] == 0x41)
						{
							uint8_t ACK[2] = {UART_BOOTMODE_ACK,'\n'};
							HAL_UART_Transmit_IT(&huart4, (uint8_t*)&ACK, 2);
							HAL_TIM_Base_Stop_IT(&htim2);

						}
#ifdef DEBUG_MONITOR
						HAL_UART_Transmit_IT(&huart4, (uint8_t*)"mCU is BootMode\n", 16);
#endif

						break;

					case UART_FLASH_SIZE_CHECK_COMMAND:

						if(flashSizeByte_Counter == 0)
						{
							appFlashSize = (uint32_t)received_data[1];
							flashSizeByte_Counter++;
						}
						else if(flashSizeByte_Counter == 1)
						{
							appFlashSize |= (uint32_t)received_data[1] << 8;
							flashSizeByte_Counter++;
						}
						else if(flashSizeByte_Counter == 2)
						{
							appFlashSize |= (uint32_t)received_data[1] << 16;
							flashSizeByte_Counter++;
						}
						else if(flashSizeByte_Counter == 3)
						{
							flashSizeByte_Counter = 0;
							appFlashSize |= (uint32_t)received_data[1] << 24;

							if(isEnoughFlashSizeForAppCode(&appFlashSize))
							{
								uint8_t ACK[2] = {UART_BOOTMODE_ACK,'\n'};
								HAL_UART_Transmit_IT(&huart4, (uint8_t*)&ACK, 2);
							}
							else
							{
								uint8_t NACK[2] = {UART_BOOTMODE_NACK,'\n'};
								HAL_UART_Transmit_IT(&huart4, (uint8_t*)&NACK, 2);
							}

						}

						break;

					case UART_SEND_BYTE_COMMAND:

						HAL_StatusTypeDef flashWriteStatus;

						HAL_FLASH_Unlock();

						flashWriteStatus = HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, appStartBaseAdress, received_data[1]);

						if(flashWriteStatus == HAL_OK)
						{
							appStartBaseAdress += 1;
							uint8_t ACK[2] = {UART_BOOTMODE_ACK,'\n'};
							HAL_UART_Transmit_IT(&huart4, (uint8_t*)&ACK, 2);
						}
						else
						{
							uint8_t NACK[2] = {UART_BOOTMODE_NACK,'\n'};
							HAL_UART_Transmit_IT(&huart4, (uint8_t*)&NACK, 2);
						}

						HAL_FLASH_Lock();
						break;

					case SYSTEM_RESET_COMMAND:

						NVIC_SystemReset();

						break;

				}
			}

			__HAL_UART_CLEAR_FLAG(&huart4,UART_FLAG_RXNE);
		}


		if(__HAL_UART_GET_FLAG(&huart4,UART_FLAG_TC))
		{
			//HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
			__HAL_UART_CLEAR_FLAG(&huart4,UART_FLAG_TC);
		}

	}

}

void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

	if(__HAL_TIM_GET_FLAG(&htim2,TIM_FLAG_UPDATE))
	{

		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
		HAL_UART_Transmit_IT(&huart4, (uint8_t*)"Waiting Boot Mode Message\n", 26);

		if(timCounter >= 15)
		{
			check_jumpApplicationCode = true;
			HAL_TIM_Base_Stop_IT(&htim2);
		}

		timCounter++;

		__HAL_TIM_CLEAR_FLAG(&htim2,TIM_FLAG_UPDATE);

	}


  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */

  /* USER CODE BEGIN 2 */
  systemClockInit();
  uart_Init(&huart4,(uint32_t)UART4_BAUDRATE);
  gpioInit();
  initTimer2();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_UART_Receive_IT(&huart4, received_data, 3);
  HAL_TIM_Base_Start_IT(&htim2);

  HAL_Delay(10);

  while (1)
  {

	if(check_jumpApplicationCode)
	{
		HAL_RCC_DeInit();
		HAL_UART_DeInit(&huart4);
		HAL_TIM_Base_DeInit(&htim2);
		HAL_DeInit();
		jump_Application_Code();
	}

	HAL_Delay(1);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
