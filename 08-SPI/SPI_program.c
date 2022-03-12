/********************************************************************/
/* @file    : SPI_program.c 				 						*/
/* @Author  : Zaki Ahmed Hamed                                      */
/* @Date    : 13 April 2021                                         */
/* @Version : V02                      				                */
/* @brief   : This file provides all the USART firmware functions.	*/ 
/********************************************************************/


#include"STD_TYPES.H"
#include"BIT_MATH.h"

#include"GPIO_interface.h"
#include"SPI_interface.h"
#include"SPI_private.h"
#include"SPI_config.h"

void ( *SPI_CallBack[SPI_MAX_CH] )(u16);

void MSPI_voidInit(u8 Copy_u8SPI_Num)
{
	#if  SPI_STATUS	== SPI_ENABLE
	
			#if   SPI_CLOCK_PHASE == SPI_CPHA_HIGH
				  SET_BIT( SPIx[Copy_u8SPI_Num]->CR1 , CPHA);
			#elif SPI_CLOCK_PHASE == SPI_CPHA_LOW
				  CLR_BIT( SPIx[Copy_u8SPI_Num]->CR1 , CPHA);
			
			#endif
			
			#if   SPI_CLOCK_POLARITY == SPI_IDLE_HIGH
		          SET_BIT( SPIx[Copy_u8SPI_Num]->CR1 , CPOL);	
			#elif SPI_CLOCK_POLARITY == SPI_IDLE_LOW 
			      CLR_BIT( SPIx[Copy_u8SPI_Num]->CR1 , CPOL);	
			
			#endif
			
			#if   SPI_MASTER_SLAVE == SPI_MASTER
				  SET_BIT( SPIx[Copy_u8SPI_Num]->CR1 , MSTR);
			#elif SPI_MASTER_SLAVE == SPI_SLAVE
			      CLR_BIT( SPIx[Copy_u8SPI_Num]->CR1 , MSTR);
			
			#endif
	
	        #if	  SPI_DATA_ORDER == SPI_LSB_FIRST
				  SET_BIT( SPIx[Copy_u8SPI_Num]->CR1 , LSBFIRST); 		
			#elif SPI_DATA_ORDER == SPI_MSB_FIRST
				  CLR_BIT( SPIx[Copy_u8SPI_Num]->CR1 , LSBFIRST); 	
			
			#endif

			#if	  SPI_SS_MANAGE == SW_SLAVE_MANAGEMENT
				  SET_BIT( SPIx[Copy_u8SPI_Num]->CR1 , SSM); 	
			#elif SPI_SS_MANAGE == HW_SLAVE_MANAGEMENT
				  CLR_BIT( SPIx[Copy_u8SPI_Num]->CR1 , SSM); 	
			#endif

		
			#if	  SPI_DATA_FORMAT == SPI_8BIT
				  CLR_BIT( SPIx[Copy_u8SPI_Num]->CR1 , DFF); 	
			#elif SPI_DATA_FORMAT == SPI_16BIT
				  SET_BIT( SPIx[Copy_u8SPI_Num]->CR1 , DFF); 	
			#endif
			
			#if	  SPI_INT_STATUS == SPI_INT_DISABLE
				  SPIx[Copy_u8SPI_Num]->CR2 = CLR; 	
			#elif SPI_INT_STATUS == SPI_TXE_INT_ENABLE
				  SET_BIT(SPIx[Copy_u8SPI_Num]->CR2 , TXEIE);
			#elif SPI_INT_STATUS == SPI_RXNE_INT_ENABLE
				  SET_BIT(SPIx[Copy_u8SPI_Num]->CR2 , RXNEIE);
				  
			#endif			
			
			#if   SPI_TX_DMA == SPI_TX_DMA_ENABLE
				  SET_BIT(SPIx[Copy_u8SPI_Num]->CR2 , TXDMAEN);
			#elif SPI_TX_DMA == SPI_TX_DMA_DISABLE
				  CLR_BIT(SPIx[Copy_u8SPI_Num]->CR2 , TXDMAEN);
				  
			#endif					    

			#if   SPI_RX_DMA == SPI_RX_DMA_ENABLE
				  SET_BIT(SPIx[Copy_u8SPI_Num]->CR2 , RXDMAEN);
			#elif SPI_RX_DMA == SPI_RX_DMA_ENABLE
				  CLR_BIT(SPIx[Copy_u8SPI_Num]->CR2 , RXDMAEN);
			#endif	
	
	SPIx[Copy_u8SPI_Num]->CR1 &= 0xFFC7 ;
	SPIx[Copy_u8SPI_Num]->CR1 |= (SPI_PRESCALLER << 3);
	SET_BIT( SPIx[Copy_u8SPI_Num]->CR1 , SPE);
	
	#elif SPI_STATUS	== SPI_DISABLE
	CLR_BIT( SPIx[Copy_u8SPI_Num]->CR1 , SPE);
	
	#endif
}

u16 MSPI_u16SendRecieveSynch(u8 Copy_u8SPI_Num ,u8 Copy_u8DataToTransmit)
{
	/* clear for slave select pin */
	MGPIO_VoidSetRestPinValue(SPI_SLAVE_PIN , GPIO_LOW);
	
	/* Put data transmit to SPI data register */
	SPIx[Copy_u8SPI_Num]->DR = Copy_u8DataToTransmit;
	
	/* wait Busy flag finish */
	while( GET_BIT(SPIx[Copy_u8SPI_Num]-> BSY) == SET );
	
	/* set for slave select pin */
	MGPIO_VoidSetRestPinValue(SPI_SLAVE_PIN , GPIO_HIGH);
	
	/* return data received */
	return SPIx[Copy_u8SPI_Num]->DR;
}

void MSPI_voidSendRecieveASynch(u8 Copy_u8SPI_Num ,u16 Copy_u8DataToTransmit , void(*Copy_CallBack)(u16) )
{
	/* assign call back */
	SPI_CallBack[Copy_u8SPI_Num] = Copy_CallBack;
	
	/* send data */
	SPIx[Copy_u8SPI_Num]->DR = Copy_u8DataToTransmit;	
}

/************** ISR ****************/
void SPI1_IRQHandler(void)
{
	SPI_CallBack[SPI1]( SPIx[SPI1]->DR );
}

void SPI2_IRQHandler(void)
{
	SPI_CallBack[SPI2]( SPIx[SPI2]->DR );
}

void SPI3_IRQHandler(void)
{
	SPI_CallBack[SPI3]( SPIx[SPI3]->DR );
}

void SPI4_IRQHandler(void)
{
	SPI_CallBack[SPI4]( SPIx[SPI4]->DR );
}

void SPI5_IRQHandler(void)
{
	SPI_CallBack[SPI5]( SPIx[SPI15]->DR );
}

void SPI6_IRQHandler(void)
{
	SPI_CallBack[SPI6]( SPIx[SPI6]->DR );
}

/*********	Copyright 2021 © Zaki Ahmed. All Rights Reserved.****** End of file **************/

