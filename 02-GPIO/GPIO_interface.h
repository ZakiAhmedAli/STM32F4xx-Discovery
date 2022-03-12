/*****************************************************************************************************************************
*  Layer       : MCAL																  
*
*  SWC         : GPIO 																  
*
*  File 	   : GPIO_interface.h							 	 						  
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
*	             V03 -> 29-Sep-2021: 1-Add u8 MGPIO_U8Init(PinConfig_t *PinConfig) to set required pin configuration options.
*									 2-Add PinConfig_t	struct.
*			
*  Description : This file contains STM32F40x GPIO Function prototypes/Instruction   
*				  public informatins 						  						  
*********************************************************************************************************************************************************************/


/*******************************************************
*     @brief: Define to prevent recursive inclusion    *
*******************************************************/	
#ifndef _GPIO_INTERFACEE_H
#define _GPIO_INTERFACEE_H


/*

MODER register
00: Input (reset state)
01: General purpose output mode
10: Alternate function mode
11: Analog mode
-----------------
OSPEEDRy[1:0]: Port x configuration bits (y = 0..15)
These bits are written by software to configure the I/O output speed.
00: Low speed       ->0HZ to 8MHZ 
01: Medium speed    ->up  to 50MHz
10: High speed      ->up  to 100MHz
11: Very high speed ->up  to 180MHz

*/


typedef struct
{
	u8 GPIO_u8Port;				
	u8 GPIO_u8PinNumber;	/* Specifies the GPIO pin to be configured */
	u8 GPIO_u8Mode;         /* Specifies the operatin mode for selected pin */
	u8 GPIO_u8OutputSpeed;  /* Specifies the speed of the selected pin */
	u8 GPIO_u8OutputType;   /* Specifies the output type for selected pin*/
	u8 GPIO_u8PullUpDown;   /* Specifies the pull-down / pull-up activation for selected pin */
	u8 GPIO_u8AFOption;     /* Specifies alternate function value */
	
}PinConfig_t;


/*!<*************Ports Definitions********************/
#define GPIO_PORTA				0U
#define GPIO_PORTB				1U
#define GPIO_PORTC				2U
#define GPIO_PORTD				3U
#define GPIO_PORTE				4U
#define GPIO_PORTF				5U
#define GPIO_PORTG 				6U
#define GPIO_PORTH				7U
#define GPIO_PORTI				8U
#define GPIO_PORTJ				9U
#define GPIO_PORTK				10U

/*!<*************Pins Definitions********************/
#define GPIO_PIN0 				0U
#define GPIO_PIN1 				1U
#define GPIO_PIN2 				2U
#define GPIO_PIN3 				3U
#define GPIO_PIN4 				4U
#define GPIO_PIN5 				5U
#define GPIO_PIN6 				6U
#define GPIO_PIN7 				7U
#define GPIO_PIN8 				8U
#define GPIO_PIN9 				9U
#define GPIO_PIN10				10U
#define GPIO_PIN11				11U
#define GPIO_PIN12				12U
#define GPIO_PIN13				13U
#define GPIO_PIN14				14U
#define GPIO_PIN15				15U


#define GPIO_HIGH			1
#define GPIO_LOW			0


/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup GPIO_Private_Constants GPIO Private Constants
  * @{
  */

#define  GPIO_MODE_INPUT           0x00U                                     /*!< Input Mode                   */
#define  GPIO_MODE_OUTPUT          0x01U                                     /*!< Output Mode                  */
#define  GPIO_MODE_AF              0x02U                                     /*!< Alternate Function Mode      */
#define  GPIO_MODE_ANALOG          0x03U                                     /*!< Analog Mode                  */

#define  GPIO_MODE_OUTPUT_PP       0x00U                                     /*!< Push Pull Mode               */
#define  GPIO_MODE_OUTPUT_OD       0x01U                                     /*!< Open Drain Mode              */

//#define  GPIO_OUTPUT_PP            GPIO_MODE_OUTPUT_PP | GPIO_MODE_OUTPUT                                  /*!< Output Push Pull Mode                 */

#define  GPIO_MODE_AF_PP           (GPIO_MODE_OUTPUT_PP | GPIO_MODE_AF)      /*!< Alternate Function Push Pull Mode     */
#define  GPIO_MODE_AF_OD           (GPIO_MODE_OUTPUT_OD | GPIO_MODE_AF)      /*!< Alternate Function Open Drain Mode    */
   
   /************************************************************
   * @defgroup GPIO_pull_define GPIO pull define
   * @brief GPIO Pull-Up or Pull-Down Activation
   * @{
   ***********************************************************/  
#define  GPIO_NOPULL        0x00U   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_PULLUP        0x01U   /*!< Pull-up activation                  */
#define  GPIO_PULLDOWN      0x02U   /*!< Pull-down activation                */


/**
  * @}
  */

/** @defgroup GPIO_speed_define  GPIO speed define
  * @brief GPIO Output Maximum frequency
  * @{GPIO_u8OutputSpeed
  */
#define  GPIO_SPEED_FREQ_LOW         0x00U  /*!< IO works at 2 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_MEDIUM      0x01U  /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_HIGH        0x02U  /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
#define  GPIO_SPEED_FREQ_VERY_HIGH   0x03U  /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */

/** 
  * @brief   AF 0 selection  
  */ 
#define GPIO_AF0               (0x00)  /* Alternate Function mapping                       */
#define GPIO_AF0_RTC_50Hz      (0x00)  /* RTC_50Hz Alternate Function mapping                       */
#define GPIO_AF0_MCO           (0x00)  /* MCO (MCO1 and MCO2) Alternate Function mapping            */
#define GPIO_AF0_TAMPER        (0x00)  /* TAMPER (TAMPER_1 and TAMPER_2) Alternate Function mapping */
#define GPIO_AF0_SWJ           (0x00)  /* SWJ (SWD and JTAG) Alternate Function mapping             */
#define GPIO_AF0_TRACE         (0x00)  /* TRACE Alternate Function mapping                          */

/** 
  * @brief   AF 1 selection  
  */ 
#define GPIO_AF1_TIM1          (0x01)  /* TIM1 Alternate Function mapping */
#define GPIO_AF1_TIM2          (0x01)  /* TIM2 Alternate Function mapping */

/** 
  * @brief   AF 2 selection  
  */ 
#define GPIO_AF2_TIM3          (0x02)  /* TIM3 Alternate Function mapping */
#define GPIO_AF2_TIM4          (0x02)  /* TIM4 Alternate Function mapping */
#define GPIO_AF2_TIM5          (0x02)  /* TIM5 Alternate Function mapping */

/** 
  * @brief   AF 3 selection  
  */ 
#define GPIO_AF3_TIM8          (0x03)  /* TIM8 Alternate Function mapping  */
#define GPIO_AF3_TIM9          (0x03)  /* TIM9 Alternate Function mapping  */
#define GPIO_AF3_TIM10         (0x03)  /* TIM10 Alternate Function mapping */
#define GPIO_AF3_TIM11         (0x03)  /* TIM11 Alternate Function mapping */

/** 
  * @brief   AF 4 selection  
  */ 
#define GPIO_AF4_I2C1          (0x04)  /* I2C1 Alternate Function mapping */
#define GPIO_AF4_I2C2          (0x04)  /* I2C2 Alternate Function mapping */
#define GPIO_AF4_I2C3          (0x04)  /* I2C3 Alternate Function mapping */

/** 
  * @brief   AF 5 selection  
  */ 
#define GPIO_AF5_SPI1          (0x05)  /* SPI1 Alternate Function mapping        */
#define GPIO_AF5_SPI2          (0x05)  /* SPI2/I2S2 Alternate Function mapping   */
#define GPIO_AF5_I2S3ext       (0x05)  /* I2S3ext_SD Alternate Function mapping  */

/** 
  * @brief   AF 6 selection  
  */ 
#define GPIO_AF6_SPI3          ((u8)0x06)  /* SPI3/I2S3 Alternate Function mapping  */
#define GPIO_AF6_I2S2ext       ((u8)0x06)  /* I2S2ext_SD Alternate Function mapping */

/** 
  * @brief   AF 7 selection  
  */ 
#define GPIO_AF7_USART1        ((u8)0x07)  /* USART1 Alternate Function mapping     */
#define GPIO_AF7_USART2        ((u8)0x07)  /* USART2 Alternate Function mapping     */
#define GPIO_AF7_USART3        ((u8)0x07)  /* USART3 Alternate Function mapping     */
#define GPIO_AF7_I2S3ext       ((u8)0x07)  /* I2S3ext_SD Alternate Function mapping */

/** 
  * @brief   AF 8 selection  
  */ 
#define GPIO_AF8_UART4         ((u8)0x08)  /* UART4 Alternate Function mapping  */
#define GPIO_AF8_UART5         ((u8)0x08)  /* UART5 Alternate Function mapping  */
#define GPIO_AF8_USART6        ((u8)0x08)  /* USART6 Alternate Function mapping */

/** 
  * @brief   AF 9 selection 
  */ 
#define GPIO_AF9_CAN1          ((u8)0x09)  /* CAN1 Alternate Function mapping  */
#define GPIO_AF9_CAN2          ((u8)0x09)  /* CAN2 Alternate Function mapping  */
#define GPIO_AF9_TIM12         ((u8)0x09)  /* TIM12 Alternate Function mapping */
#define GPIO_AF9_TIM13         ((u8)0x09)  /* TIM13 Alternate Function mapping */
#define GPIO_AF9_TIM14         ((u8)0x09)  /* TIM14 Alternate Function mapping */

/** 
  * @brief   AF 10 selection  
  */ 
#define GPIO_AF10_OTG_FS        ((u8)0x0A)  /* OTG_FS Alternate Function mapping */
#define GPIO_AF10_OTG_HS        ((u8)0x0A)  /* OTG_HS Alternate Function mapping */

/** 
  * @brief   AF 11 selection  
  */ 
#define GPIO_AF11_ETH           ((u8)0x0B)  /* ETHERNET Alternate Function mapping */

/** 
  * @brief   AF 12 selection  
  */ 
#define GPIO_AF12_FSMC          ((u8)0x0C)  /* FSMC Alternate Function mapping                     */
#define GPIO_AF12_OTG_HS_FS     ((u8)0x0C)  /* OTG HS configured in FS, Alternate Function mapping */
#define GPIO_AF12_SDIO          ((u8)0x0C)  /* SDIO Alternate Function mapping                     */

/** 
  * @brief   AF 13 selection  
  */ 
#define GPIO_AF13_DCMI          ((u8)0x0D)  /* DCMI Alternate Function mapping */

/** 
  * @brief   AF 15 selection  
  */ 
#define GPIO_AF15_EVENTOUT      ((u8)0x0F)  /* EVENTOUT Alternate Function mapping */

/******************************************************************************
 * Function Name:  MGPIO_U8Init
 *
 * Description:	the function initialize the required pin configuration  options
 *
 * Parameters: 1- PinConfig: const pointer to GPIO_PinConfig_t structure to set configurations
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/
u8 MGPIO_U8Init(PinConfig_t *PinConfig);

/******************************************************************************
 * Function Name:  MGPIO_VoidSetPinValue
 *
 * Description:	the function sets an output values on the output pin
 *
 * Parameters: 1- Copy_u8Port : the port of the required output pin, refer to port possible options
 * 			   2- Copy_u8pin  : the pin number of the required output pin, refer to pin number possible options
 * 			   3- Copy_u8value: the required pin state, refer to pin value possible options
 *
 * Return:	ErrorState , Type:u8
 *
 ******************************************************************************/
u8 MGPIO_VoidSetPinValue(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Value);

u8 MGPIO_VoidSetRestPinValue(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Value);

void MGPIO_VoidSetPinMode(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Mode );

void MGPIO_VoidSetPinOutSpeed(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Speed);

void MGPIO_VoidSetPinOutType(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Type );

void MGPIO_VoidSetPinPullUpDown(u8 Copy_U8Port,u8 Copy_U8Pin ,u8 Copy_U8PullType);

/*******************************************************************/
/* Descrption : this function is used to Return pin value		   */
/* Input      : Port Name , Pin Number 							   */	
/* Return	  : pin value[high/low]								   */
/*******************************************************************/
u8 MGPIO_u8GetPinvalue(u8 Copy_u8Port , u8 Copy_u8Pin);


void MGPIO_VoidSetPinLock	  (u8 Copy_U8Port ,u8 Copy_U8Pin);


#endif //GPIO


