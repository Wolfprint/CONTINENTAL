################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/mcl/ARM_SysTick.c" \
"../Sources/mcl/CrystalClock.c" \
"../Sources/mcl/IO_PinCfg.c" \
"../Sources/mcl/interrupts.c" \
"../Sources/mcl/sysinit.c" \
"../Sources/mcl/uart.c" \

C_SRCS += \
../Sources/mcl/ARM_SysTick.c \
../Sources/mcl/CrystalClock.c \
../Sources/mcl/IO_PinCfg.c \
../Sources/mcl/interrupts.c \
../Sources/mcl/sysinit.c \
../Sources/mcl/uart.c \

OBJS += \
./Sources/mcl/ARM_SysTick.o \
./Sources/mcl/CrystalClock.o \
./Sources/mcl/IO_PinCfg.o \
./Sources/mcl/interrupts.o \
./Sources/mcl/sysinit.o \
./Sources/mcl/uart.o \

C_DEPS += \
./Sources/mcl/ARM_SysTick.d \
./Sources/mcl/CrystalClock.d \
./Sources/mcl/IO_PinCfg.d \
./Sources/mcl/interrupts.d \
./Sources/mcl/sysinit.d \
./Sources/mcl/uart.d \

OBJS_QUOTED += \
"./Sources/mcl/ARM_SysTick.o" \
"./Sources/mcl/CrystalClock.o" \
"./Sources/mcl/IO_PinCfg.o" \
"./Sources/mcl/interrupts.o" \
"./Sources/mcl/sysinit.o" \
"./Sources/mcl/uart.o" \

C_DEPS_QUOTED += \
"./Sources/mcl/ARM_SysTick.d" \
"./Sources/mcl/CrystalClock.d" \
"./Sources/mcl/IO_PinCfg.d" \
"./Sources/mcl/interrupts.d" \
"./Sources/mcl/sysinit.d" \
"./Sources/mcl/uart.d" \

OBJS_OS_FORMAT += \
./Sources/mcl/ARM_SysTick.o \
./Sources/mcl/CrystalClock.o \
./Sources/mcl/IO_PinCfg.o \
./Sources/mcl/interrupts.o \
./Sources/mcl/sysinit.o \
./Sources/mcl/uart.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/mcl/ARM_SysTick.o: ../Sources/mcl/ARM_SysTick.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/ARM_SysTick.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/ARM_SysTick.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcl/CrystalClock.o: ../Sources/mcl/CrystalClock.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/CrystalClock.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/CrystalClock.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcl/IO_PinCfg.o: ../Sources/mcl/IO_PinCfg.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/IO_PinCfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/IO_PinCfg.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcl/interrupts.o: ../Sources/mcl/interrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/interrupts.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/interrupts.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcl/sysinit.o: ../Sources/mcl/sysinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/sysinit.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/sysinit.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcl/uart.o: ../Sources/mcl/uart.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/uart.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/uart.o"
	@echo 'Finished building: $<'
	@echo ' '


