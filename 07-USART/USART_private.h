/*****************************************************************************/
/*	File 		: USART_private.h						 	 				 */
/*	Author	    : Zaki Ahmed Hamed					     					 */
/*  Date 	    : 03-April-2021						 						 */
/*  Version     : V01									 					 */
/*  Description : This file contains all the USART register's definitions,	 */
/*				  bits definitions and memory mapping for STM32F40x.		 */
/*****************************************************************************/


/*******************************************************
*     @brief: Define to prevent recursive inclusion    *
*******************************************************/	
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

	/*==============================================================================
	=  Memory map Universal synchronous asynchronous receiver transmitter (USART)  =
	==============================================================================*/
#define  USART1_BASE_ADDRESS  (u32)0x40011000
#define  USART2_BASE_ADDRESS  (u32)0x40004400 
#define  USART3_BASE_ADDRESS  (u32)0x40004800
#define  UART4_BASE_ADDRESS   (u32)0x40004C00
#define  UART5_BASE_ADDRESS   (u32)0x40005000
#define  USART6_BASE_ADDRESS  (u32)0x40011400 
#define  UART7_BASE_ADDRESS   (u32)0x40007800
#define  UART8_BASE_ADDRESS   (u32)0x40007C00


/*Universal synchronous asynchronous receiver transmitter (USART) register's */
typedef struct
{
  volatile u32 SR;
  volatile u32 DR;
  volatile u32 BRR;
  volatile u32 CR1;
  volatile u32 CR2;
  volatile u32 CR3;
  volatile u32 GPTR;
  
}USART_t;

static volatile USART_t *USARTx[8] = {  ((USART_t*)(USART1_BASE_ADDRESS)),
									    ((USART_t*)(USART2_BASE_ADDRESS)),
									    ((USART_t*)(USART3_BASE_ADDRESS)),
									    ((USART_t*)(UART4_BASE_ADDRESS )),
									    ((USART_t*)(UART5_BASE_ADDRESS )),
									    ((USART_t*)(USART6_BASE_ADDRESS)),
									    ((USART_t*)(UART7_BASE_ADDRESS )),
									    ((USART_t*)(UART8_BASE_ADDRESS ))
									 
									 };
														
/***** @ brief : private constant **********/									
#define USART_DISABLE           0
#define USART_ENABLE            1

#define _8BIT_WORD_LENGTH       0
#define _9BIT_WORD_LENGTH       1

#define PARITY_DISABLE          0
#define EVEN_PARITY             1
#define ODD_PARITY              2

#define INT_DISABLE             0
#define TXE_INT_ENABLE          1
#define TCE_INT_ENABLE          3
#define RXNE_INT_ENABLE         5

#define TRANSMITTER_DISABLE     0
#define TRANSMITTER_ENABLE      1

#define RECEIVER_DISBLE         0
#define RECEIVER_ENABLE         1

#define ONE_STOP_BIT            0
#define HALF_STOP_BIT           1
#define TWO_STOP_BIT            2
#define ONE_AND_HALF_STOP_BIT   3


/*Status register (USART_SR) Bits definition's */									
#define CTS 	  9U
#define LBD       8U
#define TXE       7U
#define TC        6U
#define RXNE      5U
#define IDLE      4U
#define ORE       3U
#define NF        2U
#define FE        1U
#define PE		  0U						

/*Control register 1 (USART_CR1)Bits definition's */

#define OVER8      15U
#define Reserved   14U
#define UE         13U
#define M          12U
#define WAKE       11U
#define PCE        10U
#define PS         9U
#define PEIE       8U
#define TXEIE      7U
#define TCIE       6U
#define RXNEIE     5U
#define IDLEIE     4U
#define TE         3U
#define RE         2U
#define RWU        1U
#define SBK		   0U

/*Control register 2 (USART_CR2)Bits definition's */
#define LINEN     14U
#define STOP1     13U
#define STOP0     12U
#define CLKEN     11U
#define CPOL      10U
#define CPHA      9U
#define LBCL      8U
#define Res2      7U
#define LBDIE     6U
#define LBDL      5U
#define Res1      7U
#define ADD3      3U
#define ADD2      2U
#define ADD1      1U
#define ADD0	  0U

/*Control register 3 (USART_CR3)Bits definition's */
#define ONEBIT    11U
#define CTSIE     10U
#define CTSE      9U
#define RTSE      8U
#define DMAT      7U
#define DMAR      6U
#define SCEN      5U
#define NACK      4U
#define HDSEL     3U
#define IRLP      2U
#define IREN      1U
#define EIE       0U
/***********************************************************/

//Clock: 8 MHz 
#define UART_BAUDRATE_1200_CLK_8M       0X1A0B
#define UART_BAUDRATE_2400_CLK_8M       0X0D05
#define UART_BAUDRATE_4800_CLK_8M       0X0683
#define UART_BAUDRATE_9600_CLK_8M       0X0341
#define UART_BAUDRATE_19200_CLK_8M      0X01A1
#define UART_BAUDRATE_15200_CLK_8M      0X45

#endif //USART_PRIVATE_H

