/**************************************************************************************/
/*	File 		: USART_config.h						 	 						  */
/*	Author	    : Zaki Ahmed Hamed					     							  */
/*  Date 	    : 03-April-2021 						 							  */
/*  Version     : V01									 							  */
/*  Description : This file contains all the USARTx configuration parameters          */
/**************************************************************************************/


/*******************************************************
*     @brief: Define to prevent recursive inclusion    *
*******************************************************/	
#ifndef USART_CONFIG_H
#define USART_CONFIG_H

						  
									  
/* System Clock */
#define F_CPU           8000000UL			

#define USART_STATUS  	USART_ENABLE						  
									  
/*	Options : ONE_STOP_BIT          
			  HALF_STOP_BIT         
			  TWO_STOP_BIT          
			  ONE_AND_HALF_STOP_BIT 
*/
#define STOP_BIT	ONE_STOP_BIT


/* Options : _8BIT_WORD_LENGTH
			 _9BIT_WORD_LENGTH
			 */
#define WORD_LENGTH		_8BIT_WORD_LENGTH
/* Options : PARITY_DISABLE
             EVEN_PARITY   
             ODD_PARITY    
*/
#define USART_PARITY	PARITY_DISABLE

/* Options : INT_DISABLE     
             TXE_INT_ENABLE  
             TCE_INT_ENABLE  
             RXNE_INT_ENABLE 
*/
#define USART_INTERRUPT  RXNE_INT_ENABLE

/*Options : TRANSMITTER_ENABLE
			TRANSMITTER_DISABLE		
*/
#define USART_TRANSMITT  TRANSMITTER_ENABLE
 


/*Options : RECEIVER_DISBLE
			RECEIVER_ENABLE		
*/
#define USART_RECEIVER RECEIVER_ENABLE


#endif //USART_CONFIG_H

