################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/my_Bootloader/src/bootloader.c 

OBJS += \
./Core/my_Bootloader/src/bootloader.o 

C_DEPS += \
./Core/my_Bootloader/src/bootloader.d 


# Each subdirectory must supply rules for building sources it contributes
Core/my_Bootloader/src/%.o Core/my_Bootloader/src/%.su Core/my_Bootloader/src/%.cyclo: ../Core/my_Bootloader/src/%.c Core/my_Bootloader/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Core/my_Bootloader/Inc" -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Core/peripheralConfig/Inc" -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Library/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Core/Include" -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Library/STM32Cube_FW_F4_V1.28.0/Drivers/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-my_Bootloader-2f-src

clean-Core-2f-my_Bootloader-2f-src:
	-$(RM) ./Core/my_Bootloader/src/bootloader.cyclo ./Core/my_Bootloader/src/bootloader.d ./Core/my_Bootloader/src/bootloader.o ./Core/my_Bootloader/src/bootloader.su

.PHONY: clean-Core-2f-my_Bootloader-2f-src

