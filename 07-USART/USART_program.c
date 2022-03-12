/********************************************************************/
/*	@File 	: USART_program.c						 	 			*/
/*	@Author	: Zaki Ahmed Hamed					     				*/
/*  @Date 	: 03-April-2021						 					*/
/*  @Version: V01									 				*/
/*  @brief  : This file provides all the USART firmware functions.	*/ 
/********************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

/*********************** Component DIRECTIVES *******************/
#include"GPIO_interface.h"
#include"GPIO_private.h"

#include"USART_interface.h"
#include"USART_private.h"
#include"USART_config.h"

#define THRESHOLD_VALUE  1000000UL

/**************Pointer to functions to be assigned to IRQ**********************/
static void (*USART1_CallBack)(void);
static void (*USART2_CallBack)(void);
static void (*USART3_CallBack)(void);
static void (*UART4_CallBack )(void);
static void (*UART5_CallBack )(void);
static void (*USART6_CallBack)(void);
static void (*UART7_CallBack )(void);
static void (*UART8_CallBack )(void);

void MUSART_VoidInit(u8 Copy_u8UsartNum , u32 Copy_U32BaudRate)
{

	u32 LOC_U32Mantissa = ( F_CPU ) / ( 16 * Copy_U32BaudRate ) ;

	u32 LOC_U32Fraction = ( ( (F_CPU * 100) / (16 * Copy_U32BaudRate) ) % 100 ) * 16 ;
	if( LOC_U32Fraction > 1500 )
	{
		 LOC_U32Mantissa += 1 ;
		 LOC_U32Fraction  = 0 ;
	}
	USARTx[Copy_u8UsartNum]->BRR =Copy_U32BaudRate;

	#if	  USART_STATUS == USART_ENABLE
				  USARTx[Copy_u8UsartNum]->SR=0;
				/*!< Specifies the number of data bits transmitted or received in a frame.
				This parameter can be a value of @ref WORD_LENGTH */	
			#if   WORD_LENGTH == _8BIT_WORD_LENGTH
					CLR_BIT(USARTx[Copy_u8UsartNum]->CR1 ,M);
			#elif WORD_LENGTH == _9BIT_WORD_LENGTH
					SET_BIT(USARTx[Copy_u8UsartNum]->CR1 ,M);
			#endif		  

			#if    USART_PARITY == PARITY_DISABLE
					   CLR_BIT(USARTx[Copy_u8UsartNum]->CR1 ,PCE);
			
			#elif  USART_PARITY == EVEN_PARITY 
					   SET_BIT(USARTx[Copy_u8UsartNum]->CR1 ,PCE);
					   CLR_BIT(USARTx[Copy_u8UsartNum]->CR1 ,WAKE);	
	
			#elif  USART_PARITY == ODD_PARITY 
					   SET_BIT(USARTx[Copy_u8UsartNum]->CR1 ,PCE);
					   SET_BIT(USARTx[Copy_u8UsartNum]->CR1 ,WAKE);	
			#endif
			
			#if   USART_INTERRUPT == INT_DISABLE
					  CLR_BIT(USARTx[Copy_u8UsartNum]->CR1 ,RXNEIE);			
					  CLR_BIT(USARTx[Copy_u8UsartNum]->CR1 ,TCIE);
						CLR_BIT(USARTx[Copy_u8UsartNum]->CR1 ,TXEIE);


			#elif USART_INTERRUPT == TXE_INT_ENABLE
					  SET_BIT(USARTx[Copy_u8UsartNum]->CR1 ,TXEIE);
			#elif USART_INTERRUPT == TCE_INT_ENABLE
					  SET_BIT(USARTx[Copy_u8UsartNum]->CR1 ,TCE);
			#elif USART_INTERRUPT == RXNE_INT_ENABLE
					  SET_BIT(USARTx[Copy_u8UsartNum]->CR1 ,RXNEIE);
			#endif
			
			
			
			/*!< Specifies wether the Transmit mode is enabled or disabled.
											This parameter can be a value of @ref USART_TRANSMITT */				
			#if    USART_TRANSMITT == TRANSMITTER_ENABLE
						 SET_BIT(USARTx[Copy_u8UsartNum]->CR1 ,TE); 
			#elif  USART_TRANSMITT == TRANSMITTER_DISABLE
					 CLR_BIT(USARTx[Copy_u8UsartNum]->CR1 ,TE); 
			#endif
			
				/*!< Specifies wether the receive mode is enabled or disabled.
											This parameter can be a value of @ref USART_RECEIVER */			
			#if    USART_RECEIVER == RECEIVER_ENABLE
						 SET_BIT(USARTx[Copy_u8UsartNum]->CR1 ,RE); 
			#elif  USART_RECEIVER == RECEIVER_DISBLE
					   CLR_BIT(USARTx[Copy_u8UsartNum]->CR1 ,RE); 
			#endif
			
			
				/*!< Specifies the number of stop bits transmitted.
						 This parameter can be a value of @ref USART_Stop_Bits */
			#if    STOP_BIT	== ONE_STOP_BIT
						 USARTx[Copy_u8UsartNum]->CR2 |= (0<<STOP1)|(0<<STOP0);
			#elif  STOP_BIT	== HALF_STOP_BIT 
						 USARTx[Copy_u8UsartNum]->CR2 |= (0<<STOP1)|(1<<STOP0); 
			#elif  STOP_BIT	== TWO_STOP_BIT 
						 USARTx[Copy_u8UsartNum]->CR2 |= (1<<STOP1)|(0<<STOP0);
			#elif  STOP_BIT	== ONE_AND_HALF_STOP_BIT 
					 USARTx[Copy_u8UsartNum]->CR2 |= (1<<STOP1)|(1<<STOP0);

			#endif

			/* assign Baude rate in Baud rate register (USART_BRR)*/
			USARTx[Copy_u8UsartNum]->BRR = (LOC_U32Mantissa << 4) | (LOC_U32Fraction / 100) ;
			USARTx[Copy_u8UsartNum]->CR1 |=(1<<UE);
	
	#elif USART_STATUS == USART_DISABLE
		    USARTx[Copy_u8UsartNum]->CR1 |=(0<<SBK);
	
	#endif
	
	 /* TX pin configuration */	
    MGPIO_VoidSetPinMode      (PORTB ,PIN6 , GPIO_MODE_AF_PP    );
	MGPIO_VoidSetPinPullUpDown(PORTB ,PIN6 , GPIO_NOPULL        );
    MGPIO_VoidSetPinAF        (PORTB ,PIN6 , GPIO_AF7_USART1    );
    MGPIO_VoidSetPinOutSpeed  (PORTB ,PIN6 , GPIO_SPEED_FREQ_LOW);
	 /* RX pin configuration */ 
	MGPIO_VoidSetPinMode      (PORTB ,PIN7 , GPIO_MODE_AF_PP    );
	MGPIO_VoidSetPinPullUpDown(PORTB ,PIN7 , GPIO_NOPULL        );
	MGPIO_VoidSetPinAF        (PORTB ,PIN7 , GPIO_AF7_USART1    );
}

void MUSART_VoidTransmitByteSynch(u8 Copy_u8UsartNum , u8 Copy_U8Data)
{
	USARTx[Copy_u8UsartNum]->DR = Copy_U8Data;
	/* Wait untill transmition finished.*/
	while( !GET_BIT(USARTx[Copy_u8UsartNum]->SR ,TC) );
	
   /*The TC bit can also be cleared by writing a '0' to it. This clearing*/	
	CLR_BIT(USARTx[Copy_u8UsartNum]->SR ,TC);
}

void MUSART_VoidTransmitSynch(u8 Copy_u8UsartNum , u8 *Copy_U8Data)
{
		while(*Copy_U8Data != 0)
		MUSART_VoidTransmitByteSynch( Copy_u8UsartNum , *Copy_U8Data++);
				/*
	u8 LOC_u8Iterator = 0 ;
	
	while(Copy_U8Data[LOC_u8Iterator] != '\0')
	{
	  USARTx[Copy_u8UsartNum]->DR = Copy_U8Data[LOC_u8Iterator] ;
		MUSART_VoidTransmitByteSynch( Copy_u8UsartNum , Copy_U8Data[LOC_u8Iterator] );
*/
		/* Wait untill transmition finished.*/
		//while( GET_BIT(USARTx[Copy_u8UsartNum]->SR ,TC) == 0);
		
	//	LOC_u8Iterator++;
	//}	
		
}

u8 MUSART_U8ReceiveSych(u8 Copy_u8UsartNum , u8 *Copy_U8Data)
{
	u8 Local_u8State = 1;
	/*check if data received*/
	if(GET_BIT(USARTx[Copy_u8UsartNum]->SR , RXNE) == 1)
	{
		*Copy_U8Data = USARTx[Copy_u8UsartNum]->DR;
	}
	else
	{
	   Local_u8State =0;
	}
	
	return Local_u8State;
}

u8 MUSART_U8ReceiveByteSych(u8 Copy_u8UsartNum)
{
	u8 LOC_u8DataRecieve = 0;
	u32 LOC_TimeOut      = 0 ;
	
	 /*wait till Receive complete */
	 while( (GET_BIT(USARTx[Copy_u8UsartNum]->SR , RXNE) == 0) && (LOC_TimeOut < THRESHOLD_VALUE) )
	 {
		 LOC_TimeOut++;
	 }
	 if(LOC_TimeOut == THRESHOLD_VALUE)
	 {
		 LOC_u8DataRecieve = 255;
	 }
	 else
	 {
		 // Getting the first byte of the register to be returned.
		 LOC_u8DataRecieve = USARTx[Copy_u8UsartNum]->DR;
	 }		 
	 
	 return LOC_u8DataRecieve;
	 
}

void MUSART_VoidClearFlags(u8 Copy_u8UsartNum ){

	/* Clear all flags */
	USARTx[Copy_u8UsartNum]-> SR = 0;

}

u8 MUSART_U8ReadDataRegister ( u8 Copy_u8UsartNum ){

	return (USARTx[Copy_u8UsartNum] -> DR );

}

void USART1_VoidSetCallBack(void (*Copy_Ptr)(void))
{
	USART1_CallBack = Copy_Ptr;
}

void USART2_VoidSetCallBack(void (*Copy_Ptr)(void))
{
	USART2_CallBack = Copy_Ptr;
}

void USART3_VoidSetCallBack(void (*Copy_Ptr)(void))
{
	USART3_CallBack = Copy_Ptr;

}

void UART4_VoidSetCallBack (void (*Copy_Ptr)(void))
{
	UART4_CallBack = Copy_Ptr;
}

void UART5_VoidSetCallBack (void (*Copy_Ptr)(void))
{
	UART5_CallBack  = Copy_Ptr;
}

void USART6_VoidSetCallBack(void (*Copy_Ptr)(void))
{
	USART6_CallBack = Copy_Ptr;
}

void UART7_VoidSetCallBack (void (*Copy_Ptr)(void))
{
	UART7_CallBack = Copy_Ptr;
	
}

void UART8_VoidSetCallBack (void (*Copy_Ptr)(void))
{
	UART8_CallBack  = Copy_Ptr;
}


void USART1_IRQHandler(void)
{
	
	USART1_CallBack();
}

void USART2_IRQHandler(void)
{
	USARTx[USART2]->SR = 0;	
	USART2_CallBack();
}

void USART3_IRQHandler(void)
{
	USARTx[USART3]->SR = 0;	
	USART3_CallBack();
}

void UART4_IRQHandler(void)
{
	USARTx[UART4]->SR = 0;	
	UART4_CallBack();
}

void UART5_IRQHandler(void)
{
	USARTx[UART5]->SR = 0;	
	UART5_CallBack();
}

void USART6_IRQHandler(void)
{
	USARTx[USART6]->SR = 0;	
	USART6_CallBack();
}

void UART7_IRQHandler(void)
{
	USARTx[UART7]->SR = 0;	
	UART7_CallBack();
}

void UART8_IRQHandler(void)
{
	USARTx[UART8]->SR = 0;	
	UART8_CallBack();
}


/******************* Copyright 2021 © Zaki Ahmed. All Rights Reserved. *****END OF FILE****/
