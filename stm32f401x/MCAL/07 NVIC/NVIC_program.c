/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: NVIC            ***************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include"STD_TYPES.h"
#include"BIT_Manipulation.h"

#include"NVIC_interface.h"
#include"NVIC_private.h"
#include"NVIC_config.h"

static u32 GlobalStatic_32GroupConfig;

void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptPosition)
{
	
	NVIC->ISER[Copy_u8InterruptPosition / 32] = 1 << (Copy_u8InterruptPosition % 32);	
}

void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptPosition)
{
	NVIC->ICER[Copy_u8InterruptPosition / 32] = 1 << (Copy_u8InterruptPosition % 32);	
	
}

void NVIC_VoidSetPendingFlag(u8 Copy_u8InterruptPosition)
{
	NVIC->ISPR[Copy_u8InterruptPosition / 32] = 1 << (Copy_u8InterruptPosition % 32);
}

void NVIC_VoidClearPendingFlag(u8 Copy_u8InterruptPosition)
{
	NVIC->ICPR[Copy_u8InterruptPosition / 32] = 1 << (Copy_u8InterruptPosition % 32);
}

u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptPosition)
{
	u8 Local_u8ActiveState = GET_BIT((NVIC->IAPR[Copy_u8InterruptPosition / 32]), (Copy_u8InterruptPosition % 32));
    return Local_u8ActiveState;
}

void NVIC_voidSetPriorityConfig(void)
{
    GlobalStatic_32GroupConfig = 0x05FA0000 | (NVIC_PRIORITY_CONFIGURATION << 8);
    SCB->AIRCR = GlobalStatic_32GroupConfig;
}

void NVIC_VoidSetPriority(INT_PRIO_t Copy_InterruptPriority, Priority_t Copy_u8GroupPriority, Priority_t Copy_u8SubPriority)
{
	u8 Local_u8Priority = Copy_u8SubPriority | Copy_u8GroupPriority << ((GlobalStatic_32GroupConfig - 0x05FA0300) / 256);
	
	if (Copy_InterruptPriority == MEMORY_MANAGE || Copy_InterruptPriority == BUS_FAULT || Copy_InterruptPriority == USAGE_FAULT)
        {
        	
            SCB->SHPR1 = (Local_u8Priority) << ((8 * Copy_InterruptPriority) + 4);
        }
    else if (Copy_InterruptPriority == SV_CALL)
        {
        	
            SCB->SHPR2 = (Local_u8Priority) << 28;
        }
    else if (Copy_InterruptPriority == PEND_SV || Local_u8Priority == SYSTICK)
        {
        	Local_u8Priority -= 3;
            SCB->SHPR3 = (Local_u8Priority) << ((8 * Copy_s8INTID) + 4);
        }
	 else if (Copy_InterruptPriority > 6)
    {
		Copy_InterruptPriority-=6;
        NVIC->IPR[Copy_InterruptPriority] = Local_u8Priority << 4;
    }
	
	
	
}