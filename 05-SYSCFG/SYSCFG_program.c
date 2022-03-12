/*************************************************************************************
* @File    : SYSCFG_program.c						 	 				             *
* @Author  : Zaki Ahmed Hamed					     					             *
* @Date    : 1-April-2021						 						             *
* @Version : V01									 					             *
* @brief   : This file provides firmware functions to manage the System configuration*
*************************************************************************************/

/******includes ********/
#include"..\include\STD_TYPES.h"
#include"..\include\BIT_MATH.h"	

#include"..\include\SYSCFG_interface.h"
#include"..\include\SYSCFG_config.h"
#include"..\include\SYSCFG_private.h"



void MSYSCFG_VoidEXTIConfigInit(EXTILineNum_t LineNum , u8 Copy_U8PortMap)
{
	
	/* Get the register index */
	u8 LOC_u8RegIndex = LineNum/4;
	LineNum %= 4;
	
	/* Clear the four bits first */
	SYSCFG->EXTICRx[LOC_u8RegIndex] &= ~(0xF<<(LineNum*4));
	/* Write into the four bits */
	SYSCFG->EXTICRx[LOC_u8RegIndex] |= (Copy_U8PortMap<<(LineNum*4));
	
}

