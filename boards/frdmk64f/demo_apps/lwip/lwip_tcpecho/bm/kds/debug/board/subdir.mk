################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/LanToIo/LanTCPToIo/boards/frdmk64f/demo_apps/lwip/lwip_tcpecho/bm/board.c \
C:/LanToIo/LanTCPToIo/boards/frdmk64f/demo_apps/lwip/lwip_tcpecho/bm/clock_config.c \
C:/LanToIo/LanTCPToIo/boards/frdmk64f/demo_apps/lwip/lwip_tcpecho/bm/fsl_phy.c \
C:/LanToIo/LanTCPToIo/boards/frdmk64f/demo_apps/lwip/lwip_tcpecho/bm/pin_mux.c 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/fsl_phy.o \
./board/pin_mux.o 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/fsl_phy.d \
./board/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
board/board.o: C:/LanToIo/LanTCPToIo/boards/frdmk64f/demo_apps/lwip/lwip_tcpecho/bm/board.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -DDEBUG -DCPU_MK64FN1M0VMD12 -DFRDM_K64F -DFREEDOM -I../ -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../devices/MK64F12/drivers -I../.. -I../../../../../../../../devices/MK64F12/utilities -I../../../../../../../../middleware/lwip_2.0.0 -I../../../../../../../../middleware/lwip_2.0.0/port -I../../../../../../../../middleware/lwip_2.0.0/port/arch -I../../../../../../../../middleware/lwip_2.0.0/src -I../../../../../../../../middleware/lwip_2.0.0/src/include -I../../../../../../../../middleware/lwip_2.0.0/src/include/lwip -I../../../../../../../../middleware/lwip_2.0.0/src/include/lwip/priv -I../../../../../../../../middleware/lwip_2.0.0/src/include/netif -I../../../../../../../../middleware/lwip_2.0.0/src/include/posix -I../../../../../../../../middleware/lwip_2.0.0/src/include -I../../../../../../../../middleware/lwip_2.0.0/contrib/apps -I../../../../../.. -I../../../../../../../../devices/MK64F12 -std=gnu99 -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

board/clock_config.o: C:/LanToIo/LanTCPToIo/boards/frdmk64f/demo_apps/lwip/lwip_tcpecho/bm/clock_config.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -DDEBUG -DCPU_MK64FN1M0VMD12 -DFRDM_K64F -DFREEDOM -I../ -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../devices/MK64F12/drivers -I../.. -I../../../../../../../../devices/MK64F12/utilities -I../../../../../../../../middleware/lwip_2.0.0 -I../../../../../../../../middleware/lwip_2.0.0/port -I../../../../../../../../middleware/lwip_2.0.0/port/arch -I../../../../../../../../middleware/lwip_2.0.0/src -I../../../../../../../../middleware/lwip_2.0.0/src/include -I../../../../../../../../middleware/lwip_2.0.0/src/include/lwip -I../../../../../../../../middleware/lwip_2.0.0/src/include/lwip/priv -I../../../../../../../../middleware/lwip_2.0.0/src/include/netif -I../../../../../../../../middleware/lwip_2.0.0/src/include/posix -I../../../../../../../../middleware/lwip_2.0.0/src/include -I../../../../../../../../middleware/lwip_2.0.0/contrib/apps -I../../../../../.. -I../../../../../../../../devices/MK64F12 -std=gnu99 -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

board/fsl_phy.o: C:/LanToIo/LanTCPToIo/boards/frdmk64f/demo_apps/lwip/lwip_tcpecho/bm/fsl_phy.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -DDEBUG -DCPU_MK64FN1M0VMD12 -DFRDM_K64F -DFREEDOM -I../ -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../devices/MK64F12/drivers -I../.. -I../../../../../../../../devices/MK64F12/utilities -I../../../../../../../../middleware/lwip_2.0.0 -I../../../../../../../../middleware/lwip_2.0.0/port -I../../../../../../../../middleware/lwip_2.0.0/port/arch -I../../../../../../../../middleware/lwip_2.0.0/src -I../../../../../../../../middleware/lwip_2.0.0/src/include -I../../../../../../../../middleware/lwip_2.0.0/src/include/lwip -I../../../../../../../../middleware/lwip_2.0.0/src/include/lwip/priv -I../../../../../../../../middleware/lwip_2.0.0/src/include/netif -I../../../../../../../../middleware/lwip_2.0.0/src/include/posix -I../../../../../../../../middleware/lwip_2.0.0/src/include -I../../../../../../../../middleware/lwip_2.0.0/contrib/apps -I../../../../../.. -I../../../../../../../../devices/MK64F12 -std=gnu99 -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

board/pin_mux.o: C:/LanToIo/LanTCPToIo/boards/frdmk64f/demo_apps/lwip/lwip_tcpecho/bm/pin_mux.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -DDEBUG -DCPU_MK64FN1M0VMD12 -DFRDM_K64F -DFREEDOM -I../ -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../devices/MK64F12/drivers -I../.. -I../../../../../../../../devices/MK64F12/utilities -I../../../../../../../../middleware/lwip_2.0.0 -I../../../../../../../../middleware/lwip_2.0.0/port -I../../../../../../../../middleware/lwip_2.0.0/port/arch -I../../../../../../../../middleware/lwip_2.0.0/src -I../../../../../../../../middleware/lwip_2.0.0/src/include -I../../../../../../../../middleware/lwip_2.0.0/src/include/lwip -I../../../../../../../../middleware/lwip_2.0.0/src/include/lwip/priv -I../../../../../../../../middleware/lwip_2.0.0/src/include/netif -I../../../../../../../../middleware/lwip_2.0.0/src/include/posix -I../../../../../../../../middleware/lwip_2.0.0/src/include -I../../../../../../../../middleware/lwip_2.0.0/contrib/apps -I../../../../../.. -I../../../../../../../../devices/MK64F12 -std=gnu99 -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


