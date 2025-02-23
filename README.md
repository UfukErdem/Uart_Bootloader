Uart Bootlaoder Software for STM32F407VGT6

Sector 0-1 For bootloader
Sector 2-11 For Application

If you want to upload your application code to using this bootloader. You should change app start adress(0x08008000) and vector table(0x00008000) base adress.
