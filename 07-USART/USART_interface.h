/*****************************************************************************/
/*	File 		: USART_interface.h						 	 				 */
/*	Author	    : Zaki Ahmed Hamed					     					 */
/*  Date 	    : 03-April-2021						 						 */
/*  Version     : V01									 					 */
/*  Description : This file contains all the USART functions prototypes for, */
/*				   the USART firmware library, all public information's		 */
/*****************************************************************************
*   @attention                                                               *
*    -Please feel free to contact me on the details below                    *
*    -If you would like to share your experience, feel free to contact me    * 
*	 -I hope these driver help you, if you have questions or problems        *
*        please feel free to contact me                                      *
*                                                                            *
*			Copyright 2021 © Zaki Ahmed. All Rights Reserved.                *
*****************************************************************************/


/*******************************************************
*     @brief: Define to prevent recursive inclusion    *
*******************************************************/	
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

/**** @brief : public defenitions***********/ 
#define USART1   0
#define USART2   1
#define USART3   2
#define UART4    3
#define UART5    4
#define USART6   5
#define UART7    6
#define UART8    7





/**************************************************************************/
/*  Function_Name: MUSART_VoidInit							              */
/*	Description  : function used to initialize all USART configurations	  */
/*	Input 	     : u8 Copy_u8UsartNum , u32 Copy_U32BaudRate              */
/*	return 	     : void													  */
/**************************************************************************/
void MUSART_VoidInit(u8 Copy_u8UsartNum , u32 Copy_U32BaudRate);

/**************************************************************************/
/*  Function_Name: MUSART_VoidTransmitByteSynch							  */
/*	Description  : function used to transmit character synchronization	  */
/*	Input 	     : u8 Copy_u8UsartNum , u8 Copy_U8Data                    */
/*	return 	     : void													  */
/**************************************************************************/
void MUSART_VoidTransmitByteSynch(u8 Copy_u8UsartNum , u8 Copy_U8Data);

/*****************************************************************************/
/*  Function_Name: MUSART_VoidTransmitSynch							         */
/*	Description  : the function used to transmit  string  in synchronize mode*/
/*	Input 	     : u8 Copy_u8UsartNum , u8 *Copy_U8Data                      */
/*	return 	     : void													     */
/*****************************************************************************/
void MUSART_VoidTransmitSynch(u8 Copy_u8UsartNum , u8 *Copy_U8Data);

u8 MUSART_U8ReceiveSych(u8 Copy_u8UsartNum ,u8 *Copy_U8Data);

u8 MUSART_U8ReceiveByteSych(u8 Copy_u8UsartNum);

u8 MUSART_U8ReadDataRegister ( u8 Copy_u8UsartNum );

void MUSART_VoidClearFlags(u8 Copy_u8UsartNum );

/************* CallBack functions*******************/
void USART1_VoidSetCallBack(void (*Copy_Ptr)(void));
void USART2_VoidSetCallBack(void (*Copy_Ptr)(void));
void USART3_VoidSetCallBack(void (*Copy_Ptr)(void));
void UART4_VoidSetCallBack (void (*Copy_Ptr)(void));
void UART5_VoidSetCallBack (void (*Copy_Ptr)(void));
void USART6_VoidSetCallBack(void (*Copy_Ptr)(void));
void UART7_VoidSetCallBack (void (*Copy_Ptr)(void));
void UART8_VoidSetCallBack (void (*Copy_Ptr)(void));

#endif //USART_INTERFACE_H

