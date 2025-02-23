################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/peripheralConfig/src/gpioConfig.c \
../Core/peripheralConfig/src/systemClockConfig.c \
../Core/peripheralConfig/src/timerConfig.c \
../Core/peripheralConfig/src/uartConfig.c 

OBJS += \
./Core/peripheralConfig/src/gpioConfig.o \
./Core/peripheralConfig/src/systemClockConfig.o \
./Core/peripheralConfig/src/timerConfig.o \
./Core/peripheralConfig/src/uartConfig.o 

C_DEPS += \
./Core/peripheralConfig/src/gpioConfig.d \
./Core/peripheralConfig/src/systemClockConfig.d \
./Core/peripheralConfig/src/timerConfig.d \
./Core/peripheralConfig/src/uartConfig.d 


# Each subdirectory must supply rules for building sources it contributes
Core/peripheralConfig/src/%.o Core/peripheralConfig/src/%.su Core/peripheralConfig/src/%.cyclo: ../Core/peripheralConfig/src/%.c Core/peripheralConfig/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Core/my_Bootloader/Inc" -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Core/peripheralConfig/Inc" -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Library/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Core/Include" -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Library/STM32Cube_FW_F4_V1.28.0/Drivers/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-peripheralConfig-2f-src

clean-Core-2f-peripheralConfig-2f-src:
	-$(RM) ./Core/peripheralConfig/src/gpioConfig.cyclo ./Core/peripheralConfig/src/gpioConfig.d ./Core/peripheralConfig/src/gpioConfig.o ./Core/peripheralConfig/src/gpioConfig.su ./Core/peripheralConfig/src/systemClockConfig.cyclo ./Core/peripheralConfig/src/systemClockConfig.d ./Core/peripheralConfig/src/systemClockConfig.o ./Core/peripheralConfig/src/systemClockConfig.su ./Core/peripheralConfig/src/timerConfig.cyclo ./Core/peripheralConfig/src/timerConfig.d ./Core/peripheralConfig/src/timerConfig.o ./Core/peripheralConfig/src/timerConfig.su ./Core/peripheralConfig/src/uartConfig.cyclo ./Core/peripheralConfig/src/uartConfig.d ./Core/peripheralConfig/src/uartConfig.o ./Core/peripheralConfig/src/uartConfig.su

.PHONY: clean-Core-2f-peripheralConfig-2f-src

