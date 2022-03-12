/****************************************************************************/
/* @File 	: EXTI_private.h						 	 				    */
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
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


/** 
  * @brief : EXTI Base address defenitions
  */
#define EXTI_BASE_ADDERSS		(u32)0x40013C00

/** 
  * @brief : External Interrupt/Event Controller
  */
typedef struct
{
	volatile u32 IMR  ;	   /*!< Interrupt mask register (EXTI_IMR)             Address offset: 0x00*/
	volatile u32 EMR  ;    /*!< Event mask register (EXTI_EMR)                 Address offset: 0x04*/
	volatile u32 RTSR ;    /*!< Rising trigger selection register (EXTI_RTSR)  Address offset: 0x08*/
	volatile u32 FTSR ;    /*!< Falling trigger selection register (EXTI_FTSR) Address offset: 0x0C*/
	volatile u32 SWIER;    /*!< Software interrupt event register (EXTI_SWIER) Address offset: 0x10*/
	volatile u32 PR   ;    /*!< Pending register (EXTI_PR) 					   Address offset: 0x14*/
	
}EXTI_t;

/****** Ptr to struct *****/
#define EXTI 		((volatile EXTI_t*)(EXTI_BASE_ADDERSS))


 /** 
  * @brief : Pending register (EXTI_PR) bits definition
  */
#define PR0		0
#define PR1		1
#define PR2		2
#define PR3		3
#define PR4		4
#define PR5		5
#define PR6		6
#define PR7		7
#define PR8		8
#define PR9		9
#define PR10	10
#define PR11	11
#define PR12	12
#define PR13	13
#define PR14	14
#define PR15	15



/******************* (C) COPYRIGHT 2021 Zaki ahmed *****END OF FILE****/
#endif //EXTI_PRIVATE_H

