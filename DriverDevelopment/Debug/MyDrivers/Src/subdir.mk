################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MyDrivers/Src/EXTI.c \
../MyDrivers/Src/GPIO.c \
../MyDrivers/Src/I2C.c \
../MyDrivers/Src/RCC.c \
../MyDrivers/Src/SPI.c \
../MyDrivers/Src/USART.c 

OBJS += \
./MyDrivers/Src/EXTI.o \
./MyDrivers/Src/GPIO.o \
./MyDrivers/Src/I2C.o \
./MyDrivers/Src/RCC.o \
./MyDrivers/Src/SPI.o \
./MyDrivers/Src/USART.o 

C_DEPS += \
./MyDrivers/Src/EXTI.d \
./MyDrivers/Src/GPIO.d \
./MyDrivers/Src/I2C.d \
./MyDrivers/Src/RCC.d \
./MyDrivers/Src/SPI.d \
./MyDrivers/Src/USART.d 


# Each subdirectory must supply rules for building sources it contributes
MyDrivers/Src/%.o MyDrivers/Src/%.su: ../MyDrivers/Src/%.c MyDrivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -c -I../Inc -I"C:/Users/HP/STM32CubeIDE/DriverDevelopment/MyDrivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MyDrivers-2f-Src

clean-MyDrivers-2f-Src:
	-$(RM) ./MyDrivers/Src/EXTI.d ./MyDrivers/Src/EXTI.o ./MyDrivers/Src/EXTI.su ./MyDrivers/Src/GPIO.d ./MyDrivers/Src/GPIO.o ./MyDrivers/Src/GPIO.su ./MyDrivers/Src/I2C.d ./MyDrivers/Src/I2C.o ./MyDrivers/Src/I2C.su ./MyDrivers/Src/RCC.d ./MyDrivers/Src/RCC.o ./MyDrivers/Src/RCC.su ./MyDrivers/Src/SPI.d ./MyDrivers/Src/SPI.o ./MyDrivers/Src/SPI.su ./MyDrivers/Src/USART.d ./MyDrivers/Src/USART.o ./MyDrivers/Src/USART.su

.PHONY: clean-MyDrivers-2f-Src

