/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: PORT           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include"STD_TYPES.h"
#include"BIT_Manipulation.h"
#include"PORT_register.h"
#include"PORT_private.h"
#include"PORT_config.h"
#include"PORT_interface.h"

void PORT_voidInit(void)
{
	
	GPIOA_MODER = GPIOA_Mode;
	GPIOB_MODER = GPIOB_Mode;
	GPIOC_MODER = GPIOC_Mode;
	
	GPIOA_OTYPER = GPIOA_Output_Type ;
	GPIOB_OTYPER = GPIOB_Output_Type ;
	GPIOC_OTYPER = GPIOC_Output_Type ;
	
	GPIOA_OSPEEDR = GPIOA_Speed;
	GPIOB_OSPEEDR = GPIOB_Speed;
	GPIOC_OSPEEDR = GPIOC_Speed;
	
	GPIOA_PUPDR = GPIOA_PUPD;
	GPIOB_PUPDR = GPIOB_PUPD;
	GPIOC_PUPDR = GPIOC_PUPD;
	

    GPIOA_AFRL= BitManipulationGetBits(GPIOA_AF, GPIOx_AFRL0, 32);
	GPIOB_AFRL= BitManipulationGetBits(GPIOB_AF, GPIOx_AFRL0, 32);
	GPIOC_AFRL= BitManipulationGetBits(GPIOC_AF, GPIOx_AFRL0, 32);
								
    GPIOA_AFRH= BitManipulationGetBits(GPIOA_AF, 32, 32);
	GPIOB_AFRH= BitManipulationGetBits(GPIOB_AF, 32, 32);
	GPIOC_AFRH= BitManipulationGetBits(GPIOC_AF, 32, 32);
	
	
	
}


