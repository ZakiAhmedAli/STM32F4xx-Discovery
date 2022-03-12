
/********************************************************************/
/*	@File 	: STK_program.c						 	 				*/
/*	@Author	: Zaki Ahmed Hamed					     				*/
/*  @Date 	: 02-April-2021						 					*/
/*  @Version: V01									 				*/
/*  @brief  : This file provides all the STK APIs functions.		*/ 
/********************************************************************/


/*--------- includes -------------*/
#include"..\include\STD_TYPES.h"
#include"..\include\BIT_MATH.h"
     
#include"..\include\STK_interface.h"
#include"..\include\STK_private.h"
#include"..\include\STK_config.h"


/** @defgroup STK 
  * @brief STK driver modules
  * @{
  */

/** @defgroup STK_Private_TypesDefinitions
  * @{
  */


/** @defgroup STK_Private_Defines
* 
* 
*/
	
/*@defgroup STK_Private_Macros
*@{ 
*@}
*/

/* @defgroup STK_Private_Variables
* @{
* 
*	  @brief: Define Variable for interval mode
*     @brief: Define pointer to function
*@}
*/

static u8 Global_U8Flag;

void (*STK_CALLBACK)(void);
 
/* 
* @defgroup STK_Private_FunctionPrototypes
* @{
*
*/


// AHB = EXT = 8MHZ & CLOCK OF MSTK = AHB / 8 = 8MHZ / 8 = 1MHZ = 1 Micro For Each Count
void MSTK_VoidInit(STK_CLK_t ClockSource)
{
	switch(ClockSource)
	{
		case AHB_CLK      : SET_BIT(STK->CTRL ,CLKSOURCE);	break;
		
		case AHB_DIV_EIGHT: CLR_BIT(STK->CTRL ,CLKSOURCE);	break;
		
		default			  : /*RETURN ERROR*/break;
	}
	
	/* Disable Systick , Disable SysTick interrupt*/
	MSTK_VoidStopTimer();
}

void MSTK_VoidSetBusyWait(u32 Copy_U32Ticks)
{
	/*Load ticks in load register*/
	STK->LOAD = Copy_U32Ticks;
	/* start timer */
	SET_BIT(STK->CTRL ,ENABLE);
	/* waiting flag =1 then loads the RELOAD value again, and begins counting.*/
	while( !GET_BIT(STK->CTRL ,COUNTFLAG) );
	/* stop timer */
	SET_BIT(STK->CTRL ,ENABLE);
	STK->LOAD = 0;
	STK->VAL  = 0;
	
	
}

void MSTK_VoidDelayMS(u32 Copy_U32Ticks)
{
	MSTK_VoidSetBusyWait(Copy_U32Ticks * 1000);
}

void MSTK_VoidSetIntervalSingle(u32 Copy_U32Ticks , void (*Copy_Ptr)(void))
{
	/*Load ticks in load register*/
	STK->LOAD = Copy_U32Ticks;
	/* start timer */
	SET_BIT(STK->CTRL ,ENABLE);
	
	/* *Save CallBack */
	STK_CALLBACK = Copy_Ptr;
	/* Set interval single mode*/
	Global_U8Flag = MSTK_SINGLE_INTERVAL;
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL ,TICKINT);
}

void MSTK_VoidSetIntervalPeriodic(u32 Copy_U32Ticks , void (*Copy_Ptr)(void))
{
		/*Load ticks in load register*/
	STK->LOAD = Copy_U32Ticks;
	/* start timer */
	SET_BIT(STK->CTRL ,ENABLE);
	
	/* Save CallBack */
	STK_CALLBACK = Copy_Ptr;
	/* Set interval periodic mode*/
	Global_U8Flag = MSTK_PERIODIC_INTERVAL;
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL ,TICKINT);
}

void MSTK_VoidStopTimer(void)
{
	/* disable interrupt */
	CLR_BIT(STK->CTRL ,TICKINT);
	/* stop counting */
	CLR_BIT(STK->CTRL ,ENABLE);
	
	STK->LOAD = 0;
	STK->VAL = 0;
	
}

u32 MSTK_U32GetElapsedTime(void)
{
	return (STK->LOAD - STK->VAL);
}

u32 MSTK_U32GetRemainingTime(void)
{
	return STK->VAL;	
}

void Systick_Handler(void)
{
	if(Global_U8Flag == MSTK_SINGLE_INTERVAL)
	{
		MSTK_VoidStopTimer();
	}
	
	STK_CALLBACK();
	
}

