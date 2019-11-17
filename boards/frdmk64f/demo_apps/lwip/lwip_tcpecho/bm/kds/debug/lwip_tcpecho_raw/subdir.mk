################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/LanToIo/LanTCPToIo/middleware/lwip_2.0.0/contrib/apps/tcpecho_raw/tcpecho_raw.c 

OBJS += \
./lwip_tcpecho_raw/tcpecho_raw.o 

C_DEPS += \
./lwip_tcpecho_raw/tcpecho_raw.d 


# Each subdirectory must supply rules for building sources it contributes
lwip_tcpecho_raw/tcpecho_raw.o: C:/LanToIo/LanTCPToIo/middleware/lwip_2.0.0/contrib/apps/tcpecho_raw/tcpecho_raw.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -DDEBUG -DCPU_MK64FN1M0VMD12 -DFRDM_K64F -DFREEDOM -I../ -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../devices/MK64F12/drivers -I../.. -I../../../../../../../../devices/MK64F12/utilities -I../../../../../../../../middleware/lwip_2.0.0 -I../../../../../../../../middleware/lwip_2.0.0/port -I../../../../../../../../middleware/lwip_2.0.0/port/arch -I../../../../../../../../middleware/lwip_2.0.0/src -I../../../../../../../../middleware/lwip_2.0.0/src/include -I../../../../../../../../middleware/lwip_2.0.0/src/include/lwip -I../../../../../../../../middleware/lwip_2.0.0/src/include/lwip/priv -I../../../../../../../../middleware/lwip_2.0.0/src/include/netif -I../../../../../../../../middleware/lwip_2.0.0/src/include/posix -I../../../../../../../../middleware/lwip_2.0.0/src/include -I../../../../../../../../middleware/lwip_2.0.0/contrib/apps -I../../../../../.. -I../../../../../../../../devices/MK64F12 -std=gnu99 -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


