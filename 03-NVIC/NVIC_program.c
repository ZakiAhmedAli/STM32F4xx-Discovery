/************************************************************************/
/*  @Layer  : MCAL                                                      */
/*  @SWC    : NVIC                                                      */
/*	@File 	: NVIC_program.c						 	 				*/
/*	@Author	: Zaki Ahmed Hamed					     					*/
/*  @Date 	: 27 March 2021						 						*/
/*  @Version: V01									 					*/
/*  @brief  : This file provides all the NVIC firmware functions.		*/ 
/************************************************************************/


/*==================[inclusions]============================================*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"NVIC_interface.h"
#include"NVIC_config.h"
#include"NVIC_private.h"


/** @defgroup NVIC 
  * @brief NVIC driver modules
  * @{
  */

/** @defgroup NVIC_Private_TypesDefinitions
  * @{
  */




/** @defgroup NVIC_Private_Defines
* 
*
*	@defgroup NVIC_Private_Macros
*@{ 
*@}
*/
#define GROUPING_BASE   0x05FA0300
#define ONE_HUND 	    0x100 // 0x100 Hex  ---> 256 Decimal
#define FOUR_BIT        4


/* @defgroup NVIC_Private_Variables
* @{
* 
* 
* 
* @}
* 
* 
* @defgroup NVIC_Private_FunctionPrototypes
* @{
*
*/

void MNVIC_VoidPriorityInit(NVIC_IRQn_t Copy_IRQn ,u8 Copy_U8GroupPrio ,u8 Copy_U8SubPrio ,u32 Copy_U32Grouping)
{
	u8 LOC_U8Priorit= Copy_U8SubPrio|Copy_U8GroupPrio<<((Copy_U32Grouping-GROUPING_BASE)/ONE_HUND);
	
	
	NVIC->IPR[Copy_IRQn] = (LOC_U8Priorit<<FOUR_BIT);
	
	SCB->AIRCR = Copy_U32Grouping;
}

void MNVIC_voidEnableIRQ(NVIC_IRQn_t Copy_IRQn)
{
	NVIC->ISER[Copy_IRQn / MAX_REG_BIT] = (SET<<(Copy_IRQn % MAX_REG_BIT));
	
}

void MNVIC_voidDisableIRQ(NVIC_IRQn_t Copy_IRQn)
{
	NVIC->ICER[Copy_IRQn / MAX_REG_BIT] = (SET<<(Copy_IRQn % MAX_REG_BIT));
	
}

void MNVIC_voidSetPendingIRQ(NVIC_IRQn_t Copy_IRQn)
{
	NVIC->ISPR[Copy_IRQn / MAX_REG_BIT] = (SET<<(Copy_IRQn % MAX_REG_BIT));
	
}

void MNVIC_voidClearPendingIRQ(NVIC_IRQn_t Copy_IRQn)
{
	NVIC->ICPR[Copy_IRQn / MAX_REG_BIT] = (SET<<(Copy_IRQn % MAX_REG_BIT));
	
}

u8 MNVIC_u8GetActiveIRQ(NVIC_IRQn_t Copy_IRQn)
{
	u8 LOC_U8Result = 0;
	
	LOC_U8Result = GET_BIT(NVIC->IABR[Copy_IRQn/MAX_REG_BIT] ,(Copy_IRQn % MAX_REG_BIT) );
	return LOC_U8Result;
	
}




/******************* (C) COPYRIGHT 2021 Zaki ahmed *****END OF FILE****/
