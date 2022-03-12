/******************************************************************************************************************************
*  File 	   : RCC_program.c
*
*  Author	   : zaki ahmed
*
*  Date 	   : 16 August 2021
*
*  Description : Cortex-M4 Device Peripheral Access Layer System Source File.
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



/*!< Uncomment the line corresponding to the desired System clock (SYSCLK)
   frequency (after reset the HSI is used as SYSCLK source)
   
   IMPORTANT NOTE:
   ============== 
   1. After each device reset the HSI is used as System clock source.

   2. Please make sure that the selected System clock doesn't exceed your device's
      maximum frequency.
      
   3. If none of the define below is enabled, the HSI is used as System clock
    source.

   4. The System clock configuration functions provided within this file assume that:
        - For Low, Medium and High density Value line devices an external 8MHz 
          crystal is used to drive the System clock.
        - For Low, Medium and High density devices an external 8MHz crystal is
          used to drive the System clock.
        - For Connectivity line devices an external 25MHz crystal is used to drive
          the System clock.
     If you are using different crystal you have to adapt those functions accordingly.
	 
	 
	 *The maximum frequency for each bus will be:
		Bus       	STM32F42      
		AHB			180MHz
		APB1		45MHz
		APB2		90MHz
    */
	
	
	
/*********************** STD LIB DIRECTIVES *********************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

/*********************** Component DIRECTIVES *******************/
#include"RCC_interface.h"
#include"RCC_private.h"


/*

  * - If SYSCLK source is HSI, SystemCoreClock will contain the HSI_VALUE(*)                               
  * - If SYSCLK source is HSE, SystemCoreClock will contain the HSE_VALUE(**)               
  * - If SYSCLK source is PLL, SystemCoreClock will contain the HSE_VALUE(**) 
  *   or HSI_VALUE(*) multiplied/divided by the PLL factors.

*/
PllConfig_t PLL_confg = {RCC_PLL_HSI, 4, 2, 5};

void RCC_VoidInitSystemClock(ClKSrc_t ClkSrc)
{
	switch(ClkSrc)
	{
					
		case RCC_HSE_CRYSTAL:
			
			//Enable HSE with NO bypass
			SET_BIT(RCC->CR   , HSEON);
			//check HSE Ready flags,wait until HSE ready
			while(!(GET_BIT(RCC->CR , HSERDY)));
			//HSE selected as system clock
			SET_BIT(RCC->CFGR , SW0  );
			CLR_BIT(RCC->CFGR , SW1  );
		break;
		
		case RCC_HSE_RC:
			 /*Enable Clock Security System*/
			 SET_BIT(RCC->CR, CSSON);
			 /*Enable HSE*/
			 SET_BIT(RCC->CR , HSEON );
			 // Enable HSE With ByPass  
			 SET_BIT(RCC->CR , HSEBYP);
			 //check HSE Ready flags,wait until HSE ready
			// while(!GET_BIT(RCC->CR , HSERDY) );
			 //HSE selected as system clock
			 SET_BIT(RCC->CFGR , SW0 );
			 CLR_BIT(RCC->CFGR , SW1 );		
			
		break;
		
		case RCC_HSI:
			 // Enable HSI + Trimming = 0 
			 SET_BIT(RCC->CR   , HSION);
			 /* Bit 1 -> Checking While The HSI Clock Is Stable */
			 while(!GET_BIT(RCC->CR , HSIRDY));
			 //HSI Selected As A System Clock 
			 CLR_BIT(RCC->CFGR , SW0  );
			 CLR_BIT(RCC->CFGR , SW1  );
		break;
		
		case RCC_PLL: 
			 /*Disable PLL*/
			 CLR_BIT(RCC->CR , PLLON);
			 /*Go to PLL Configuration Function*/
			 RCC_u8PLLConfig(&PLL_confg);
			 /*PLL selected as system clock*/
			 RCC->CFGR &= ~(CFGR_MASK);
			 RCC->CFGR |= (PLL);
			 /*Enable HSE*/
			 SET_BIT(RCC->CR , HSEON);
			 /*enable HSI*/
			 SET_BIT(RCC->CR , HSION); 	
			 /*enable PLL*/
			 SET_BIT(RCC->CR , PLLON);
				 
		break;
		default: /*error*/ break;
	}
	
}


void RCC_u8PLLConfig (const PllConfig_t* PllConfig)
{
	/*Check on PLL Clock Source*/
	(RCC->PLLCFGR) &= ~((PLLSRC_MASK)<<22);
	(RCC->PLLCFGR) |= ((PllConfig->RCC_u8PLLSRC)<<22);
	
	/*Check On PLLQ : Main PPL Division Factor*/
	(RCC->PLLCFGR) &= ~((PLLQ_MASK)<<24);
	(RCC->PLLCFGR) |= ((PllConfig->RCC_u8PLLQ)<<24);
	
	/*Check On PLLP : Main PPL Division Factor for main system clock*/
	(RCC->PLLCFGR) &= ~((PLLP_MASK)<<16);
	(RCC->PLLCFGR) |= ((PllConfig->RCC_u8PLLQ)<<16);

	/*Check On PLLN : Main PPL Multiplication Factor for VCO*/
	(RCC->PLLCFGR) &= ~((PLLN_MASK)<<6);
	(RCC->PLLCFGR) |= ((PllConfig->RCC_u8PLLQ)<<6);

	/*Check On PLLM : Division Factor for the main PLL*/
	(RCC->PLLCFGR) &= ~((PLLM_MASK));
	(RCC->PLLCFGR) |= ((PllConfig->RCC_u8PLLQ));
}


void RCC_VoidEnablePeriClock(u8 Copy_U8BusId , u8 Copy_U8PeriId)
{
	if(Copy_U8PeriId < MAX_REG_BITS)
	{
		switch(Copy_U8BusId)
		{
			case RCC_AHB1 : SET_BIT(RCC->AHB1ENR , Copy_U8PeriId);	break;
			case RCC_AHB2 : SET_BIT(RCC->AHB2ENR , Copy_U8PeriId);	break;
			case RCC_AHB3 : SET_BIT(RCC->AHB3ENR , Copy_U8PeriId);	break;
			case RCC_APB1 : SET_BIT(RCC->APB1ENR , Copy_U8PeriId);	break;
			case RCC_APB2 : SET_BIT(RCC->APB2ENR , Copy_U8PeriId);	break;
			
		}
	}
	else
	{
		/* RETURN ERROR NOT HERE  */ 
	}
}


void RCC_VoidDisablePeriClock(u8 Copy_U8BusId , u8 Copy_U8PeriId)
{
		if(Copy_U8PeriId < MAX_REG_BITS)
	{
		switch(Copy_U8BusId)
		{
			case RCC_AHB1 : CLR_BIT(RCC->AHB1ENR , Copy_U8PeriId);	break;
			case RCC_AHB2 : CLR_BIT(RCC->AHB2ENR , Copy_U8PeriId);	break;
			case RCC_AHB3 : CLR_BIT(RCC->AHB3ENR , Copy_U8PeriId);	break;
			case RCC_APB1 : CLR_BIT(RCC->APB1ENR , Copy_U8PeriId);	break;
			case RCC_APB2 : CLR_BIT(RCC->APB2ENR , Copy_U8PeriId);	break;
			
		}
	}
	else
	{
		/* RETURN ERROR NOT HERE  */ 
	}
}



void RCC_VoidEnablePeriClockLowMode(u8 Copy_U8BusId , u8 Copy_U8PeriId)
{
	if(Copy_U8PeriId < MAX_REG_BITS)
	{
		switch(Copy_U8BusId)
		{
			case RCC_AHB1 : SET_BIT(RCC->AHB1LPENR , Copy_U8PeriId);	break;
			case RCC_AHB2 : SET_BIT(RCC->AHB2LPENR , Copy_U8PeriId);	break;
			case RCC_AHB3 : SET_BIT(RCC->AHB3LPENR , Copy_U8PeriId);	break;
			case RCC_APB1 : SET_BIT(RCC->APB1LPENR , Copy_U8PeriId);	break;
			case RCC_APB2 : SET_BIT(RCC->APB2LPENR , Copy_U8PeriId);	break;
			
		}
	}
	else
	{
		/* RETURN ERROR NOT HERE  */ 
	}
}


void RCC_VoidDisablePeriClockLowMode(u8 Copy_U8BusId , u8 Copy_U8PeriId)
{
	if(Copy_U8PeriId < MAX_REG_BITS)
	{
		switch(Copy_U8BusId)
		{
			case RCC_AHB1 : CLR_BIT(RCC->AHB1LPENR , Copy_U8PeriId);	break;
			case RCC_AHB2 : CLR_BIT(RCC->AHB2LPENR , Copy_U8PeriId);	break;
			case RCC_AHB3 : CLR_BIT(RCC->AHB3LPENR , Copy_U8PeriId);	break;
			case RCC_APB1 : CLR_BIT(RCC->APB1LPENR , Copy_U8PeriId);	break;
			case RCC_APB2 : CLR_BIT(RCC->APB2LPENR , Copy_U8PeriId);	break;	
		}
	}
	else
	{
		/* RETURN ERROR NOT HERE  */ 
	}
}

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
{
	switch(Copy_U8BusId)
	{
		case RCC_AHB :
			/*Check On AHB bus Prescaler*/
			 RCC->CFGR &= (HPRE_MASK<<4);
			 RCC->CFGR |= (Copy_U8prescaler<<4);
		break;

		case RCC_APB1 :
			/*Check On APB1 bus prescaler*/
			 RCC->CFGR &= (PPRE1_MASK<<10);
			 RCC->CFGR |= (Copy_U8prescaler<<10);
		break;

		case RCC_APB2 :
			/*Check On APB2 bus prescaler*/
			 RCC->CFGR &= (PPRE2_MASK<<13);
			 RCC->CFGR |= (Copy_U8prescaler<<13);
		break;
		default: /*not here*/break;

	}
}


