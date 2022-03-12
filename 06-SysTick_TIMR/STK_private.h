/*****************************************************************************/
/*	File 		: STK_private.h						 	 				     */
/*	Author	    : Zaki Ahmed Hamed					     					 */
/*  Date 	    : 02-April-2021						 						 */
/*  Version     : V01									 					 */
/*  Description : This file contains all the STK register's definitions,	 */
/*				  bits definitions and memory mapping for STM32F40x.		 */
/*****************************************************************************/


/*******************************************************
*     @brief: Define to prevent recursive inclusion    *
*******************************************************/	
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H



/**********************************************************/
/*                 SysTick timer (STK)                    */
/**********************************************************/

/** @defgroup STK_Private_Defines
* 
*
*	@defgroup STK_Private_Macros
*@{
*/
#define     MSTK_SINGLE_INTERVAL      0
#define     MSTK_PERIODIC_INTERVAL    1

#define     STK_BASE_ADDRESS		(u32)0xE000E010

/*
*	@defgroup STK register's definitions
*@{
*/
typedef struct
{
	volatile u32 CTRL;	/*SysTick control and status register (STK_CTRL)  Address offset: 0x00*/
	volatile u32 LOAD;  /*SysTick control and status register (STK_CTRL)  Address offset: 0x04*/
	volatile u32 VAL;   /*SysTick control and status register (STK_CTRL)  Address offset: 0x08*/
	volatile u32 CALIB; /*SysTick control and status register (STK_CTRL)  Address offset: 0x0C*/
}STK_t;

/*
*	@defgroup ptr to struct
*@{
*/
#define STK 	((volatile STK_t *)(STK_BASE_ADDRESS))

/*
*	@defgroup : SysTick control and status register (STK_CTRL) bits definitions 
*@{
*/
#define  COUNTFLAG	16	
#define  CLKSOURCE  2
#define  TICKINT    1
#define  ENABLE		0


#endif //STK_PRIVATE_H

