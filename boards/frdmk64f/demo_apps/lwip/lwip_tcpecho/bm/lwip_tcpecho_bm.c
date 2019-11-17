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
		// J2
		case PTA4:
			GPIO_WritePinOutput(GPIOA, 4, onoff);
		break;
		case PTC4:
			GPIO_WritePinOutput(GPIOC, 4, onoff);
		break;
		case PTD0:
			GPIO_WritePinOutput(GPIOD, 0, onoff);
		break;
		case PTD2:
			GPIO_WritePinOutput(GPIOD, 2, onoff);
		break;
		case PTD3:
			GPIO_WritePinOutput(GPIOD, 3, onoff);
		break;
		case PTD1:
			GPIO_WritePinOutput(GPIOD, 1, onoff);
		break;
		case PTE25:
			GPIO_WritePinOutput(GPIOE, 25, onoff);
		break;
		case PTE24:
			GPIO_WritePinOutput(GPIOE, 24, onoff);
		break;
		case PTC6:
			GPIO_WritePinOutput(GPIOC, 6, onoff);
			break;
		case PTC13:
			GPIO_WritePinOutput(GPIOC, 13, onoff);
			break;
		case PTE5:
			GPIO_WritePinOutput(GPIOE, 5, onoff);
			break;
		case PTE4:
			GPIO_WritePinOutput(GPIOE, 4, onoff);
			break;
		case PTE3:
			GPIO_WritePinOutput(GPIOE, 3, onoff);
			break;
		case PTE2:
			GPIO_WritePinOutput(GPIOE, 2, onoff);
			break;
		case PTE1:
			GPIO_WritePinOutput(GPIOE, 1, onoff);
			break;
		case PTE0:
			GPIO_WritePinOutput(GPIOE, 0, onoff);
			break;
		case PTE6:
			GPIO_WritePinOutput(GPIOE, 6, onoff);
	    break;
	    //
		case PTA0:
			GPIO_WritePinOutput(GPIOA, 0, onoff);
			break;
		case PTA3:
			GPIO_WritePinOutput(GPIOA, 3, onoff);
			break;
		case PTA5:
			GPIO_WritePinOutput(GPIOA, 5, onoff);
			break;
		case PTA12:
			GPIO_WritePinOutput(GPIOA, 12, onoff);
			break;
		case PTA13:
			GPIO_WritePinOutput(GPIOA, 13, onoff);
			break;
		case PTA14:
			GPIO_WritePinOutput(GPIOA, 14, onoff);
			break;
		case PTA15:
			GPIO_WritePinOutput(GPIOA, 15, onoff);
			break;
		case PTA16:
			GPIO_WritePinOutput(GPIOA, 16, onoff);
			break;
		case PTA17:
			GPIO_WritePinOutput(GPIOA, 17, onoff);
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
	// J2
	PORT_SetPinMux(PORTA, 4, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 4, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 0, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 2, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 3, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 1, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 25, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 24, kPORT_MuxAsGpio);
    // J4
	PORT_SetPinMux(PORTB, 2, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, 3, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, 10, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, 11, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 11, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 10, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, 20, kPORT_MuxAsGpio);
	//J6
	PORT_SetPinMux(PORTC, 12, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 5, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 7, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 4, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 6, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 18, kPORT_MuxAsGpio);

	//
	PORT_SetPinMux(PORTC, 6, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 13, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 5, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 4, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 3, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 1, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 1, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 0, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 6, kPORT_MuxAsGpio);
	//
	PORT_SetPinMux(PORTC, 14, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTC, 15, kPORT_MuxAsGpio);
	//

	PORT_SetPinMux(PORTA, 0, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 1, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 2, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 3, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 4, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 5, kPORT_MuxAsGpio);

	PORT_SetPinMux(PORTA, 12, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 13, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 14, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 15, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 16, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 17, kPORT_MuxAsGpio);



	/* Init output LED GPIO. */
	GPIO_PinInit(GPIOB, 22, &led_config);
	// J1
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
	// J2
	GPIO_PinInit(GPIOA, 4, &led_config);
	GPIO_PinInit(GPIOC, 4, &led_config);
	GPIO_PinInit(GPIOD, 0, &led_config);
	GPIO_PinInit(GPIOD, 2, &led_config);
	GPIO_PinInit(GPIOD, 3, &led_config);
	GPIO_PinInit(GPIOD, 1, &led_config);
	GPIO_PinInit(GPIOE, 25, &led_config);
	GPIO_PinInit(GPIOE, 24, &led_config);
    // J4
	GPIO_PinInit(GPIOB, 2, &led_config);
	GPIO_PinInit(GPIOB, 3, &led_config);
	GPIO_PinInit(GPIOB, 10, &led_config);
	GPIO_PinInit(GPIOB, 11, &led_config);
	GPIO_PinInit(GPIOC, 11, &led_config);
	GPIO_PinInit(GPIOC, 10, &led_config);
	GPIO_PinInit(GPIOB, 20, &led_config);
	//J6
	GPIO_PinInit(GPIOC, 12, &led_config);
	GPIO_PinInit(GPIOD, 5, &led_config);
	GPIO_PinInit(GPIOD, 7, &led_config);
	GPIO_PinInit(GPIOD, 4, &led_config);
	GPIO_PinInit(GPIOD, 6, &led_config);
	GPIO_PinInit(GPIOC, 18, &led_config);
	//

	GPIO_PinInit(GPIOC, 6, &led_config);
	GPIO_PinInit(GPIOC, 13, &led_config);

	GPIO_PinInit(GPIOE, 5, &led_config);
	GPIO_PinInit(GPIOE, 4, &led_config);
	GPIO_PinInit(GPIOE, 3, &led_config);

	GPIO_PinInit(GPIOE, 1, &led_config);
	GPIO_PinInit(GPIOE, 1, &led_config);
	GPIO_PinInit(GPIOE, 0, &led_config);
	GPIO_PinInit(GPIOE, 6, &led_config);
	//

	GPIO_PinInit(GPIOC, 14, &led_config);
	GPIO_PinInit(GPIOC, 15, &led_config);
	//
	GPIO_PinInit(GPIOA, 0, GPIO_PinInit);
	GPIO_PinInit(GPIOC, 1, GPIO_PinInit);
	GPIO_PinInit(GPIOC, 2, GPIO_PinInit);
	GPIO_PinInit(GPIOC, 3, GPIO_PinInit);
	GPIO_PinInit(GPIOC, 4, GPIO_PinInit);
	GPIO_PinInit(GPIOC, 5, GPIO_PinInit);

	GPIO_PinInit(GPIOC, 12, GPIO_PinInit);
	GPIO_PinInit(GPIOC, 13, GPIO_PinInit);
	GPIO_PinInit(GPIOC, 14, GPIO_PinInit);
	GPIO_PinInit(GPIOC, 15, GPIO_PinInit);
	GPIO_PinInit(GPIOC, 16, GPIO_PinInit);
	GPIO_PinInit(GPIOC, 17, GPIO_PinInit);






	GPIO_WritePinOutput(GPIOB,22, 1);

    while (1)
    {
        /* Poll the driver, get any outstanding frames */
        ethernetif_input(&fsl_netif0);

        sys_check_timeouts(); /* Handle all system timeouts for all core protocols */
    }
}
#endif
