/*****************************************************************************/
/*	File 		: SPI_private.h						 	 				 	 */
/*	Author	    : Zaki Ahmed Hamed					     					 */
/*  Date 	    : 13 April 2021						 						 */
/*  Version     : V01									 					 */
/*  Description : This file contains all the SPI register's definitions,	 */
/*				  bits definitions and memory mapping for STM32F40x.		 */
/*****************************************************************************/


/*******************************************************
*     @brief: Define to prevent recursive inclusion    *
*******************************************************/	
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


/******************************************************************************/
/*                 Serial peripheral interface (SPI)                     	  */
/******************************************************************************/

/*********************************************************
*     @brief: SPI from 1 : 6 Base address definitions    *
*********************************************************/	
#define SPI1_BASE       0x40013000		
#define SPI2_BASE       0x40003800
#define SPI3_BASE 		0x40003C00
#define SPI4_BASE	    0x40013400
#define SPI5_BASE		0x40015000 
#define SPI6_BASE		0x40015400 

/*********************************************************
*     @brief: SPI register's struct definition's	    *
*********************************************************/
typedef struct
{
	volatile u32 CR1    ;
	volatile u32 CR2    ;
	volatile u32 SR     ;
	volatile u32 DR     ;
	volatile u32 CRCPR  ;	
	volatile u32 RXCRCR ;	
	volatile u32 TXCRCR ;	
	volatile u32 I2SCFGR;	
	volatile u32 I2SPR  ;	

}SPI_REG_t


volatile static SPI_REG_t* SPIx[6] = { (SPI_REG_t*)(SPI1_BASE),
									   (SPI_REG_t*)(SPI2_BASE),
									   (SPI_REG_t*)(SPI3_BASE),
									   (SPI_REG_t*)(SPI4_BASE),
									   (SPI_REG_t*)(SPI5_BASE),
									   (SPI_REG_t*)(SPI6_BASE)
	
								     };
									 
									 
/******** SPI control register 1 (SPI_CR1) bits **********/									 
#define  BIDIMODE		15
#define  BIDIOE         14
#define  CRCEN          13
#define  CRCNEXT        12
#define  DFF            11
#define  RXONLY         10
#define  SSM            9
#define  SSI            8
#define  LSBFIRST       7
#define  SPE            6
#define  BR2            5
#define  BR1            4
#define  BR0            3
#define  MSTR           2
#define  CPOL           1
#define  CPHA			0		


/******** SPI control register 2 (SPI_CR2) bits **********/	
#define  TXEIE         7
#define  RXNEIE        6
#define  ERRIE         5
#define  FRF           4
#define  Res           3
#define  SSOE          2
#define  TXDMAEN       1 
#define  RXDMAEN       0

/******** SPI status registe bits (SPI_SR)**********/	
#define  FRE           8
#define  BSY           7
#define  OVR           6
#define  MODF          5
#define  CRCERR        4
#define  UDR           3
#define  CHSIDE        2
#define  TXE           1
#define  RXNE		   0	 

/********** SPI_I2S configuration register (SPI_I2SCFGR) bits********/
#define  I2SMOD        11
#define  I2SE          10
#define  I2SCFG9	   9
#define  I2SCFG8       8
#define  PCMSYNC       7
#define  Res           6
#define  I2SSTD5       5
#define  I2SSTD4       4
#define  CKPOL         3
#define  DATLEN1       2
#define  DATLEN1       1
#define  CHLEN		   0



#endif //SPI_PRIVATE_H


