################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/mcl/IO_PinCfg.c" \
"../Sources/mcl/mcg_init.c" \
"../Sources/mcl/uart0_init.c" \

C_SRCS += \
../Sources/mcl/IO_PinCfg.c \
../Sources/mcl/mcg_init.c \
../Sources/mcl/uart0_init.c \

OBJS += \
./Sources/mcl/IO_PinCfg.o \
./Sources/mcl/mcg_init.o \
./Sources/mcl/uart0_init.o \

C_DEPS += \
./Sources/mcl/IO_PinCfg.d \
./Sources/mcl/mcg_init.d \
./Sources/mcl/uart0_init.d \

OBJS_QUOTED += \
"./Sources/mcl/IO_PinCfg.o" \
"./Sources/mcl/mcg_init.o" \
"./Sources/mcl/uart0_init.o" \

C_DEPS_QUOTED += \
"./Sources/mcl/IO_PinCfg.d" \
"./Sources/mcl/mcg_init.d" \
"./Sources/mcl/uart0_init.d" \

OBJS_OS_FORMAT += \
./Sources/mcl/IO_PinCfg.o \
./Sources/mcl/mcg_init.o \
./Sources/mcl/uart0_init.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/mcl/IO_PinCfg.o: ../Sources/mcl/IO_PinCfg.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/IO_PinCfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/IO_PinCfg.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcl/mcg_init.o: ../Sources/mcl/mcg_init.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/mcg_init.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/mcg_init.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcl/uart0_init.o: ../Sources/mcl/uart0_init.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/uart0_init.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/uart0_init.o"
	@echo 'Finished building: $<'
	@echo ' '


