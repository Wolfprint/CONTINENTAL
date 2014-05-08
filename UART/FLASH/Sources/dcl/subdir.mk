################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/dcl/charCtrlFnc.c" \
"../Sources/dcl/io_char.c" \
"../Sources/dcl/ledDrivers.c" \

C_SRCS += \
../Sources/dcl/charCtrlFnc.c \
../Sources/dcl/io_char.c \
../Sources/dcl/ledDrivers.c \

OBJS += \
./Sources/dcl/charCtrlFnc.o \
./Sources/dcl/io_char.o \
./Sources/dcl/ledDrivers.o \

C_DEPS += \
./Sources/dcl/charCtrlFnc.d \
./Sources/dcl/io_char.d \
./Sources/dcl/ledDrivers.d \

OBJS_QUOTED += \
"./Sources/dcl/charCtrlFnc.o" \
"./Sources/dcl/io_char.o" \
"./Sources/dcl/ledDrivers.o" \

C_DEPS_QUOTED += \
"./Sources/dcl/charCtrlFnc.d" \
"./Sources/dcl/io_char.d" \
"./Sources/dcl/ledDrivers.d" \

OBJS_OS_FORMAT += \
./Sources/dcl/charCtrlFnc.o \
./Sources/dcl/io_char.o \
./Sources/dcl/ledDrivers.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/dcl/charCtrlFnc.o: ../Sources/dcl/charCtrlFnc.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/dcl/charCtrlFnc.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/dcl/charCtrlFnc.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/dcl/io_char.o: ../Sources/dcl/io_char.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/dcl/io_char.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/dcl/io_char.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/dcl/ledDrivers.o: ../Sources/dcl/ledDrivers.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/dcl/ledDrivers.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/dcl/ledDrivers.o"
	@echo 'Finished building: $<'
	@echo ' '


