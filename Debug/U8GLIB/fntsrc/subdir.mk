################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../U8GLIB/fntsrc/u8g_font_8x13B.c \
../U8GLIB/fntsrc/u8g_font_9x15B.c \
../U8GLIB/fntsrc/u8g_font_9x18B.c \
../U8GLIB/fntsrc/u8g_font_9x18_75r.c \
../U8GLIB/fntsrc/u8g_font_9x18_78_79.c \
../U8GLIB/fntsrc/u8g_font_fub17r.c \
../U8GLIB/fntsrc/u8g_font_helvb08.c \
../U8GLIB/fntsrc/u8g_font_helvb10.c \
../U8GLIB/fntsrc/u8g_font_profont10.c \
../U8GLIB/fntsrc/u8g_font_profont11.c \
../U8GLIB/fntsrc/u8g_font_profont12.c \
../U8GLIB/fntsrc/u8g_font_profont15.c \
../U8GLIB/fntsrc/u8g_font_profont17.c \
../U8GLIB/fntsrc/u8g_font_profont22.c \
../U8GLIB/fntsrc/u8g_font_profont22r.c \
../U8GLIB/fntsrc/u8g_font_profont29.c \
../U8GLIB/fntsrc/u8g_font_profont29r.c 

OBJS += \
./U8GLIB/fntsrc/u8g_font_8x13B.o \
./U8GLIB/fntsrc/u8g_font_9x15B.o \
./U8GLIB/fntsrc/u8g_font_9x18B.o \
./U8GLIB/fntsrc/u8g_font_9x18_75r.o \
./U8GLIB/fntsrc/u8g_font_9x18_78_79.o \
./U8GLIB/fntsrc/u8g_font_fub17r.o \
./U8GLIB/fntsrc/u8g_font_helvb08.o \
./U8GLIB/fntsrc/u8g_font_helvb10.o \
./U8GLIB/fntsrc/u8g_font_profont10.o \
./U8GLIB/fntsrc/u8g_font_profont11.o \
./U8GLIB/fntsrc/u8g_font_profont12.o \
./U8GLIB/fntsrc/u8g_font_profont15.o \
./U8GLIB/fntsrc/u8g_font_profont17.o \
./U8GLIB/fntsrc/u8g_font_profont22.o \
./U8GLIB/fntsrc/u8g_font_profont22r.o \
./U8GLIB/fntsrc/u8g_font_profont29.o \
./U8GLIB/fntsrc/u8g_font_profont29r.o 

C_DEPS += \
./U8GLIB/fntsrc/u8g_font_8x13B.d \
./U8GLIB/fntsrc/u8g_font_9x15B.d \
./U8GLIB/fntsrc/u8g_font_9x18B.d \
./U8GLIB/fntsrc/u8g_font_9x18_75r.d \
./U8GLIB/fntsrc/u8g_font_9x18_78_79.d \
./U8GLIB/fntsrc/u8g_font_fub17r.d \
./U8GLIB/fntsrc/u8g_font_helvb08.d \
./U8GLIB/fntsrc/u8g_font_helvb10.d \
./U8GLIB/fntsrc/u8g_font_profont10.d \
./U8GLIB/fntsrc/u8g_font_profont11.d \
./U8GLIB/fntsrc/u8g_font_profont12.d \
./U8GLIB/fntsrc/u8g_font_profont15.d \
./U8GLIB/fntsrc/u8g_font_profont17.d \
./U8GLIB/fntsrc/u8g_font_profont22.d \
./U8GLIB/fntsrc/u8g_font_profont22r.d \
./U8GLIB/fntsrc/u8g_font_profont29.d \
./U8GLIB/fntsrc/u8g_font_profont29r.d 


# Each subdirectory must supply rules for building sources it contributes
U8GLIB/fntsrc/%.o U8GLIB/fntsrc/%.su: ../U8GLIB/fntsrc/%.c U8GLIB/fntsrc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F031x6 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/LucasLaurindo/Documents/ENGENHARIA/PRESSOR/Workspace_current/Irrigador_Smart_v4/U8GLIB/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-U8GLIB-2f-fntsrc

clean-U8GLIB-2f-fntsrc:
	-$(RM) ./U8GLIB/fntsrc/u8g_font_8x13B.d ./U8GLIB/fntsrc/u8g_font_8x13B.o ./U8GLIB/fntsrc/u8g_font_8x13B.su ./U8GLIB/fntsrc/u8g_font_9x15B.d ./U8GLIB/fntsrc/u8g_font_9x15B.o ./U8GLIB/fntsrc/u8g_font_9x15B.su ./U8GLIB/fntsrc/u8g_font_9x18B.d ./U8GLIB/fntsrc/u8g_font_9x18B.o ./U8GLIB/fntsrc/u8g_font_9x18B.su ./U8GLIB/fntsrc/u8g_font_9x18_75r.d ./U8GLIB/fntsrc/u8g_font_9x18_75r.o ./U8GLIB/fntsrc/u8g_font_9x18_75r.su ./U8GLIB/fntsrc/u8g_font_9x18_78_79.d ./U8GLIB/fntsrc/u8g_font_9x18_78_79.o ./U8GLIB/fntsrc/u8g_font_9x18_78_79.su ./U8GLIB/fntsrc/u8g_font_fub17r.d ./U8GLIB/fntsrc/u8g_font_fub17r.o ./U8GLIB/fntsrc/u8g_font_fub17r.su ./U8GLIB/fntsrc/u8g_font_helvb08.d ./U8GLIB/fntsrc/u8g_font_helvb08.o ./U8GLIB/fntsrc/u8g_font_helvb08.su ./U8GLIB/fntsrc/u8g_font_helvb10.d ./U8GLIB/fntsrc/u8g_font_helvb10.o ./U8GLIB/fntsrc/u8g_font_helvb10.su ./U8GLIB/fntsrc/u8g_font_profont10.d ./U8GLIB/fntsrc/u8g_font_profont10.o ./U8GLIB/fntsrc/u8g_font_profont10.su ./U8GLIB/fntsrc/u8g_font_profont11.d ./U8GLIB/fntsrc/u8g_font_profont11.o ./U8GLIB/fntsrc/u8g_font_profont11.su ./U8GLIB/fntsrc/u8g_font_profont12.d ./U8GLIB/fntsrc/u8g_font_profont12.o ./U8GLIB/fntsrc/u8g_font_profont12.su ./U8GLIB/fntsrc/u8g_font_profont15.d ./U8GLIB/fntsrc/u8g_font_profont15.o ./U8GLIB/fntsrc/u8g_font_profont15.su ./U8GLIB/fntsrc/u8g_font_profont17.d ./U8GLIB/fntsrc/u8g_font_profont17.o ./U8GLIB/fntsrc/u8g_font_profont17.su ./U8GLIB/fntsrc/u8g_font_profont22.d ./U8GLIB/fntsrc/u8g_font_profont22.o ./U8GLIB/fntsrc/u8g_font_profont22.su ./U8GLIB/fntsrc/u8g_font_profont22r.d ./U8GLIB/fntsrc/u8g_font_profont22r.o ./U8GLIB/fntsrc/u8g_font_profont22r.su ./U8GLIB/fntsrc/u8g_font_profont29.d ./U8GLIB/fntsrc/u8g_font_profont29.o ./U8GLIB/fntsrc/u8g_font_profont29.su ./U8GLIB/fntsrc/u8g_font_profont29r.d ./U8GLIB/fntsrc/u8g_font_profont29r.o ./U8GLIB/fntsrc/u8g_font_profont29r.su

.PHONY: clean-U8GLIB-2f-fntsrc

