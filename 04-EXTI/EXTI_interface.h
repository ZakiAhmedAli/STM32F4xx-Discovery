/****************************************************************************/
/* @File 	: EXTI_interface.h						 	 				    */
/* @Author	: Zaki Ahmed Hamed					     					    */
/* @Date 	: 1-April-2021						 						    */
/* @Version : V01									 					    */
/* @brief	: This file contains:	 										*/
/*			   - Functions prototypes and public informations				*/
/****************************************************************************/


/***********************************************************
*   @brief: Define guardian to prevent recursive inclusion *
***********************************************************/	
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/** 
  * @brief : EXTI Lines Numbers
  */
	
typedef enum
{
	LINE0 =0,
	LINE1   ,
	LINE2   ,
	LINE3   ,
	LINE4   ,
	LINE5   ,
	LINE6   ,
	LINE7   ,
	LINE8   ,
	LINE9   ,
	LINE10  ,
	LINE11  ,
	LINE12  ,
	LINE13  ,
	LINE14  ,
    LINE15

}LineNumber_t;
  
/** 
  * @brief : Trigger Modes
  */
typedef enum 
{
	RISING ,	
    FALLING,	
    ON_CHANGE
	
}TriggerMode_t;

/** 
  * @brief : Functions Prototypes
  */
  
/** 
  * @brief  Set configuration of a dedicated Exti line and trigger selection.
  * @param  LineNumber_t LineNum , TriggerMode_t Mode
  * @retval void.
  */  
void MEXTI_VoidInit(LineNumber_t LineNum , TriggerMode_t Mode);

 /*************************************************** 
  * @brief  Enable Exti line selection.
  * @param  LineNumber_t LineNum. 
  * @retval void.
  *************************************************/
void MEXTI_VoidEXTIEnable(LineNumber_t LineNum );

/**************************************************** 
  * @brief  Disable Exti line selection.
  * @param  LineNumber_t LineNum. 
  * @retval void.
  *************************************************/
void MEXTI_VoidEXTIDisable(LineNumber_t LineNum );


void EXTI_VoidSoftWareTrigger(LineNumber_t LineNum);


/****************************************************************
  * @brief  Register callback for a dedicated Exti line.
  * @param  *Ptr. function pointer to be stored as callback.
  * @retval void.
  *************************************************************/
  
void MEXTI0_VoidSetCallBack(void (*Ptr) (void));
void MEXTI1_VoidSetCallBack(void (*Ptr) (void));


#endif //EXTI_INTERFACE_H

