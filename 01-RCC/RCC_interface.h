/******************************************************************************************************************************
*  Author	   : zaki ahmed									  														
*
*  Date 	   : 16 August 2021
*
*  Description : RCC interface file[function prototypes , macros]														
*
*  Version     : V03
*
*  LOG         : V01 -> Initial creation				          														
*
*			   : V02 -> Add [PllConfig_t]struct for  PLL parameter, 
*                 		 Add void RCC_u8PLLConfig (const PllConfig_t* PllConfig)The Function that Configure PLL Clock.
*
*			   : V03 -> Add function RCC_u8BusesPrescaler(u8 Copy_U8BusId, u8 Copy_U8prescaler) to set Buses prescaler
*
*************************************************************************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	

#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H




/*----------CLOCK TYPES OPTIONS--------------*/
typedef enum
{	
	RCC_HSE_CRYSTAL = 0,
	RCC_HSE_RC,
	RCC_HSI   ,
	RCC_PLL   ,
	
}ClKSrc_t;


typedef struct
{
	u8 RCC_u8PLLSRC;
	u8 RCC_u8PLLQ;
	u8 RCC_u8PLLP;
	u8 RCC_u8PLLN;
	u8 RCC_u8PLLM;
	
}PllConfig_t;


/*----------BUS OPTIONS----------------------*/
#define RCC_AHB3		0
#define RCC_AHB2		1
#define RCC_AHB1		2
#define RCC_AHB			5

#define RCC_APB2		3
#define RCC_APB1		4

/*PLl Input Options*/

#define	RCC_PLL_HSE    1
#define	RCC_PLL_HSI	   0


/*PLLM : Division Factor for the main PLL*/
# define	RCC_PLLM_DIV_FACTOR_2                  2
# define	RCC_PLLM_DIV_FACTOR_3                  3
# define	RCC_PLLM_DIV_FACTOR_4                  4
# define	RCC_PLLM_DIV_FACTOR_5                  5
# define	RCC_PLLM_DIV_FACTOR_6                  6
# define	RCC_PLLM_DIV_FACTOR_7                  7
# define	RCC_PLLM_DIV_FACTOR_8                  8
# define	RCC_PLLM_DIV_FACTOR_9                  9
# define	RCC_PLLM_DIV_FACTOR_10                 10
# define	RCC_PLLM_DIV_FACTOR_11                 11
# define	RCC_PLLM_DIV_FACTOR_12                 22
# define	RCC_PLLM_DIV_FACTOR_13                 13
# define	RCC_PLLM_DIV_FACTOR_14                 14
# define	RCC_PLLM_DIV_FACTOR_15                 15
# define	RCC_PLLM_DIV_FACTOR_16                 16
# define	RCC_PLLM_DIV_FACTOR_17                 17
# define	RCC_PLLM_DIV_FACTOR_18                 18
# define	RCC_PLLM_DIV_FACTOR_19                 19
# define	RCC_PLLM_DIV_FACTOR_20                 20
# define	RCC_PLLM_DIV_FACTOR_21                 21
# define	RCC_PLLM_DIV_FACTOR_22                 22
# define	RCC_PLLM_DIV_FACTOR_23                 23
# define	RCC_PLLM_DIV_FACTOR_24                 24
# define	RCC_PLLM_DIV_FACTOR_25                 25
# define	RCC_PLLM_DIV_FACTOR_26                 26
# define	RCC_PLLM_DIV_FACTOR_27                 27
# define	RCC_PLLM_DIV_FACTOR_28                 28
# define	RCC_PLLM_DIV_FACTOR_29                 29
# define	RCC_PLLM_DIV_FACTOR_30                 30
# define	RCC_PLLM_DIV_FACTOR_31                 31
# define	RCC_PLLM_DIV_FACTOR_32                 32
# define	RCC_PLLM_DIV_FACTOR_33                 33
# define	RCC_PLLM_DIV_FACTOR_34                 34
# define	RCC_PLLM_DIV_FACTOR_35                 35
# define	RCC_PLLM_DIV_FACTOR_36                 36
# define	RCC_PLLM_DIV_FACTOR_37                 37
# define	RCC_PLLM_DIV_FACTOR_38                 38
# define	RCC_PLLM_DIV_FACTOR_39                 39
# define	RCC_PLLM_DIV_FACTOR_40                 40
# define	RCC_PLLM_DIV_FACTOR_41                 41
# define	RCC_PLLM_DIV_FACTOR_42                 42
# define	RCC_PLLM_DIV_FACTOR_43                 43
# define	RCC_PLLM_DIV_FACTOR_44                 44
# define	RCC_PLLM_DIV_FACTOR_45                 45
# define	RCC_PLLM_DIV_FACTOR_46                 46
# define	RCC_PLLM_DIV_FACTOR_47                 47
# define	RCC_PLLM_DIV_FACTOR_48                 48
# define	RCC_PLLM_DIV_FACTOR_49                 49
# define	RCC_PLLM_DIV_FACTOR_50                 50
# define	RCC_PLLM_DIV_FACTOR_51                 51
# define	RCC_PLLM_DIV_FACTOR_52                 52
# define	RCC_PLLM_DIV_FACTOR_53                 53
# define	RCC_PLLM_DIV_FACTOR_54                 54
# define	RCC_PLLM_DIV_FACTOR_55                 55
# define	RCC_PLLM_DIV_FACTOR_56                 56
# define	RCC_PLLM_DIV_FACTOR_57                 57
# define	RCC_PLLM_DIV_FACTOR_58                 58
# define	RCC_PLLM_DIV_FACTOR_59                 59
# define	RCC_PLLM_DIV_FACTOR_60                 60
# define	RCC_PLLM_DIV_FACTOR_61                 61
# define	RCC_PLLM_DIV_FACTOR_62                 62
# define	RCC_PLLM_DIV_FACTOR_63                 63

/*HPRE : AHB clock division factor*/
#define	RCC_HPRE_AHB_SYS_CLK_DIV_BY_1                                      0
#define	RCC_HPRE_AHB_SYS_CLK_DIV_BY_2                                      0b1000
#define	RCC_HPRE_AHB_SYS_CLK_DIV_BY_4                                      0b1001
#define	RCC_HPRE_AHB_SYS_CLK_DIV_BY_8                                      0b1010
#define	RCC_HPRE_AHB_SYS_CLK_DIV_BY_16                                     0b1011
#define	RCC_HPRE_AHB_SYS_CLK_DIV_BY_64                                     0b1100
#define	RCC_HPRE_AHB_SYS_CLK_DIV_BY_128                                    0b1101
#define	RCC_HPRE_AHB_SYS_CLK_DIV_BY_256                                    0b1110
#define	RCC_HPRE_AHB_SYS_CLK_DIV_BY_512                                    0b1111

/*PPRE1 : APB Low Speed Prescaler(APB1)*/
#define	RCC_PPRE1_AHB_SYS_CLK_DIV_BY_1                                     0
#define	RCC_PPRE1_AHB_SYS_CLK_DIV_BY_2                                     0b100
#define	RCC_PPRE1_AHB_SYS_CLK_DIV_BY_4                                     0b101
#define	RCC_PPRE1_AHB_SYS_CLK_DIV_BY_8                                     0b110
#define	RCC_PPRE1_AHB_SYS_CLK_DIV_BY_16                                    0b111

/*PPRE2 : APB High Speed Prescaler(APB1)*/
#define	RCC_PPRE2_AHB_SYS_CLK_DIV_BY_1                                     0
#define	RCC_PPRE2_AHB_SYS_CLK_DIV_BY_2                                     0b100
#define	RCC_PPRE2_AHB_SYS_CLK_DIV_BY_4                                     0b101
#define	RCC_PPRE2_AHB_SYS_CLK_DIV_BY_8                                     0b110
#define	RCC_PPRE2_AHB_SYS_CLK_DIV_BY_16                                    0b111

/***********  Bit definition for(RCC_AHB1ENR)register  ********/
#define OTGHSULPIEN  	30
#define OTGHSEN      	29
#define ETHMACPTPEN  	28
#define ETHMACRXEN   	27
#define ETHMACTXEN   	26
#define ETHMACEN	 	25 	
#define DMA2EN		 	22
#define DMA1EN       	21
#define BKPSRAMEN	 	20
#define CCMDATARAMEN 	18 
#define CRCEN		 	12
#define GPIOIEN		 	8
#define GPIOHEN      	4
#define GPIOGEN      	6
#define GPIOFEN      	5
#define GPIOEEN      	4
#define GPIODEN      	3
#define GPIOCEN      	2
#define GPIOBEN      	1
#define GPIOAEN      	0

/***********  Bit definition for(RCC_AHB2ENR)register  ********/

#define DCMIEN			0
#define CRYPEN          1
#define HASHEN          2
#define RNGEN           3
#define OTGFSEN         4

/***********  Bit definition for(RCC_APB1ENR)register  ********/

#define	DACEN			 29
#define	PWREN            28
#define	CAN2EN           26
#define	CAN1EN           25
#define	I2C3EN           23
#define	I2C2EN           22
#define	I2C1EN           21
#define	UART5EN          20
#define	UART4EN          19
#define	USART3EN         18
#define	USART2EN         17
#define	SPI3EN           15
#define	SPI2EN           14
#define	WWDGEN           11
#define	TIM14EN          8
#define	TIM13EN          7
#define	TIM12EN          6
#define	TIM7EN           5
#define	TIM6EN           4
#define	TIM5EN           3
#define	TIM4EN           2
#define	TIM3EN           1
#define	TIM2EN           0


/***********  Bit definition for(RCC_APB2ENR)register  ********/

#define	TIM11EN			 18
#define	TIM10EN          17
#define	TIM9EN           16
#define	SYSCFGEN         14
#define	SPI1EN           12
#define	SDIOEN           11
#define	ADC3EN           10
#define	ADC2EN           9
#define	ADC1EN           8
#define	USART6EN         5
#define	USART1EN         4
#define	TIM8EN           1
#define	TIM1EN           0


/*********AHB prescaler*****/
#define AHP_CLK_DIV0	10
#define AHP_CLK_DIV2	11
#define AHP_CLK_DIV4	12
#define AHP_CLK_DIV8	13
#define AHP_CLK_DIV16	14
#define AHP_CLK_DIV64	15
#define AHP_CLK_DIV128	16
#define AHP_CLK_DIV256	17
#define AHP_CLK_DIV512	18


/*********APB prescaler*****/
#define APB_CLK_DIV0	5
#define APB_CLK_DIV2	6
#define APB_CLK_DIV4	7
#define APB_CLK_DIV8	8
#define APB_CLK_DIV16	9
/*************** (PLL)division factor for main system clock********/



/*************Functions Prototypes*******************/

/****************************************************************************************
*	FunctionName: RCC_VoidInitSystemClock                     			  
*
*	Argument    : 1-ClkSrc : variables of enum ClKSrc_t that holds clock source
*
*	Return      : void	                                      			  
*
*	Description : The Function that Set the System Clock Source and pll source 
*
******************************************************************************************/
void RCC_VoidInitSystemClock(ClKSrc_t ClkSrc);


/**************************************************************
*	FunctionName: RCC_VoidEnablePeriClock                     *
*	Argument    : u8 Copy_U8BusId , u8 Copy_U8PeriId          *
*	Return      : void	                                      *
*	Description : This function is enable peripheral clock    *
*															  *
**************************************************************/
void RCC_VoidEnablePeriClock(u8 Copy_U8BusId , u8 Copy_U8PeriId);

/**************************************************************
*	FunctionName: RCC_VoidDisablePeriClock                    *
*	Argument    : u8 Copy_U8BusId , u8 Copy_U8PeriId          *
*	Return      : void	                                      *
*	Description : This function is Disable peripheral clock   *
*															  *
**************************************************************/
void RCC_VoidDisablePeriClock(u8 Copy_U8BusId , u8 Copy_U8PeriId);

/**************************************************************
*	FunctionName: RCC_VoidEnablePeriClockLowMode              *
*	Argument    : u8 Copy_U8BusId , u8 Copy_U8PeriId          *
*	Return      : void	                                      *
*	Description : This function is enable peripheral clock    *
*				   in LOW mode register						  *
**************************************************************/

void RCC_VoidEnablePeriClockLowMode(u8 Copy_U8BusId , u8 Copy_U8PeriId);

/**************************************************************
*	FunctionName: RCC_VoidDisablePeriClockLowMode             *
*	Argument    : u8 Copy_U8BusId , u8 Copy_U8PeriId          *
*	Return      : void	                                      *
*	Description : This function is Disable peripheral clock   *
*				   in LOW mode register						  *
**************************************************************/
void RCC_VoidDisablePeriClockLowMode(u8 Copy_U8BusId , u8 Copy_U8PeriId);

/***************************************************************************************************
* Function Name:  RCC_u8PLLConfig
*
* Description:	The Function that Configure PLL Clock
*
* Parameters: 1- PllConfig: const pointer to PllConfig_t structure which holds the configurations
*
* Return:	Void
****************************************************************************************************
*	 please ensure that:
*	 1-PLLM = 2 ≤PLLM≤63
*	 2-PLLN = 50 ≤PLLN ≤432
*	 3-PLLP = 2, 4, 6, or 8
*	 4-PLLQ = 2 ≤PLLQ ≤15
*
********************************************************************************************************/
void RCC_u8PLLConfig (const PllConfig_t* PllConfig);

/*********************************************************************************
 * Function Name:  RCC_u8BusesPrescaler
 *
 * Description:	The Function that Configure Buses Prescaler (AHB,APB1,APB2)
 *
 * Parameters: 1- Copy_U8BusId : variable that hold Bus Number 
 *             2- Copy_U8prescaler: variable that hold Bus prescaler(AHB,APB1,APB2)
 *
 * Return:	void
 *
 ********************************************************************************/
void RCC_u8BusesPrescaler(u8 Copy_U8BusId, u8 Copy_U8prescaler)

#endif


