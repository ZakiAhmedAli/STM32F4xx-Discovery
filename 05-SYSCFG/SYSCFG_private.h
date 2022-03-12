/****************************************************************************/
/* @File 	: SYSCFG_private.h						 	 				    */
/* @Author	: Zaki Ahmed Hamed					     					    */
/* @Date 	: 1-April-2021						 						    */
/* @Version : V01									 					    */
/* @brief	: This file contains:	 										*/
/*			   - Data structures and the address mapping for all peripherals*/
/*             - peripherals registers declarations and bits definition     */
/*             - Macros to access peripheral’s registers hardware           */
/****************************************************************************/

/***********************************************************
*   @brief: Define guardian to prevent recursive inclusion *
***********************************************************/	
#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H

 /*==============================================================================
              ##### System configuration controller (SYSCFG) #####
 ===============================================================================*/
/** 
  * @brief : System configuration controller (SYSCFG) Base address defenitions
  */
#define SYSCFG_BASE_ADDERSS		(u32)0x40013800

typedef struct
{
	volatile u32 MEMRMP ;
	volatile u32 PMC    ;
	volatile u32 EXTICRx[4];
	volatile u32 CMPCR  ;
	
}SYSCFG_t;

#define SYSCFG		((volatile SYSCFG_t*)(SYSCFG_BASE_ADDERSS))  
  
#endif //SYSCFG_PRIVATE_H

