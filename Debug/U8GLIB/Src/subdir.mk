################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../U8GLIB/Src/Display.c \
../U8GLIB/Src/fonts.c \
../U8GLIB/Src/u8g_com_arm_stm32.c 

OBJS += \
./U8GLIB/Src/Display.o \
./U8GLIB/Src/fonts.o \
./U8GLIB/Src/u8g_com_arm_stm32.o 

C_DEPS += \
./U8GLIB/Src/Display.d \
./U8GLIB/Src/fonts.d \
./U8GLIB/Src/u8g_com_arm_stm32.d 


# Each subdirectory must supply rules for building sources it contributes
U8GLIB/Src/%.o U8GLIB/Src/%.su: ../U8GLIB/Src/%.c U8GLIB/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F031x6 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/LucasLaurindo/Documents/ENGENHARIA/PRESSOR/Workspace_current/Irrigador_Smart_v4/U8GLIB/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-U8GLIB-2f-Src

clean-U8GLIB-2f-Src:
	-$(RM) ./U8GLIB/Src/Display.d ./U8GLIB/Src/Display.o ./U8GLIB/Src/Display.su ./U8GLIB/Src/fonts.d ./U8GLIB/Src/fonts.o ./U8GLIB/Src/fonts.su ./U8GLIB/Src/u8g_com_arm_stm32.d ./U8GLIB/Src/u8g_com_arm_stm32.o ./U8GLIB/Src/u8g_com_arm_stm32.su

.PHONY: clean-U8GLIB-2f-Src

