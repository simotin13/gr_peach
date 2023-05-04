################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LINKER_SCRIPT += \
../generate/linker_script.ld 

S_UPPER_SRCS += \
../generate/start.S \
../generate/vect_table.S 

LST += \
start.lst \
vect_table.lst 

OBJS += \
./generate/start.o \
./generate/vect_table.o 

S_UPPER_DEPS += \
./generate/start.d \
./generate/vect_table.d 

MAP += \
gr_peach.map 


# Each subdirectory must supply rules for building sources it contributes
generate/%.o: ../generate/%.S
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-a9 -marm -mlittle-endian -mfloat-abi=soft -fdiagnostics-parseable-fixits -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wnull-dereference -Wstack-usage=100 -g -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@echo $< && arm-none-eabi-gcc @"$@.in"

