################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../U8GLIB/u8glib/u8g_bitmap.c \
../U8GLIB/u8glib/u8g_circle.c \
../U8GLIB/u8glib/u8g_clip.c \
../U8GLIB/u8glib/u8g_com_api.c \
../U8GLIB/u8glib/u8g_com_api_16gr.c \
../U8GLIB/u8glib/u8g_com_i2c.c \
../U8GLIB/u8glib/u8g_com_io.c \
../U8GLIB/u8glib/u8g_com_linux_ssd_i2c.c \
../U8GLIB/u8glib/u8g_com_msp430_hw_spi.c \
../U8GLIB/u8glib/u8g_com_null.c \
../U8GLIB/u8glib/u8g_com_psoc5_ssd_hw_parallel.c \
../U8GLIB/u8glib/u8g_com_raspberrypi_hw_spi.c \
../U8GLIB/u8glib/u8g_com_raspberrypi_ssd_i2c.c \
../U8GLIB/u8glib/u8g_com_std_sw_spi.c \
../U8GLIB/u8glib/u8g_cursor.c \
../U8GLIB/u8glib/u8g_delay.c \
../U8GLIB/u8glib/u8g_dev_null.c \
../U8GLIB/u8glib/u8g_dev_ssd1306_128x64.c \
../U8GLIB/u8glib/u8g_ellipse.c \
../U8GLIB/u8glib/u8g_font.c \
../U8GLIB/u8glib/u8g_line.c \
../U8GLIB/u8glib/u8g_ll_api.c \
../U8GLIB/u8glib/u8g_page.c \
../U8GLIB/u8glib/u8g_pb.c \
../U8GLIB/u8glib/u8g_pb14v1.c \
../U8GLIB/u8glib/u8g_pb16h1.c \
../U8GLIB/u8glib/u8g_pb16h2.c \
../U8GLIB/u8glib/u8g_pb16v1.c \
../U8GLIB/u8glib/u8g_pb16v2.c \
../U8GLIB/u8glib/u8g_pb32h1.c \
../U8GLIB/u8glib/u8g_pb8h1.c \
../U8GLIB/u8glib/u8g_pb8h1f.c \
../U8GLIB/u8glib/u8g_pb8h2.c \
../U8GLIB/u8glib/u8g_pb8h8.c \
../U8GLIB/u8glib/u8g_pb8v1.c \
../U8GLIB/u8glib/u8g_pb8v2.c \
../U8GLIB/u8glib/u8g_pbxh16.c \
../U8GLIB/u8glib/u8g_pbxh24.c \
../U8GLIB/u8glib/u8g_polygon.c \
../U8GLIB/u8glib/u8g_rect.c \
../U8GLIB/u8glib/u8g_rot.c \
../U8GLIB/u8glib/u8g_scale.c \
../U8GLIB/u8glib/u8g_state.c \
../U8GLIB/u8glib/u8g_u16toa.c \
../U8GLIB/u8glib/u8g_u8toa.c \
../U8GLIB/u8glib/u8g_virtual_screen.c 

OBJS += \
./U8GLIB/u8glib/u8g_bitmap.o \
./U8GLIB/u8glib/u8g_circle.o \
./U8GLIB/u8glib/u8g_clip.o \
./U8GLIB/u8glib/u8g_com_api.o \
./U8GLIB/u8glib/u8g_com_api_16gr.o \
./U8GLIB/u8glib/u8g_com_i2c.o \
./U8GLIB/u8glib/u8g_com_io.o \
./U8GLIB/u8glib/u8g_com_linux_ssd_i2c.o \
./U8GLIB/u8glib/u8g_com_msp430_hw_spi.o \
./U8GLIB/u8glib/u8g_com_null.o \
./U8GLIB/u8glib/u8g_com_psoc5_ssd_hw_parallel.o \
./U8GLIB/u8glib/u8g_com_raspberrypi_hw_spi.o \
./U8GLIB/u8glib/u8g_com_raspberrypi_ssd_i2c.o \
./U8GLIB/u8glib/u8g_com_std_sw_spi.o \
./U8GLIB/u8glib/u8g_cursor.o \
./U8GLIB/u8glib/u8g_delay.o \
./U8GLIB/u8glib/u8g_dev_null.o \
./U8GLIB/u8glib/u8g_dev_ssd1306_128x64.o \
./U8GLIB/u8glib/u8g_ellipse.o \
./U8GLIB/u8glib/u8g_font.o \
./U8GLIB/u8glib/u8g_line.o \
./U8GLIB/u8glib/u8g_ll_api.o \
./U8GLIB/u8glib/u8g_page.o \
./U8GLIB/u8glib/u8g_pb.o \
./U8GLIB/u8glib/u8g_pb14v1.o \
./U8GLIB/u8glib/u8g_pb16h1.o \
./U8GLIB/u8glib/u8g_pb16h2.o \
./U8GLIB/u8glib/u8g_pb16v1.o \
./U8GLIB/u8glib/u8g_pb16v2.o \
./U8GLIB/u8glib/u8g_pb32h1.o \
./U8GLIB/u8glib/u8g_pb8h1.o \
./U8GLIB/u8glib/u8g_pb8h1f.o \
./U8GLIB/u8glib/u8g_pb8h2.o \
./U8GLIB/u8glib/u8g_pb8h8.o \
./U8GLIB/u8glib/u8g_pb8v1.o \
./U8GLIB/u8glib/u8g_pb8v2.o \
./U8GLIB/u8glib/u8g_pbxh16.o \
./U8GLIB/u8glib/u8g_pbxh24.o \
./U8GLIB/u8glib/u8g_polygon.o \
./U8GLIB/u8glib/u8g_rect.o \
./U8GLIB/u8glib/u8g_rot.o \
./U8GLIB/u8glib/u8g_scale.o \
./U8GLIB/u8glib/u8g_state.o \
./U8GLIB/u8glib/u8g_u16toa.o \
./U8GLIB/u8glib/u8g_u8toa.o \
./U8GLIB/u8glib/u8g_virtual_screen.o 

C_DEPS += \
./U8GLIB/u8glib/u8g_bitmap.d \
./U8GLIB/u8glib/u8g_circle.d \
./U8GLIB/u8glib/u8g_clip.d \
./U8GLIB/u8glib/u8g_com_api.d \
./U8GLIB/u8glib/u8g_com_api_16gr.d \
./U8GLIB/u8glib/u8g_com_i2c.d \
./U8GLIB/u8glib/u8g_com_io.d \
./U8GLIB/u8glib/u8g_com_linux_ssd_i2c.d \
./U8GLIB/u8glib/u8g_com_msp430_hw_spi.d \
./U8GLIB/u8glib/u8g_com_null.d \
./U8GLIB/u8glib/u8g_com_psoc5_ssd_hw_parallel.d \
./U8GLIB/u8glib/u8g_com_raspberrypi_hw_spi.d \
./U8GLIB/u8glib/u8g_com_raspberrypi_ssd_i2c.d \
./U8GLIB/u8glib/u8g_com_std_sw_spi.d \
./U8GLIB/u8glib/u8g_cursor.d \
./U8GLIB/u8glib/u8g_delay.d \
./U8GLIB/u8glib/u8g_dev_null.d \
./U8GLIB/u8glib/u8g_dev_ssd1306_128x64.d \
./U8GLIB/u8glib/u8g_ellipse.d \
./U8GLIB/u8glib/u8g_font.d \
./U8GLIB/u8glib/u8g_line.d \
./U8GLIB/u8glib/u8g_ll_api.d \
./U8GLIB/u8glib/u8g_page.d \
./U8GLIB/u8glib/u8g_pb.d \
./U8GLIB/u8glib/u8g_pb14v1.d \
./U8GLIB/u8glib/u8g_pb16h1.d \
./U8GLIB/u8glib/u8g_pb16h2.d \
./U8GLIB/u8glib/u8g_pb16v1.d \
./U8GLIB/u8glib/u8g_pb16v2.d \
./U8GLIB/u8glib/u8g_pb32h1.d \
./U8GLIB/u8glib/u8g_pb8h1.d \
./U8GLIB/u8glib/u8g_pb8h1f.d \
./U8GLIB/u8glib/u8g_pb8h2.d \
./U8GLIB/u8glib/u8g_pb8h8.d \
./U8GLIB/u8glib/u8g_pb8v1.d \
./U8GLIB/u8glib/u8g_pb8v2.d \
./U8GLIB/u8glib/u8g_pbxh16.d \
./U8GLIB/u8glib/u8g_pbxh24.d \
./U8GLIB/u8glib/u8g_polygon.d \
./U8GLIB/u8glib/u8g_rect.d \
./U8GLIB/u8glib/u8g_rot.d \
./U8GLIB/u8glib/u8g_scale.d \
./U8GLIB/u8glib/u8g_state.d \
./U8GLIB/u8glib/u8g_u16toa.d \
./U8GLIB/u8glib/u8g_u8toa.d \
./U8GLIB/u8glib/u8g_virtual_screen.d 


# Each subdirectory must supply rules for building sources it contributes
U8GLIB/u8glib/%.o U8GLIB/u8glib/%.su: ../U8GLIB/u8glib/%.c U8GLIB/u8glib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F031x6 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/LucasLaurindo/Documents/ENGENHARIA/PRESSOR/Workspace_current/Irrigador_Smart_v4/U8GLIB/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-U8GLIB-2f-u8glib

clean-U8GLIB-2f-u8glib:
	-$(RM) ./U8GLIB/u8glib/u8g_bitmap.d ./U8GLIB/u8glib/u8g_bitmap.o ./U8GLIB/u8glib/u8g_bitmap.su ./U8GLIB/u8glib/u8g_circle.d ./U8GLIB/u8glib/u8g_circle.o ./U8GLIB/u8glib/u8g_circle.su ./U8GLIB/u8glib/u8g_clip.d ./U8GLIB/u8glib/u8g_clip.o ./U8GLIB/u8glib/u8g_clip.su ./U8GLIB/u8glib/u8g_com_api.d ./U8GLIB/u8glib/u8g_com_api.o ./U8GLIB/u8glib/u8g_com_api.su ./U8GLIB/u8glib/u8g_com_api_16gr.d ./U8GLIB/u8glib/u8g_com_api_16gr.o ./U8GLIB/u8glib/u8g_com_api_16gr.su ./U8GLIB/u8glib/u8g_com_i2c.d ./U8GLIB/u8glib/u8g_com_i2c.o ./U8GLIB/u8glib/u8g_com_i2c.su ./U8GLIB/u8glib/u8g_com_io.d ./U8GLIB/u8glib/u8g_com_io.o ./U8GLIB/u8glib/u8g_com_io.su ./U8GLIB/u8glib/u8g_com_linux_ssd_i2c.d ./U8GLIB/u8glib/u8g_com_linux_ssd_i2c.o ./U8GLIB/u8glib/u8g_com_linux_ssd_i2c.su ./U8GLIB/u8glib/u8g_com_msp430_hw_spi.d ./U8GLIB/u8glib/u8g_com_msp430_hw_spi.o ./U8GLIB/u8glib/u8g_com_msp430_hw_spi.su ./U8GLIB/u8glib/u8g_com_null.d ./U8GLIB/u8glib/u8g_com_null.o ./U8GLIB/u8glib/u8g_com_null.su ./U8GLIB/u8glib/u8g_com_psoc5_ssd_hw_parallel.d ./U8GLIB/u8glib/u8g_com_psoc5_ssd_hw_parallel.o ./U8GLIB/u8glib/u8g_com_psoc5_ssd_hw_parallel.su ./U8GLIB/u8glib/u8g_com_raspberrypi_hw_spi.d ./U8GLIB/u8glib/u8g_com_raspberrypi_hw_spi.o ./U8GLIB/u8glib/u8g_com_raspberrypi_hw_spi.su ./U8GLIB/u8glib/u8g_com_raspberrypi_ssd_i2c.d ./U8GLIB/u8glib/u8g_com_raspberrypi_ssd_i2c.o ./U8GLIB/u8glib/u8g_com_raspberrypi_ssd_i2c.su ./U8GLIB/u8glib/u8g_com_std_sw_spi.d ./U8GLIB/u8glib/u8g_com_std_sw_spi.o ./U8GLIB/u8glib/u8g_com_std_sw_spi.su ./U8GLIB/u8glib/u8g_cursor.d ./U8GLIB/u8glib/u8g_cursor.o ./U8GLIB/u8glib/u8g_cursor.su ./U8GLIB/u8glib/u8g_delay.d ./U8GLIB/u8glib/u8g_delay.o ./U8GLIB/u8glib/u8g_delay.su ./U8GLIB/u8glib/u8g_dev_null.d ./U8GLIB/u8glib/u8g_dev_null.o ./U8GLIB/u8glib/u8g_dev_null.su ./U8GLIB/u8glib/u8g_dev_ssd1306_128x64.d ./U8GLIB/u8glib/u8g_dev_ssd1306_128x64.o ./U8GLIB/u8glib/u8g_dev_ssd1306_128x64.su ./U8GLIB/u8glib/u8g_ellipse.d ./U8GLIB/u8glib/u8g_ellipse.o ./U8GLIB/u8glib/u8g_ellipse.su ./U8GLIB/u8glib/u8g_font.d ./U8GLIB/u8glib/u8g_font.o ./U8GLIB/u8glib/u8g_font.su ./U8GLIB/u8glib/u8g_line.d ./U8GLIB/u8glib/u8g_line.o ./U8GLIB/u8glib/u8g_line.su ./U8GLIB/u8glib/u8g_ll_api.d ./U8GLIB/u8glib/u8g_ll_api.o ./U8GLIB/u8glib/u8g_ll_api.su ./U8GLIB/u8glib/u8g_page.d ./U8GLIB/u8glib/u8g_page.o ./U8GLIB/u8glib/u8g_page.su ./U8GLIB/u8glib/u8g_pb.d ./U8GLIB/u8glib/u8g_pb.o ./U8GLIB/u8glib/u8g_pb.su ./U8GLIB/u8glib/u8g_pb14v1.d ./U8GLIB/u8glib/u8g_pb14v1.o ./U8GLIB/u8glib/u8g_pb14v1.su ./U8GLIB/u8glib/u8g_pb16h1.d ./U8GLIB/u8glib/u8g_pb16h1.o ./U8GLIB/u8glib/u8g_pb16h1.su ./U8GLIB/u8glib/u8g_pb16h2.d ./U8GLIB/u8glib/u8g_pb16h2.o ./U8GLIB/u8glib/u8g_pb16h2.su ./U8GLIB/u8glib/u8g_pb16v1.d ./U8GLIB/u8glib/u8g_pb16v1.o ./U8GLIB/u8glib/u8g_pb16v1.su ./U8GLIB/u8glib/u8g_pb16v2.d ./U8GLIB/u8glib/u8g_pb16v2.o ./U8GLIB/u8glib/u8g_pb16v2.su ./U8GLIB/u8glib/u8g_pb32h1.d ./U8GLIB/u8glib/u8g_pb32h1.o ./U8GLIB/u8glib/u8g_pb32h1.su ./U8GLIB/u8glib/u8g_pb8h1.d ./U8GLIB/u8glib/u8g_pb8h1.o ./U8GLIB/u8glib/u8g_pb8h1.su ./U8GLIB/u8glib/u8g_pb8h1f.d ./U8GLIB/u8glib/u8g_pb8h1f.o ./U8GLIB/u8glib/u8g_pb8h1f.su ./U8GLIB/u8glib/u8g_pb8h2.d ./U8GLIB/u8glib/u8g_pb8h2.o ./U8GLIB/u8glib/u8g_pb8h2.su ./U8GLIB/u8glib/u8g_pb8h8.d ./U8GLIB/u8glib/u8g_pb8h8.o ./U8GLIB/u8glib/u8g_pb8h8.su ./U8GLIB/u8glib/u8g_pb8v1.d ./U8GLIB/u8glib/u8g_pb8v1.o ./U8GLIB/u8glib/u8g_pb8v1.su ./U8GLIB/u8glib/u8g_pb8v2.d ./U8GLIB/u8glib/u8g_pb8v2.o ./U8GLIB/u8glib/u8g_pb8v2.su ./U8GLIB/u8glib/u8g_pbxh16.d ./U8GLIB/u8glib/u8g_pbxh16.o ./U8GLIB/u8glib/u8g_pbxh16.su ./U8GLIB/u8glib/u8g_pbxh24.d ./U8GLIB/u8glib/u8g_pbxh24.o ./U8GLIB/u8glib/u8g_pbxh24.su ./U8GLIB/u8glib/u8g_polygon.d ./U8GLIB/u8glib/u8g_polygon.o ./U8GLIB/u8glib/u8g_polygon.su ./U8GLIB/u8glib/u8g_rect.d ./U8GLIB/u8glib/u8g_rect.o ./U8GLIB/u8glib/u8g_rect.su ./U8GLIB/u8glib/u8g_rot.d ./U8GLIB/u8glib/u8g_rot.o ./U8GLIB/u8glib/u8g_rot.su ./U8GLIB/u8glib/u8g_scale.d ./U8GLIB/u8glib/u8g_scale.o ./U8GLIB/u8glib/u8g_scale.su ./U8GLIB/u8glib/u8g_state.d ./U8GLIB/u8glib/u8g_state.o ./U8GLIB/u8glib/u8g_state.su ./U8GLIB/u8glib/u8g_u16toa.d ./U8GLIB/u8glib/u8g_u16toa.o ./U8GLIB/u8glib/u8g_u16toa.su ./U8GLIB/u8glib/u8g_u8toa.d ./U8GLIB/u8glib/u8g_u8toa.o ./U8GLIB/u8glib/u8g_u8toa.su ./U8GLIB/u8glib/u8g_virtual_screen.d ./U8GLIB/u8glib/u8g_virtual_screen.o ./U8GLIB/u8glib/u8g_virtual_screen.su

.PHONY: clean-U8GLIB-2f-u8glib

