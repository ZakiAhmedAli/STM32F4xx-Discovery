/*****************************************************************************************************************************
*  Layer       : MCAL																  
*
*  SWC         : GPIO 																  
*
*  File 	   : GPIO_program.c						 	 						  
*
*  Author	   : Zaki Ahmed Hamed					     							  
*
*  Date 	   : 28-January-2021							 							  
*
*  Version     : V03									 							  
*
*  LOG         : V01 -> 28-January-2021: Initial creation 											  
*
*				 V02 -> 1-March-2021: Edit functions MGPIO_VoidSetPinMode,MGPIO_VoidSetPinOutSpeed ,MGPIO_VoidSetPinOutType,
*						MGPIO_VoidSetPinPullUpDown,MGPIO_VoidSetPinValue,MGPIO_VoidSetRestPinValue
*
*	             V03 -> 29-Sep-2021: Add u8 MGPIO_U8Init(PinConfig_t *PinConfig) to set required pin configuration options,
*
*  Description : This file provides all the GPIO firmware functions.				  
/****************************************************************************************************************************/

/*==================[inclusions]============================================*/
	
/*********************** STD LIB DIRECTIVES *********************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

/*********************** Component DIRECTIVES *******************/
#include"GPIO_interface.h"
#include"GPIO_private.h"
#include"GPIO_config.h"


static GPIOX_t* GPIOx[MAX_GPIO_PERIPHERALS]={GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH, GPIOI, GPIOJ, GPIOK};

u8 MGPIO_U8Init(PinConfig_t *PinConfig)
{
	u8 Local_U8ErrorState = OK;
	
	if(PinConfig == NULL)
	{
		Local_U8ErrorState = NULL_POINTER;
	}
	else if( (PinConfig->GPIO_u8Port <= GPIO_PORTK) && (PinConfig->GPIO_u8PinNumber <= GPIO_PIN15) )
	{
		/*1- Select GPIO Mode: GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_AF, GPIO_MODE_ANALOG */
		(GPIOx[PinConfig->GPIO_u8Port]->MODER) &= ~( MODER_MASK << (PinConfig->GPIO_u8PinNumber)*MODER_PIN_ACESS_BITS);
		(GPIOx[PinConfig->GPIO_u8Port]->MODER) |= ( PinConfig->GPIO_u8Mode << (PinConfig->GPIO_u8PinNumber)*MODER_PIN_ACESS_BITS );
		
		/*2- Select GPIO Port: Pull Up, Pull Down, NO Pull Up_PUll Down*/
		GPIOx[PinConfig->GPIO_u8Port]->PUPDR &= ~(PUPDR_MASK << (PinConfig->GPIO_u8PinNumber)*PUPDR_PIN_ACESS_BITS );
		GPIOx[PinConfig->GPIO_u8Port]->PUPDR |= (PinConfig->GPIO_u8PullUpDown << (PinConfig->GPIO_u8PinNumber)*PUPDR_PIN_ACESS_BITS);
		
		/*3- Set output type, output speed in case of output mode*/
		if(PinConfig->GPIO_u8Mode == GPIO_MODE_OUTPUT)
		{
			/* Select GPIO Output Type: Output Push-Pull , Output Open Drain*/
			GPIOx[PinConfig->GPIO_u8Port]->OTYPER &= ~(OTYPER_MASK << (PinConfig->GPIO_u8PinNumber) );
			GPIOx[PinConfig->GPIO_u8Port]->OTYPER |= ( (PinConfig->GPIO_u8OutputType) << (PinConfig->GPIO_u8PinNumber) );
			
			/* Select GPIO Output Speed: Low, Medium, High, Very High*/
			GPIOx[PinConfig->GPIO_u8Port]->OSPEEDR &= ~(OSPEEDR_MASK<< (PinConfig->GPIO_u8PinNumber)*OSPEEDR_PIN_ACESS_BITS);
			GPIOx[PinConfig->GPIO_u8Port]->OSPEEDR |= (PinConfig->GPIO_u8OutputSpeed<< (PinConfig->GPIO_u8PinNumber)*OSPEEDR_PIN_ACESS_BITS);			
		}
		
		/*4- set Alternate function option in case of Alternate function mode*/
		if(PinConfig->GPIO_u8Mode == GPIO_MODE_AF)
		{
			u8 LOC_u8RegNum = PinConfig->GPIO_u8PinNumber /8;
			u8 LOC_u8PinNum = PinConfig->GPIO_u8PinNumber %8;
			
			(GPIOx[PinConfig->GPIO_u8Port]) -> AFRx[LOC_u8RegNum] &= ~(AFR_MASK<< (LOC_u8PinNum*AFR_PIN_ACESS_BITS) );
			(GPIOx[PinConfig->GPIO_u8Port]) -> AFRx[LOC_u8RegNum] |= (PinConfig->GPIO_u8AFOption<<(LOC_u8PinNum*AFR_PIN_ACESS_BITS));
		}
	}
	else
	{
		Local_U8ErrorState = NOK;
	}
	
	return Local_U8ErrorState;
	
}


u8 MGPIO_VoidSetPinValue(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Value)
{
	u8 Local_U8ErrorState =OK;
	
	if(Copy_U8Port <= GPIO_PORTK && Copy_U8Pin<=GPIO_PIN15)
	{
		GPIOx[Copy_U8Port]->ODR &= ~(1U << Copy_U8Pin);
		GPIOx[Copy_U8Port]->ODR |= ~(Copy_U8Value << Copy_U8Pin);
	}
	else
	{
		Local_U8ErrorState = NOK;
	}
	
	return Local_U8ErrorState;
	
}


u8 MGPIO_VoidSetRestPinValue(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Value)
{
	u8 Local_U8ErrorState =OK;
	
	if(Copy_U8Port <= GPIO_PORTK && Copy_U8Pin<=GPIO_PIN15)
	{
		if(Copy_U8Value == GPIO_HIGH)
		{

			GPIOx[Copy_U8Port]->BSRR = (1U << Copy_U8Pin); 
		}
		else if(Copy_U8Value == GPIO_LOW)
		{

			GPIOx[Copy_U8Port]->BSRR = (1U << (Copy_U8Pin+16));		
		}
	}
	else
	{
		Local_U8ErrorState = NOK;
	}
	return Local_U8ErrorState;
	
}


void MGPIO_VoidSetPinMode(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Mode)
{

	 GPIOx[Copy_U8Port]->MODER |= (Copy_U8Mode << (MODER_PIN_ACESS_BITS*Copy_U8Pin) );

}

void MGPIO_VoidSetPinOutSpeed(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Speed)
{
	GPIOx[Copy_U8Port]->OSPEEDR |= (Copy_U8Speed << (OSPEEDR_PIN_ACESS_BITS*Copy_U8Pin) );
}

void MGPIO_VoidSetPinOutType(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Type )
{

	GPIOx[Copy_U8Port]->OTYPER |= (Copy_U8Type << Copy_U8Pin );
}


void MGPIO_VoidSetPinPullUpDown(u8 Copy_U8Port,u8 Copy_U8Pin ,u8 Copy_U8PullType)
{

	GPIOx[Copy_U8Port]->PUPDR |= (Copy_U8PullType << (PUPDR_PIN_ACESS_BITS*Copy_U8Pin) );

}

u8 MGPIO_u8GetPinvalue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 LOC_U8Value = 0;
	
	LOC_U8Value = GET_BIT(GPIOx[Copy_u8Port]->IDR ,Copy_u8Pin);

	return LOC_U8Value;
	
}
