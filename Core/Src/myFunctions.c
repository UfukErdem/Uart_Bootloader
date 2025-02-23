/*
 * myFunctions.c
 *
 *  Created on: Feb 17, 2025
 *      Author: L
 */
#include "myFunctions.h"

bool check_Sum(uint8_t *data,uint8_t *checkSum)
{

	if(*data == *checkSum)
		return 1;
	else
		return 0;

}

