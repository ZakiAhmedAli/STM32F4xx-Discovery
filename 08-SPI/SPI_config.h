/*****************************************************************************/
/*	File 		: SPI_config.h						 	 				 	 */
/*	Author	    : Zaki Ahmed Hamed					     					 */
/*  Date 	    : 13 April 2021						 						 */
/*  Version     : V01									 					 */
/*  Description : This file contains all the SPI configuration parameters	 */
/*****************************************************************************/


/*******************************************************
*     @brief: Define to prevent recursive inclusion    *
*******************************************************/	
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


/* Max number of SPI channels */
#define      SPI_MAX_CH          6 

/*	options	: 
			  1-SPI_ENABLE
			  2-SPI_DISABLE
				
*/
#define SPI_STATUS			  SPI_ENABLE

/* options : SPI_MASTER	
             SPI_SLAVE	
*/
#define SPI_MASTER_SLAVE      SPI_MASTER

/*please put in pair */
#define SPI_SLAVE_PIN   	  PORT,PIN0


/*	options : 1-SPI_IDLE_LOW
			  2-SPI_IDLE_HIGH
*/
#define SPI_CLOCK_POLARITY 		SPI_IDLE_HIGH

/*	options : 1-SPI_CPHA_LOW
			  2-SPI_CPHA_HIGH

*/
#define SPI_CLOCK_PHASE			SPI_CPHA_HIGH


/* options : SPI_FPCLK_DIV_2	
             SPI_FPCLK_DIV_4	
             SPI_FPCLK_DIV_8	
             SPI_FPCLK_DIV_16	
             SPI_FPCLK_DIV_32	
             SPI_FPCLK_DIV_64	
             SPI_FPCLK_DIV_128	
             SPI_FPCLK_DIV_256	
*/

#define SPI_PRESCALLER		SPI_FPCLK_DIV_2
			
/* options : SPI_LSB_FIRST			
			 SPI_MSB_FIRST
*/
#define SPI_DATA_ORDER		SPI_MSB_FIRST

/* options : SPI_8BIT				
			 SPI_16BIT
*/
#define SPI_DATA_FORMAT		SPI_8BIT

/* options : HW_SLAVE_MANAGEMENT	
			 SW_SLAVE_MANAGEMENT	

*/
#define SPI_SS_MANAGE		SW_SLAVE_MANAGEMENT

/* options : SPI_INT_DISABLE    
             SPI_TXE_INT_ENABLE 
             SPI_RXNE_INT_ENABLE
*/
#define SPI_INT_STATUS	    SPI_INT_DISABLE

/* options : SPI_TX_DMA_ENABLE	
             SPI_TX_DMA_DISABLE	
*/                
#define SPI_TX_DMA			SPI_TX_DMA_DISABLE

/* options : SPI_RX_DMA_ENABLE	
             SPI_RX_DMA_DISABLE	
*/

#define SPI_TX_DMA			SPI_RX_DMA_DISABLE	

#enfid //SPI_CONFIG_H
