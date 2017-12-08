################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TCP/Server.cpp \
../TCP/main.cpp 

OBJS += \
./TCP/Server.o \
./TCP/main.o 

CPP_DEPS += \
./TCP/Server.d \
./TCP/main.d 


# Each subdirectory must supply rules for building sources it contributes
TCP/%.o: ../TCP/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


