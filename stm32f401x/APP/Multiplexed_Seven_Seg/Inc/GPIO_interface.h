/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: GPIO           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*************************************************************************************************/
#define  GPIO_u8PORTA    0
#define  GPIO_u8PORTB    1
#define  GPIO_u8PORTC    2


/*Note: PORTA doesn't have pin 13,14 and PORTC has only 13,14,15 pins*/
#define  GPIO_u8PIN0     0
#define  GPIO_u8PIN1     1
#define  GPIO_u8PIN2     2
#define  GPIO_u8PIN3     3
#define  GPIO_u8PIN4     4
#define  GPIO_u8PIN5     5
#define  GPIO_u8PIN6     6
#define  GPIO_u8PIN7     7
#define  GPIO_u8PIN8     8
#define  GPIO_u8PIN9     9
#define  GPIO_u8PIN10    10
#define  GPIO_u8PIN11    11
#define  GPIO_u8PIN12    12
#define  GPIO_u8PIN13    13
#define  GPIO_u8PIN14    14
#define  GPIO_u8PIN15    15



#define  GPIO_u8PIN_HIGH    1
#define  GPIO_u8PIN_LOW     0


#define  GPIO_u16PORT_HIGH      0XFFFF
#define  GPIO_u16PORT_LOW        0


/**********************************************************************************************************/



u8  GPIO_u8WritePortValue(u8 Copy_u8Port, u16 Copy_u8Value);

u8  GPIO_u8ReadPortValue(u8 Copy_u8Port, u16* Copy_u8PTRvalue);

u8  GPIO_u8WritePinValue(u8 Copy_u8Pin, u8 Copy_u8Port, u8 Copy_u8Value);

u8  GPIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8PTRvalue);

u8 GPIO_u8SetGroupChannel(u8 Copy_u8Port,u8 Copy_u8StartPin,u8 Copy_u8ChannelWidth,u16 Copy_u8Value);

#endif



