################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/dcl/charCtrlFnc.c" \
"../Sources/dcl/io.c" \
"../Sources/dcl/ledDrivers.c" \
"../Sources/dcl/libs.c" \

C_SRCS += \
../Sources/dcl/charCtrlFnc.c \
../Sources/dcl/io.c \
../Sources/dcl/ledDrivers.c \
../Sources/dcl/libs.c \

OBJS += \
./Sources/dcl/charCtrlFnc.o \
./Sources/dcl/io.o \
./Sources/dcl/ledDrivers.o \
./Sources/dcl/libs.o \

C_DEPS += \
./Sources/dcl/charCtrlFnc.d \
./Sources/dcl/io.d \
./Sources/dcl/ledDrivers.d \
./Sources/dcl/libs.d \

OBJS_QUOTED += \
"./Sources/dcl/charCtrlFnc.o" \
"./Sources/dcl/io.o" \
"./Sources/dcl/ledDrivers.o" \
"./Sources/dcl/libs.o" \

C_DEPS_QUOTED += \
"./Sources/dcl/charCtrlFnc.d" \
"./Sources/dcl/io.d" \
"./Sources/dcl/ledDrivers.d" \
"./Sources/dcl/libs.d" \

OBJS_OS_FORMAT += \
./Sources/dcl/charCtrlFnc.o \
./Sources/dcl/io.o \
./Sources/dcl/ledDrivers.o \
./Sources/dcl/libs.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/dcl/charCtrlFnc.o: ../Sources/dcl/charCtrlFnc.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/dcl/charCtrlFnc.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/dcl/charCtrlFnc.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/dcl/io.o: ../Sources/dcl/io.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/dcl/io.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/dcl/io.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/dcl/ledDrivers.o: ../Sources/dcl/ledDrivers.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/dcl/ledDrivers.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/dcl/ledDrivers.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/dcl/libs.o: ../Sources/dcl/libs.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/dcl/libs.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/dcl/libs.o"
	@echo 'Finished building: $<'
	@echo ' '


