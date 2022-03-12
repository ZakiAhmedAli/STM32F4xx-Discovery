/*****************************************************************************/
/*	File 		: SPI_interface.h					 	 				 	 */
/*	Author	    : Zaki Ahmed Hamed					     					 */
/*  Date 	    : 13 April 2021						 						 */
/*  Version     : V01									 					 */
/*  Description : This file contains all the SPI functions prototypes, 	     */
/*				  public macros				 								 */
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
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#define SPI_DISABLE             0
#define SPI_ENABLE              1

/* clock phase macros option */
#define	SPI_CPHA_LOW	 		0
#define	SPI_CPHA_HIGH			1

/* clock polarity macros*/
#define SPI_IDLE_LOW         	0
#define SPI_IDLE_HIGH        	1

/*********** prescaler options ***************/

#define  SPI_FPCLK_DIV_2		0x00U
#define  SPI_FPCLK_DIV_4		0x01U
#define  SPI_FPCLK_DIV_8		0x02U
#define  SPI_FPCLK_DIV_16		0x03U
#define  SPI_FPCLK_DIV_32		0x04U
#define  SPI_FPCLK_DIV_64		0x05U
#define  SPI_FPCLK_DIV_128		0x06U
#define  SPI_FPCLK_DIV_256		0x07U

/* Data order macros*/
#define SPI_LSB_FIRST			1
#define SPI_MSB_FIRST			0

#define HW_SLAVE_MANAGEMENT	    2
#define SW_SLAVE_MANAGEMENT	    3

/* Data format macros*/
#define SPI_8BIT				0
#define SPI_16BIT				1


#define SPI_MASTER				1
#define SPI_SLAVE				0

#define SPI_INT_DISABLE         0
#define SPI_TXE_INT_ENABLE      1
#define SPI_RXNE_INT_ENABLE     2

#define RECEIVE_ONLY		    0
#define SEND_RECEIVE		    1

#define SPI_TX_DMA_ENABLE		2
#define SPI_TX_DMA_DISABLE		3

#define SPI_RX_DMA_ENABLE		2
#define SPI_RX_DMA_DISABLE		3

#define SPI1    0U
#define SPI2    1U
#define SPI3    2U
#define SPI4    3U
#define SPI5    4U
#define SPI6	5U

void MSPI_voidInit(u8 Copy_u8SPI_Num);


u16 MSPI_u16SendRecieveSynch(u8 Copy_u8SPI_Num ,u8 Copy_u8DataToTransmit);

void MSPI_voidSendRecieveASynch(u8 Copy_u8SPI_Num ,u16 Copy_u8DataToTransmit , void(*Copy_CallBack)(u16) );








/*********	Copyright 2021 © Zaki Ahmed. All Rights Reserved.****** End of file **************/

#endif //SPI_INTERFACE_H