################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/mySystemClock/src/systemClockConfig.c 

OBJS += \
./Core/mySystemClock/src/systemClockConfig.o 

C_DEPS += \
./Core/mySystemClock/src/systemClockConfig.d 


# Each subdirectory must supply rules for building sources it contributes
Core/mySystemClock/src/%.o Core/mySystemClock/src/%.su Core/mySystemClock/src/%.cyclo: ../Core/mySystemClock/src/%.c Core/mySystemClock/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Core/Include" -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Core/my_Uart/Inc" -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Core/my_GPIO/Inc" -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Core/mySystemClock/Inc" -I"C:/Users/L/Desktop/Stm_Bootloader_v1.0/uart_Bootloader/Core/my_Bootloader/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-mySystemClock-2f-src

clean-Core-2f-mySystemClock-2f-src:
	-$(RM) ./Core/mySystemClock/src/systemClockConfig.cyclo ./Core/mySystemClock/src/systemClockConfig.d ./Core/mySystemClock/src/systemClockConfig.o ./Core/mySystemClock/src/systemClockConfig.su

.PHONY: clean-Core-2f-mySystemClock-2f-src

