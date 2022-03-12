/*********************************************************************************************
* @File    : EXTI_program.c						 	 				    
* @Author  : Zaki Ahmed Hamed					     					    
* @Date    : 1-April-2021						 						    
* @Version : V01									 					    
* @brief   : This file provides firmware functions to manage the following
*			  functionalities of the Extended Interrupts and events controller (EXTI) peripheral:
*             + Initialization and de-initialization functions
*             + IO operation functions
**************************************************************************************************/

/******includes ********/
#include"STD_TYPES.h"
#include"BIT_MATH.h"	


#include"EXTI_interface.h"
#include"EXTI_private.h"
#include"EXTI_config.h"

void (*EXTI0_CallBack) (void);
void (*EXTI1_CallBack) (void);


void MEXTI_VoidInit(LineNumber_t LineNum , TriggerMode_t Mode)
{
	switch(Mode)
	{
		/* Configure rising trigger */
		case RISING   : SET_BIT(EXTI->RTSR ,LineNum);
			 break;
		/* Configure falling trigger */
		case FALLING  : SET_BIT(EXTI->FTSR ,LineNum);
			 break;
		/* Configure On change trigger */
		case ON_CHANGE: SET_BIT(EXTI->RTSR ,LineNum);
						SET_BIT(EXTI->FTSR ,LineNum);
		break;
	}
	/*Enable EXTI Line*/
	SET_BIT(EXTI->IMR ,LineNum);
}

void MEXTI_VoidEXTIEnable(LineNumber_t LineNum )
{
	/*Enable EXTI Line*/
	SET_BIT(EXTI->IMR ,LineNum);
}

void MEXTI_VoidEXTIDisable(LineNumber_t LineNum )
{
	/*Disable EXTI Line*/
	CLR_BIT(EXTI->IMR ,LineNum);
}

void EXTI_VoidSoftWareTrigger(LineNumber_t LineNum)
{
	EXTI->SWIER |= (SET<<LineNum);
}

void MEXTI0_VoidSetCallBack(void (*Ptr) (void))
{
	EXTI0_CallBack = Ptr;
}

/*********EXTI0 IRQ**********/
void EXTI0_IRQHandler(void)
{
	SET_BIT(EXTI->PR ,PR0);
	EXTI0_CallBack();
}
///////////////////////////////////////////

void MEXTI1_VoidSetCallBack(void (*Ptr) (void))
{
	EXTI1_CallBack = Ptr;
}

/*********EXTI0 IRQ**********/
void EXTI1_IRQHandler(void)
{
	SET_BIT(EXTI->PR ,PR1);
	EXTI1_CallBack();
}
