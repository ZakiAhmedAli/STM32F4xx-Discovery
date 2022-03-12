/****************************************************************************/
/*	File 		: STK_private.h						 	 				    */
/*	Author	    : Zaki Ahmed Hamed					     					*/
/*  Date 	    : 02-April-2021						 						*/
/*  Version     : V01									 					*/
/*  Description : This file contains all the STK Functions prototypes,	 	*/
/*				  public informations		 								*/
/****************************************************************************/


/*******************************************************
*     @brief: Define to prevent recursive inclusion    *
*******************************************************/	
#ifndef STK_INTEFACE_H
#define STK_INTEFACE_H

typedef enum
{
	AHB_CLK,
	AHB_DIV_EIGHT

}STK_CLK_t;

void MSTK_VoidInit(STK_CLK_t ClockSource);

void MSTK_VoidSetBusyWait(u32 Copy_U32Ticks);

void MSTK_VoidDelayMS(u32 Copy_U32Ticks);

void MSTK_VoidSetIntervalSingle(u32 Copy_U32Ticks , void (*Copy_Ptr)(void));

void MSTK_VoidSetIntervalPeriodic(u32 Copy_U32Ticks , void (*Copy_Ptr)(void));

void MSTK_VoidStopTimer(void);

u32 MSTK_U32GetElapsedTime(void);

u32 MSTK_U32GetElapsedTime(void);

u32 MSTK_U32GetRemainingTime(void);

#endif //STK_INTEFACE_H

