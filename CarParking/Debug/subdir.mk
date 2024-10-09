################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ultrasonic_Sensor.c \
../app.c \
../buzzer.c \
../gpio.c \
../icu.c \
../lcd.c \
../leds.c 

OBJS += \
./Ultrasonic_Sensor.o \
./app.o \
./buzzer.o \
./gpio.o \
./icu.o \
./lcd.o \
./leds.o 

C_DEPS += \
./Ultrasonic_Sensor.d \
./app.d \
./buzzer.d \
./gpio.d \
./icu.d \
./lcd.d \
./leds.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


