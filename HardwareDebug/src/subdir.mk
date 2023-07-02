################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gr_peach.c \
../src/rspi2.c \
../src/sci0.c 

LST += \
gr_peach.lst \
rspi2.lst \
sci0.lst 

C_DEPS += \
./src/gr_peach.d \
./src/rspi2.d \
./src/sci0.d 

OBJS += \
./src/gr_peach.o \
./src/rspi2.o \
./src/sci0.o 

MAP += \
gr_peach.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a9 -marm -mlittle-endian -mfloat-abi=soft -fdiagnostics-parseable-fixits -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wnull-dereference -Wstack-usage=100 -g -I"C:/Users/miyazaki/e2_studio/workspace/gr_peach/generate" -I"C:/Users/miyazaki/e2_studio/workspace/gr_peach/src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@echo $< && arm-none-eabi-gcc @"$@.in"

