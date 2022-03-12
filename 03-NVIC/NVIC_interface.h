
/**************************************************************************/
/*	File 	: NVIC_interface.h						 	 				  */
/*	Author	: Zaki Ahmed Hamed					     					  */
/*  Date 	: 27 March 2021						 						  */
/*  Version : V01									 					  */
/*  @brief  : This file contains all the functions prototypes for the NVIC*/ 
/*				firmware .		    									  */
/**************************************************************************/


/*******************************************************
*     @brief: Define to prevent recursive inclusion    *
*******************************************************/	
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H




/* enum for all external interrupt  */

typedef enum
{
	WWDG_IRQ    = 0       ,
	PVD_IRQ               ,
	TAMP_STAMP_IRQ        ,
	RTC_IRQ               ,
	FLASH_IRQ             ,
	RCC_IRQ               ,
	EXTI0_IRQ             ,
	EXTI1_IRQ             ,
	EXTI2_IRQ             ,
	EXTI3_IRQ             ,
	EXTI4_IRQ             ,
	DMA1_Channel0_IRQ     ,
	DMA1_Channel1_IRQ     ,
	DMA1_Channel2_IRQ     ,
	DMA1_Channel3_IRQ     ,
	DMA1_Channel4_IRQ     ,
	DMA1_Channel5_IRQ     ,
	DMA1_Channel6_IRQ     ,
	ADC1_2_3_IRQ          ,
	CAN1_TX_IRQ		      ,
	CAN1_RX0_IRQ		  ,
	CAN1_RX1_IRQ          ,
	CAN1_SCE_IRQ		  ,
	EXTI9_5_IRQ           ,
	TIM1_BRK_TIM9_IRQ     ,
	TIM1_UP_TIM10_IRQ     ,
	TIM1_TRG_COM_TIM11_IRQ,
	TIM1_CC_IRQ           ,
	TIM2_IRQ              ,
	TIM3_IRQ              ,
	TIM4_IRQ              ,
	I2C1_EV_IRQ           ,
	I2C1_ER_IRQ           ,
	I222_EV_IRQ           ,
	I2C2_ER_IRQ           ,
	SPI1_IRQ              ,
	SPI2_IRQ              ,
	USART1_IRQ            ,
	USART2_IRQ            ,
	USART3_IRQ            ,
	EXTI15_10_IRQ         ,
	RTCAlarm_IRQ          ,
	OTG_FS_WKUP_IRQ       ,
	TIM8_BRK_TIM12_IRQ    ,
	TIM8_UP_TIM13_IRQ     ,
	TIM8_TRG_COM_TIM14_IRQ,
	TIM8_CC_IRQ           ,
	DMA1_Stream7_IRQ      ,
	FSMC_IRQ              ,
	SDIO_IRQ              ,
	TIM5_IRQ              ,
	SPI13_IRQ             ,
	UART4_IRQ             ,
	UART5_IRQ             ,
	TIM6_DAC_IRQ          ,
	TIM7_IRQ     	      ,
	DMA2_Stream0_IRQ      ,
	DMA2_Stream1_IRQ      ,
	DMA2_Stream2_IRQ      ,
	DMA2_Stream3_IRQ      ,
	DMA2_Stream4_IRQ      ,
	ETH_IRQ               ,
	ETH_WKUP_IRQ          ,
	CAN2_TX_IRQ           ,
	CAN2_RX0_IRQ          ,
	CAN2_RX1_IRQ          ,
	CAN2_SCE_IRQ          ,
	OTG_FS_IRQ            ,
	DMA2_Stream5_IRQ      ,
	DMA2_Stream6_IRQ      ,
	DMA2_Stream7_IRQ      ,
	USART6_IRQ            ,
	I2C3_EV_IRQ           ,
	I2C3_ER_IRQ           ,
	OTG_HS_EP1_OUT_IRQ    ,
	OTG_HS_EP1_IN_IRQ     ,
	OTG_HS_WKUP_IRQ       ,
	OTG_HS_IRQ            ,
	DCMI_IRQ              ,
	CRYP_IRQ              ,
	HASH_RNG_IRQ          ,
	FPU_IRQ               
		
}NVIC_IRQn_t;

#define GROUP3     0x05FA0300	//0 bit for sub & 4 bit For group   << 0
#define GROUP4     0x05FA0400	//1 bit for sub & 3 bit For group   << 1
#define GROUP5     0x05FA0500	//2 bit for sub & 2 bit For group   << 2
#define GROUP6     0x05FA0600	//3 bit for sub & 1 bit For group   << 3
#define GROUP7     0x05FA0700	//4 bit for sub & 0 bit For group   << 4

#define NO_SUB_PRIORITY 0

/*-----------------Functions Prototypes -------------------------*/
void MNVIC_VoidPriorityInit(NVIC_IRQn_t Copy_IRQn ,u8 Copy_U8GroupPrio ,u8 Copy_U8SubPrio ,u32 Copy_U32Grouping);
/**************************************************************************/
/*  Function_Name: MNVIC_voidEnableIRQ()								  */
/*	Description  : function used to enable interrupt					  */
/*	Input 	     : NVIC_IRQn_t copy_IRQn->interrupt number in vector table*/
/*	return 	     : void													  */
/**************************************************************************/
void MNVIC_voidEnableIRQ(NVIC_IRQn_t Copy_IRQn);

/**************************************************************************/
/*  Function_Name: MNVIC_voidSetPendingIRQ()							  */
/*	Description  : function used to disable interrupt					  */
/*	Input 	     : NVIC_IRQn_t copy_IRQn->interrupt number in vector table*/
/*	return 	     : void													  */
/**************************************************************************/
void MNVIC_voidDisableIRQ(NVIC_IRQn_t Copy_IRQn);

/**************************************************************************/
/*  Function_Name: MNVIC_voidSetPendingIRQ()							  */
/*	Description  : function used to set pending flag					  */
/*	Input 	     : NVIC_IRQn_t copy_IRQn->interrupt number in vector table*/
/*	return 	     : void													  */
/**************************************************************************/
void MNVIC_voidSetPendingIRQ(NVIC_IRQn_t Copy_IRQn);

/**************************************************************************/
/*  Function_Name: MNVIC_voidClearPendingIRQ()							  */
/*	Description  : function used to clear pending flag					  */
/*	Input 	     : NVIC_IRQn_t copy_IRQn->interrupt number in vector table*/
/*	return 	     : void													  */
/**************************************************************************/
void MNVIC_voidClearPendingIRQ(NVIC_IRQn_t Copy_IRQn);

/**************************************************************************/
/*  Function_Name: MNVIC_u8GetActiveIRQ()								  */
/*	Description  : function used to get active flag						  */
/*	Input 	     : NVIC_IRQn_t copy_IRQn->interrupt number in vector table*/
/*	return 	     : void													  */
/**************************************************************************/
u8 MNVIC_u8GetActiveIRQ(NVIC_IRQn_t Copy_IRQn);

/******************* (C) COPYRIGHT 2021 Zaki ahmed *****END OF FILE****/
#endif //NVIC_INTERFACE_H

