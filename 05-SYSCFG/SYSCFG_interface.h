/****************************************************************************/
/* @File 	: SYSCFG_interface.h						 	 				*/
/* @Author	: Zaki Ahmed Hamed					     					    */
/* @Date 	: 1-April-2021						 						    */
/* @Version : V01									 					    */
/* @brief	: This file contains:	 										*/
/*			   - Function prototypes and public informations				*/
/****************************************************************************/


/***********************************************************
*   @brief: Define guardian to prevent recursive inclusion *
***********************************************************/	
#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H

/** 
  * @brief : EXTI Lines Numbers
  */
typedef enum
{
	EXTI0 =0,
	EXTI1   ,
	EXTI2   ,
	EXTI3   ,
	EXTI4   ,
	EXTI5   ,
	EXTI6   ,
	EXTI7   ,
	EXTI8   ,
	EXTI9   ,
	EXTI10  ,
	EXTI11  ,
    EXTI12  ,
	EXTI13  ,
	EXTI14  ,
	EXTI15
	
}EXTILineNum_t;
  
  
void MSYSCFG_VoidEXTIConfigInit(EXTILineNum_t LineNum , u8 Copy_U8PortMap);  
  
#endif //SYSCFG_INTERFACE_H

