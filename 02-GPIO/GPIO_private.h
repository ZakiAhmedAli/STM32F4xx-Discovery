/**************************************************************************************
*  Layer       : MCAL																  *
*  SWC         : GPIO 																  *
*  File 	   : GPIO_private.h						 	 						      *
*  Author	   : Zaki Ahmed Hamed					     							  *
*  Date 	   : 29-Sep-2021						 							      *
*  Version     : V02									 							  *
*  Description : This file contains all the GPIOx register's definitions,	          *
*				  bits definitions and memory mapping for STM32F4x	 				  *
**************************************************************************************/


/*******************************************************
*     @brief: Define to prevent recursive inclusion    *
*******************************************************/	
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/***********GPIOx Base Address Definitions*******************/
#define GPIOA_BASE	0x40020000
#define GPIOB_BASE	0x40020400
#define GPIOC_BASE	0x40020800
#define GPIOD_BASE	0x40020C00
#define GPIOE_BASE	0x40021000
#define GPIOF_BASE	0x40021400
#define GPIOG_BASE	0x40021800
#define GPIOH_BASE	0x40021C00
#define GPIOI_BASE	0x40022000
#define GPIOJ_BASE	0x40022400
#define GPIOK_BASE	0x40022800


/********************	GPIO register definition structure	***************************/
typedef struct
{
	volatile u32 MODER	;
	volatile u32 OTYPER	;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR	;
	volatile u32 IDR	;
	volatile u32 ODR	;
	volatile u32 BSRR	;
	volatile u32 LCKR	;
	volatile u32 AFRx[2];
	
}GPIOX_t;


/********************	GPIO Peripherial definitions	***************************/
#define GPIOA  ( (GPIOX_t*)GPIOA_BASE )
#define GPIOB  ( (GPIOX_t*)GPIOB_BASE )
#define GPIOC  ( (GPIOX_t*)GPIOC_BASE )
#define GPIOD  ( (GPIOX_t*)GPIOD_BASE )
#define GPIOE  ( (GPIOX_t*)GPIOE_BASE )
#define GPIOF  ( (GPIOX_t*)GPIOF_BASE )
#define GPIOG  ( (GPIOX_t*)GPIOG_BASE )
#define GPIOH  ( (GPIOX_t*)GPIOH_BASE )
#define GPIOI  ( (GPIOX_t*)GPIOI_BASE )
#define GPIOJ  ( (GPIOX_t*)GPIOJ_BASE )
#define GPIOK  ( (GPIOX_t*)GPIOK_BASE )

#define MAX_GPIO_PERIPHERALS 11

#define	MODER_MASK					 	 	   0b11
#define	OTYPER_MASK					 	 	   0b1
#define	OSPEEDR_MASK						   0b11
#define	PUPDR_MASK							   0b11
#define	AFR_MASK							   0b1111

#define MODER_PIN_ACESS_BITS               	    2
#define OSPEEDR_PIN_ACESS_BITS               	2
#define PUPDR_PIN_ACESS_BITS               	    2
#define AFR_PIN_ACESS_BITS               	    4

#endif //GPIO_PRIVATE_H


