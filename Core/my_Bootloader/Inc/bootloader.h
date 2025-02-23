/*
 * bootloader.h
 *
 *  Created on: Feb 15, 2025
 *      Author: L
 */

#ifndef MY_BOOTLOADER_BOOTLOADER_H_
#define MY_BOOTLOADER_BOOTLOADER_H_

#include "main.h"
#include <stdint.h>
#include <stdbool.h>




#define UART_BOOTMODE_ACK				41
#define UART_BOOTMODE_NACK				42
#define UART_TAKE_BOOTMODE_COMMAND		43
#define UART_FLASH_SIZE_CHECK_COMMAND	44
#define UART_SEND_BYTE_COMMAND			45
#define SYSTEM_RESET_COMMAND			46

void jump_Application_Code(void);

bool isEnoughFlashSizeForAppCode(uint32_t *appCodeSize);

#endif /* MY_BOOTLOADER_BOOTLOADER_H_ */
