################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/app/StopBitApp.c" \
"../Sources/app/actuatorApp.c" \
"../Sources/app/appChar.c" \

C_SRCS += \
../Sources/app/StopBitApp.c \
../Sources/app/actuatorApp.c \
../Sources/app/appChar.c \

OBJS += \
./Sources/app/StopBitApp.o \
./Sources/app/actuatorApp.o \
./Sources/app/appChar.o \

C_DEPS += \
./Sources/app/StopBitApp.d \
./Sources/app/actuatorApp.d \
./Sources/app/appChar.d \

OBJS_QUOTED += \
"./Sources/app/StopBitApp.o" \
"./Sources/app/actuatorApp.o" \
"./Sources/app/appChar.o" \

C_DEPS_QUOTED += \
"./Sources/app/StopBitApp.d" \
"./Sources/app/actuatorApp.d" \
"./Sources/app/appChar.d" \

OBJS_OS_FORMAT += \
./Sources/app/StopBitApp.o \
./Sources/app/actuatorApp.o \
./Sources/app/appChar.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/app/StopBitApp.o: ../Sources/app/StopBitApp.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/StopBitApp.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/StopBitApp.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/actuatorApp.o: ../Sources/app/actuatorApp.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/actuatorApp.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/actuatorApp.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/appChar.o: ../Sources/app/appChar.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/appChar.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/appChar.o"
	@echo 'Finished building: $<'
	@echo ' '


