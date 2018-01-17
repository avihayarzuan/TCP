################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TCP/ClientHandler.cpp \
../TCP/CloseCommand.cpp \
../TCP/CommandManager.cpp \
../TCP/GetListCommand.cpp \
../TCP/JoinCommand.cpp \
../TCP/PlayCommand.cpp \
../TCP/ReadPort.cpp \
../TCP/Server.cpp \
../TCP/StartCommand.cpp \
../TCP/ThreadPool.cpp \
../TCP/main.cpp 

OBJS += \
./TCP/ClientHandler.o \
./TCP/CloseCommand.o \
./TCP/CommandManager.o \
./TCP/GetListCommand.o \
./TCP/JoinCommand.o \
./TCP/PlayCommand.o \
./TCP/ReadPort.o \
./TCP/Server.o \
./TCP/StartCommand.o \
./TCP/ThreadPool.o \
./TCP/main.o 

CPP_DEPS += \
./TCP/ClientHandler.d \
./TCP/CloseCommand.d \
./TCP/CommandManager.d \
./TCP/GetListCommand.d \
./TCP/JoinCommand.d \
./TCP/PlayCommand.d \
./TCP/ReadPort.d \
./TCP/Server.d \
./TCP/StartCommand.d \
./TCP/ThreadPool.d \
./TCP/main.d 


# Each subdirectory must supply rules for building sources it contributes
TCP/%.o: ../TCP/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


