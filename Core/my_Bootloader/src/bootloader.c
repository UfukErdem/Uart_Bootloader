/*
 * bootloader.c
 *
 *  Created on: Feb 15, 2025
 *      Author: L
 */
#include "bootloader.h"

const uint32_t totalFlashSize = 1015808;		// Byte cinsinden değerdir.
												// Toplam hafızadan sector 0 bootloader yazılımı olduğu için çıkarılmıştır.

#define FLASH_MEM_SECTOR_2_BASE_ADRESS 0x8008000

static volatile uint32_t resetHandler_Adress = ((uint32_t)FLASH_MEM_SECTOR_2_BASE_ADRESS + 4);

void jump_Application_Code(void)
{
	//static volatile void (*jump_Application_Code_Handler) (void);
	void (*jump_Application_Code_Handler)(void);

	uint32_t mspValue = *(volatile uint32_t*)FLASH_MEM_SECTOR_2_BASE_ADRESS;

	__set_MSP(mspValue);

	//uint32_t resetHandler_Adress = (void *)*(volatile uint32_t *)(FLASH_MEM_SECTOR_2_BASE_ADRESS + 4);

	resetHandler_Adress =  *(__IO uint32_t*) resetHandler_Adress;

	jump_Application_Code_Handler = (void*) resetHandler_Adress;

	SCB->VTOR = resetHandler_Adress;

	jump_Application_Code_Handler();

}

bool isEnoughFlashSizeForAppCode(uint32_t *appCodeSize)
{
	if(*appCodeSize <= totalFlashSize)
		return 1;
	else
		return 0;

}





