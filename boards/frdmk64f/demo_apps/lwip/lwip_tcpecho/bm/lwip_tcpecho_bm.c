/*
* Copyright (c) 2016, Freescale Semiconductor, Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* o Redistributions of source code must retain the above copyright notice, this list
*   of conditions and the following disclaimer.
*
* o Redistributions in binary form must reproduce the above copyright notice, this
*   list of conditions and the following disclaimer in the documentation and/or
*   other materials provided with the distribution.
*
* o Neither the name of Freescale Semiconductor, Inc. nor the names of its
*   contributors may be used to endorse or promote products derived from this
*   software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "lwip/opt.h"

#if LWIP_TCP

#include "tcpecho_raw/tcpecho_raw.h"
#include "lwip/timeouts.h"
#include "lwip/init.h"
#include "netif/ethernet.h"
#include "ethernetif.h"

#include "board.h"

#include "fsl_device_registers.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define EXAMPLE_ENET ENET

/* IP address configuration. */
#define configIP_ADDR0 192
#define configIP_ADDR1 168
#define configIP_ADDR2 10
#define configIP_ADDR3 102

/* Netmask configuration. */
#define configNET_MASK0 255
#define configNET_MASK1 255
#define configNET_MASK2 255
#define configNET_MASK3 0

/* Gateway address configuration. */
#define configGW_ADDR0 192
#define configGW_ADDR1 168
#define configGW_ADDR2 10
#define configGW_ADDR3 100

#define configPHY_ADDRESS 1

/* Pit IRQ configuration. */
#define BOARD_PIT_IRQ_HANDLER PIT0_IRQHandler
#define BOARD_PIT_IRQ_ID PIT0_IRQn
#define BOARD_PIT_CHANNEL kPIT_Chnl_0


/*******************************************************************************
* Prototypes
******************************************************************************/

/*******************************************************************************
* Variables
******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Interrupt service for PIT timer.
 *
 */
void BOARD_PIT_IRQ_HANDLER(void)
{
    /* Clear interrupt flag.*/
    PIT_ClearStatusFlags(PIT, BOARD_PIT_CHANNEL, PIT_TFLG_TIF_MASK);
    time_isr();
}

/*!
 * @brief function to return timer parameters.
 *
 */
lwip_pit_init_param_t get_timer_init_param(void)
{
    lwip_pit_init_param_t param;
    param.irqn = BOARD_PIT_IRQ_ID;
    param.channel = BOARD_PIT_CHANNEL;
    return param;
}


void WriteGPIOByName(IOs  ios, uint8_t onoff)
{
	switch (ios)
	{
		case LED: // LED
			GPIO_WritePinOutput(GPIOB, 22, (uint32_t)onoff);         /* LED  */
		break;
		case PTB18:
			GPIO_WritePinOutput(GPIOB, 18, onoff);
		break;
		case PTB19:
			GPIO_WritePinOutput(GPIOB, 19, onoff);
		break;
		case PTC1:
			GPIO_WritePinOutput(GPIOC, 1, onoff);
		break;
		case PTC8:
			GPIO_WritePinOutput(GPIOC, 8, onoff);
		break;
		case PTC9:
			GPIO_WritePinOutput(GPIOC, 9, onoff);
		break;
		case PTC0:
			GPIO_WritePinOutput(GPIOC, 0, onoff);
		break;
		case PTC7:
			GPIO_WritePinOutput(GPIOC, 7, onoff);
		break;
		case PTC5:
			GPIO_WritePinOutput(GPIOC, 5, onoff);
		break;
		case PTC16:
			GPIO_WritePinOutput(GPIOC, 16, onoff);
		break;
		case PTC17:
			GPIO_WritePinOutput(GPIOC, 17, onoff);
		break;
		case PTB9:
			GPIO_WritePinOutput(GPIOB, 9, onoff);
		break;
		case PTA1:
			GPIO_WritePinOutput(GPIOA, 1, onoff);
		break;
		case PTB23:
			GPIO_WritePinOutput(GPIOB, 23, onoff);
		break;
		case PTA2:
			GPIO_WritePinOutput(GPIOA, 2, onoff);
		break;
		case PTC2:
			GPIO_WritePinOutput(GPIOC, 2, onoff);
		break;
		case PTC3:
			GPIO_WritePinOutput(GPIOC, 3, onoff);
		break;
	}
}

/*!
 * @brief Main function.
 */
int main(void)
{
    struct netif fsl_netif0;
    ip4_addr_t fsl_netif0_ipaddr, fsl_netif0_netmask, fsl_netif0_gw;

    MPU_Type *base = MPU;
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    /* Disable MPU. */
    base->CESR &= ~MPU_CESR_VLD_MASK;

    time_init();

    IP4_ADDR(&fsl_netif0_ipaddr, configIP_ADDR0, configIP_ADDR1, configIP_ADDR2, configIP_ADDR3);
    IP4_ADDR(&fsl_netif0_netmask, configNET_MASK0, configNET_MASK1, configNET_MASK2, configNET_MASK3);
    IP4_ADDR(&fsl_netif0_gw, configGW_ADDR0, configGW_ADDR1, configGW_ADDR2, configGW_ADDR3);

    lwip_init();

    netif_add(&fsl_netif0, &fsl_netif0_ipaddr, &fsl_netif0_netmask, &fsl_netif0_gw, NULL, ethernetif_init,
              ethernet_input);
    netif_set_default(&fsl_netif0);
    netif_set_up(&fsl_netif0);

    tcpecho_raw_init();

    PRINTF("\r\n************************************************\r\n");
    PRINTF(" TCP Echo example\r\n");
    PRINTF("************************************************\r\n");
    PRINTF(" IPv4 Address     : %u.%u.%u.%u\r\n", ((u8_t *)&fsl_netif0_ipaddr)[0], ((u8_t *)&fsl_netif0_ipaddr)[1],
           ((u8_t *)&fsl_netif0_ipaddr)[2], ((u8_t *)&fsl_netif0_ipaddr)[3]);
    PRINTF(" IPv4 Subnet mask : %u.%u.%u.%u\r\n", ((u8_t *)&fsl_netif0_netmask)[0], ((u8_t *)&fsl_netif0_netmask)[1],
           ((u8_t *)&fsl_netif0_netmask)[2], ((u8_t *)&fsl_netif0_netmask)[3]);
    PRINTF(" IPv4 Gateway     : %u.%u.%u.%u\r\n", ((u8_t *)&fsl_netif0_gw)[0], ((u8_t *)&fsl_netif0_gw)[1],
           ((u8_t *)&fsl_netif0_gw)[2], ((u8_t *)&fsl_netif0_gw)[3]);
    PRINTF("************************************************\r\n");



    gpio_pin_config_t led_config = {
 	   kGPIO_DigitalOutput, 0,
    };

    PORT_SetPinMux(PORTB, 22, kPORT_MuxAsGpio);         /* LED  */
	PORT_SetPinMux(PORTB, 18, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, 19, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 1, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 8, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 9, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 0, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 7, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 5, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 16, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 17, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, 9, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 1, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, 23, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 2, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 2, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 3, kPORT_MuxAsGpio);

	/* Init output LED GPIO. */
	GPIO_PinInit(GPIOB, 22, &led_config);
	GPIO_PinInit(GPIOB, 18, &led_config);
	GPIO_PinInit(GPIOB, 19, &led_config);
	GPIO_PinInit(GPIOC, 1, &led_config);
	GPIO_PinInit(GPIOC, 8, &led_config);
	GPIO_PinInit(GPIOC, 9, &led_config);
	GPIO_PinInit(GPIOC, 0, &led_config);
	GPIO_PinInit(GPIOC, 7, &led_config);
	GPIO_PinInit(GPIOC, 5, &led_config);
	GPIO_PinInit(GPIOC, 16, &led_config);
	GPIO_PinInit(GPIOC, 17, &led_config);
	GPIO_PinInit(GPIOB, 9, &led_config);
	GPIO_PinInit(GPIOA, 1, &led_config);
	GPIO_PinInit(GPIOB, 23, &led_config);
	GPIO_PinInit(GPIOA, 2, &led_config);
	GPIO_PinInit(GPIOC, 2, &led_config);
	GPIO_PinInit(GPIOC, 3, &led_config);

	GPIO_WritePinOutput(GPIOB,22, 1);

    while (1)
    {
        /* Poll the driver, get any outstanding frames */
        ethernetif_input(&fsl_netif0);

        sys_check_timeouts(); /* Handle all system timeouts for all core protocols */
    }
}
#endif
