/*****************************************************************************/
/*	File 		: NVIC_private.h						 	 				 */
/*	Author	    : Zaki Ahmed Hamed					     					 */
/*  Date 	    : 27 March 2021						 						 */
/*  Version     : V01									 					 */
/*  Description : This file contains all the NVIC register's definitions,	 */
/*				  bits definitions and memory mapping for STM32F40x.		 */
/*****************************************************************************/


/*******************************************************
*     @brief: Define to prevent recursive inclusion    *
*******************************************************/	
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H



/******************************************************************************/
/*                  Nested Vectored Interrupt Controller                      */
/******************************************************************************/
/** @defgroup NVIC_Private_Defines
* 
*
*	@defgroup NVIC_Private_Macros
*@{
*/

/***********NVIC Base Address *******************/
#define NVIC_BASE_ADDRESS	0xE000E100

/***********System control block (SCB) Base Address*****/
#define SCB_BASE_ADDRESS    0xE000ED00

typedef struct							
{
	volatile u32 ISER     [8  ]; 
	volatile u32 RESERVED0[24 ];
	volatile u32 ICER     [8  ];
	volatile u32 RESERVED1[24 ];
	volatile u32 ISPR     [8  ];
	volatile u32 RESERVED2[24 ];
	volatile u32 ICPR     [8  ];	
	volatile u32 RESERVED3[24 ];
	volatile u32 IABR     [8  ];
	volatile u32 RESERVED4[56 ];
	volatile u8  IPR      [240];	
	
}NVIC_t;


#define  NVIC 		   ((volatile NVIC_t*)(NVIC_BASE_ADDRESS))

#define  NVIC_STIR     *((volatile u32*)(NVIC_BASE_ADDRESS+0xE00))


typedef struct
{
	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCSR;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 RESERVED;
	volatile u32 MMAR;
	volatile u32 BFAR;
	volatile u32 AFSR;	
}SCB_t;
 
#define SCB ((volatile SCB_t*)(SCB_BASE_ADDRESS))

#define MAX_REG_BIT	 (32U)

/******************* (C) COPYRIGHT 2021 Zaki ahmed *****END OF FILE****/
#endif //NVIC_PRIVATE_H

