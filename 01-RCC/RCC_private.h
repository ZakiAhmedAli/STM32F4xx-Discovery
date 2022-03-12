/**************************************************************************************/
/*	File 		: RCC_private.h						 	 							  */
/*	Author	    : Zaki Ahmed Hamed					     							  */
/*  Date 	    : 26 January 2021						 							  */
/*  Version     : V01									 							  */
/*  Description : This file contains all the RCC register's definitions,	          */
/*				  bits definitions and memory mapping for STM32F40x Connectivity line,*/
/**************************************************************************************/


/*******************************************************
*     @brief: Define to prevent recursive inclusion    *
*******************************************************/	
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/***********RCC Register Definitions*******************/
typedef struct
{
	volatile u32 CR			;	/*Clock control register (RCC_CR) Address offset:0x00*/
	volatile u32 PLLCFGR	;	/*Clock configuration register(RCC_PLLCFGR) Address offset:0x04*/
	volatile u32 CFGR		;	/*Clock configuration register (RCC_CFGR) Address offset:0x08*/
	volatile u32 CIR		;	/*Clock configuration register (RCC_CIR) Address offset:0x0C*/
	volatile u32 AHB1RSTR	;	/*Clock configuration register(RCC_AHB1RSTR) Address offset:0x14*/
	volatile u32 AHB2RSTR	;	/*Clock configuration register(RCC_AHB2RSTR) Address offset:0x18*/
	volatile u32 AHB3RSTR	;
	volatile u32 RESERVED0	;
	volatile u32 APB1RSTR	;	
	volatile u32 APB2RSTR	;
	volatile u32 RESERVED1	;
	volatile u32 RESERVED2	;	
	volatile u32 AHB1ENR	;
	volatile u32 AHB2ENR	;	
	volatile u32 AHB3ENR	;
	volatile u32 RESERVED3	;	
	volatile u32 APB1ENR	;
	volatile u32 APB2ENR	;	
	volatile u32 RESERVED4	;
	volatile u32 RESERVED5	;	
	volatile u32 AHB1LPENR	;
	volatile u32 AHB2LPENR	;	
	volatile u32 AHB3LPENR	;
	volatile u32 RESERVED6	;	
	volatile u32 APB1LPENR	;
	volatile u32 APB2LPENR	;
	volatile u32 RESERVED7	;
	volatile u32 RESERVED8	;	
	volatile u32 BDCR		;
	volatile u32 CSR		;	
	volatile u32 RESERVED9	;
	volatile u32 RESERVED10	;	
	volatile u32 SSCGR		;
	volatile u32 PLLI2SCFGR ;	
	
}RCC_t;

#define RCC	((volatile RCC_t*)(0x40023800))

#define MAX_REG_BITS		32
#define ONE					1
#define ZERO				0

/*****@brief: STM32F40xx_System_Exported_Macros*********/

#define MAX_REG_BITS		32
#define ONE					1
#define ZERO				0
/*-------------------------------------------*/

/*-------------------------------------------*/
/*Bit Masking*/
#define	CFGR_MASK		   0b11
#define	HSI				   0
#define	HSE				   1
#define	PLL				   2

#define	PLLSRC_MASK		  0b1
#define	PLLQ_MASK		  0b1111
#define	PLLP_MASK		  0b11
#define	PLLN_MASK		  0b111111111
#define	PLLM_MASK		  0b11111
						  
#define	HPRE_MASK		  0b1111
#define	PPRE1_MASK		  0b111
#define	PPRE2_MASK		  0b111
/*-----------------------------------------------------*/

/***********  Bit definition for(RCC_CR)register  ********/
#define	HSION		0
#define	HSIRDY		1
#define	RESERVED	2
#define	HSITRIM0	3
#define	HSITRIM1	4
#define	HSITRIM2	5
#define	HSITRIM3	6
#define	HSITRIM4	7
#define	HSICAL0		8
#define	HSICAL1		9
#define	HSICAL2		10
#define	HSICAL3		11
#define	HSICAL4		12
#define	HSICAL5		31
#define	HSICAL6		14
#define	HSICAL7		15
#define	HSEON		16
#define	HSERDY      17
#define	HSEBYP      18
#define	CSSON       19
#define	PLLON       24
#define	PLLRDY      25
#define	PLLI2SON    26
#define	PLLI2SRDY   27
/***********************************************************************/


/***********  Bit definition for(RCC_PLLCFGR)register  ********/
#define PLLQ3       27
#define PLLQ2       26
#define PLLQ1       25
#define PLLQ0		24
#define PLLSRC		22
#define	PLLP1 		17
#define	PLLP0 		16
#define	PLLM5 		5
#define	PLLM4       4
#define	PLLM3       3
#define	PLLM2       2
#define	PLLM1       1
#define	PLLM0       0
/********************************************************/

/***********  Bit definition for(RCC_CFGR)register  ********/
#define MCO21       31
#define MCO20       30
#define MCO2PRE2    29
#define MCO2PRE1    28
#define MCO2PRE0    27
#define MCO1PRE2    26
#define MCO1PRE1    25
#define MCO1PRE0    24
#define I2SSCR      23
#define MCO11       22
#define MCO10       21
#define RTCPRE4     20
#define RTCPRE3     19
#define RTCPRE2     18
#define RTCPRE1     17
#define RTCPRE0     16
#define PPRE22      15
#define PPRE21      14
#define PPRE20      13
#define PPRE12      12
#define PPRE11      11
#define PPRE10      10
#define HPRE3       7
#define HPRE2       6
#define HPRE1       5
#define HPRE0       4
#define SWS1        3
#define SWS0        2
#define SW1         1
#define SW0		    0
/************************************/

/***********  Bit definition for(RCC_CIR)register  ********/
#define CSSC        23
#define Reserved    22
#define PLLI2SRDYC  21
#define PLLRDYC     20
#define HSERDYC     19
#define HSIRDYC     18
#define LSERDYC     17
#define LSIRDYC		16
#define	PLLI2SRDYIE	13
#define	PLLRDYIE    12
#define	HSERDYIE    12
#define	HSIRDYIE    10
#define	LSERDYIE    9
#define	LSIRDYIE    8
#define	CSSF        7
#define	PLLI2SRDYF  5
#define	PLLRDYF     4
#define	HSERDYF     3
#define	HSIRDYF     2
#define	LSERDYF     1
#define	LSIRDYF     0

/***********  Bit definition for(RCC_AHB1ENR)register  ********/
/*
#define OTGHSULPIEN  	30
#define OTGHSEN      	29
#define ETHMACPTPEN  	28
#define ETHMACRXEN   	27
#define ETHMACTXEN   	26
#define ETHMACEN	 	25 	
#define DMA2EN		 	22
#define DMA1EN       	21
#define BKPSRAMEN	 	20
#define CCMDATARAMEN 	18 
#define CRCEN		 	12
#define GPIOIEN		 	8
#define GPIOHEN      	4
#define GPIOGEN      	6
#define GPIOFEN      	5
#define GPIOEEN      	4
#define GPIODEN      	3
#define GPIOCEN      	2
#define GPIOBEN      	1
#define GPIOAEN      	0
*/
/***********  Bit definition for(RCC_AHB2ENR)register  ********/
/*
#define DCMIEN			0
#define CRYPEN          1
#define HASHEN          2
#define RNGEN           3
#define OTGFSEN         4
*/
/***********  Bit definition for(RCC_APB1ENR)register  ********/
/*
#define	DACEN			 29
#define	PWREN            28
#define	CAN2EN           26
#define	CAN1EN           25
#define	I2C3EN           23
#define	I2C2EN           22
#define	I2C1EN           21
#define	UART5EN          20
#define	UART4EN          19
#define	USART3EN         18
#define	USART2EN         17
#define	SPI3EN           15
#define	SPI2EN           14
#define	WWDGEN           11
#define	TIM14EN          8
#define	TIM13EN          7
#define	TIM12EN          6
#define	TIM7EN           5
#define	TIM6EN           4
#define	TIM5EN           3
#define	TIM4EN           2
#define	TIM3EN           1
#define	TIM2EN           0
*/

/***********  Bit definition for(RCC_APB2ENR)register  ********/
/*
#define	TIM11EN			 18
#define	TIM10EN          17
#define	TIM9EN           16
#define	SYSCFGEN         14
#define	SPI1EN           12
#define	SDIOEN           11
#define	ADC3EN           10
#define	ADC2EN           9
#define	ADC1EN           8
#define	USART6EN         5
#define	USART1EN         4
#define	TIM8EN           1
#define	TIM1EN           0



*/


/******************* (C) COPYRIGHT 2021 ZAKI AHMED *****END OF FILE****/

#endif // END OF FILE RCC_PRIVATE_H


