/*
 * Port.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Marco Ashraf
 */
/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include <imp_dataTypes.h>
#include "Port.h"
#include "tm4c123gh6pm.h"




/*
 * Description: Initializes the Port Driver module.
 *
 * Parameters(In): ConfigPtr Pointer to configuration set.
 *
 * Returns: None
 */
void Port_Init (const Port_ConfigType* ConfigPtr)
{
    if(ConfigPtr == 0)
    {
        while(1); /*ERROR*/
    }
    else
    {
        switch(ConfigPtr->PORT)
        {
        case PORTA:
            GPIO_PORTA_LOCK_R = UNLOCK;
            GPIO_PORTA_CR_R = NUMBER_OF_PINS;
            for(uint8 pin=0; pin<NUMBER_OF_PINS; pin++)
            {
                if(ConfigPtr->PinDirection[pin] == PORT_PIN_IN)
                {
                    GPIO_PORTA_DIR_R |= (1U<<pin);
                    if((ConfigPtr->Latch & ~(1U<<pin))>>pin == PULL_UP)
                    {
                        GPIO_PORTA_PUR_R |= (1U<<pin);
                    }
                    else if((ConfigPtr->Latch & ~(1U<<pin))>>pin == PULL_DOWN)
                    {
                        GPIO_PORTA_PDR_R |= (1U<<pin);
                    }
                    else
                    {
                        while(1); /*ERROR*/
                    }
                }
                else if(ConfigPtr->PinDirection[pin] == PORT_PIN_OUT)
                {
                    GPIO_PORTA_DIR_R &= ~(1U<<pin);
                    if(ConfigPtr->PinDirection[pin] == PORT_PIN_IN)
                    {
                        GPIO_PORTA_DIR_R |= (1U<<pin);
                        if((ConfigPtr->OutputLevel & ~(1U<<pin))>>pin == HIGH)
                        {
                            GPIO_PORTA_DATA_R |= (1U<<pin);
                        }
                        else if((ConfigPtr->OutputLevel & ~(1U<<pin))>>pin == LOW)
                        {
                            GPIO_PORTA_DATA_R &= ~(1U<<pin);
                        }
                        else
                        {
                            while(1); /*ERROR*/
                        }
                    }
                    else
                    {
                        while(1); /*ERROR*/
                    }

                }
            }
            GPIO_PORTA_DEN_R = NUMBER_OF_PINS;
            break;

        case PORTB:
            GPIO_PORTB_LOCK_R = UNLOCK;
            GPIO_PORTB_CR_R = NUMBER_OF_PINS;
            for(uint8 pin=0; pin<NUMBER_OF_PINS; pin++)
            {
                if(ConfigPtr->PinDirection[pin] == PORT_PIN_IN)
                {
                    GPIO_PORTB_DIR_R |= (1U<<pin);
                    if((ConfigPtr->Latch & ~(1U<<pin))>>pin == PULL_UP)
                    {
                        GPIO_PORTB_PUR_R |= (1U<<pin);
                    }
                    else if((ConfigPtr->Latch & ~(1U<<pin))>>pin == PULL_DOWN)
                    {
                        GPIO_PORTB_PDR_R |= (1U<<pin);
                    }
                    else
                    {
                        while(1); /*ERROR*/
                    }
                }
                else if(ConfigPtr->PinDirection[pin] == PORT_PIN_OUT)
                {
                    GPIO_PORTB_DIR_R &= ~(1U<<pin);
                    if(ConfigPtr->PinDirection[pin] == PORT_PIN_IN)
                    {
                        GPIO_PORTB_DIR_R |= (1U<<pin);
                        if((ConfigPtr->OutputLevel & ~(1U<<pin))>>pin == HIGH)
                        {
                            GPIO_PORTB_DATA_R |= (1U<<pin);
                        }
                        else if((ConfigPtr->OutputLevel & ~(1U<<pin))>>pin == LOW)
                        {
                            GPIO_PORTB_DATA_R &= ~(1U<<pin);
                        }
                        else
                        {
                            while(1); /*ERROR*/
                        }
                    }
                    else
                    {
                        while(1); /*ERROR*/
                    }

                }
            }
            GPIO_PORTB_DEN_R = NUMBER_OF_PINS;
            break;

        case PORTC:
            GPIO_PORTC_LOCK_R = UNLOCK;
            GPIO_PORTC_CR_R = NUMBER_OF_PINS;
            for(uint8 pin=0; pin<NUMBER_OF_PINS; pin++)
            {
                if(ConfigPtr->PinDirection[pin] == PORT_PIN_IN)
                {
                    GPIO_PORTC_DIR_R |= (1U<<pin);
                    if((ConfigPtr->Latch & ~(1U<<pin))>>pin == PULL_UP)
                    {
                        GPIO_PORTC_PUR_R |= (1U<<pin);
                    }
                    else if((ConfigPtr->Latch & ~(1U<<pin))>>pin == PULL_DOWN)
                    {
                        GPIO_PORTC_PDR_R |= (1U<<pin);
                    }
                    else
                    {
                        while(1); /*ERROR*/
                    }
                }
                else if(ConfigPtr->PinDirection[pin] == PORT_PIN_OUT)
                {
                    GPIO_PORTC_DIR_R &= ~(1U<<pin);
                    if(ConfigPtr->PinDirection[pin] == PORT_PIN_IN)
                    {
                        GPIO_PORTC_DIR_R |= (1U<<pin);
                        if((ConfigPtr->OutputLevel & ~(1U<<pin))>>pin == HIGH)
                        {
                            GPIO_PORTC_DATA_R |= (1U<<pin);
                        }
                        else if((ConfigPtr->OutputLevel & ~(1U<<pin))>>pin == LOW)
                        {
                            GPIO_PORTC_DATA_R &= ~(1U<<pin);
                        }
                        else
                        {
                            while(1); /*ERROR*/
                        }
                    }
                    else
                    {
                        while(1); /*ERROR*/
                    }

                }
            }
            GPIO_PORTC_DEN_R = NUMBER_OF_PINS;
            break;

        case PORTD:
            GPIO_PORTD_LOCK_R = UNLOCK;
            GPIO_PORTD_CR_R = NUMBER_OF_PINS;
            for(uint8 pin=0; pin<NUMBER_OF_PINS; pin++)
            {
                if(ConfigPtr->PinDirection[pin] == PORT_PIN_IN)
                {
                    GPIO_PORTD_DIR_R |= (1U<<pin);
                    if((ConfigPtr->Latch & ~(1U<<pin))>>pin == PULL_UP)
                    {
                        GPIO_PORTD_PUR_R |= (1U<<pin);
                    }
                    else if((ConfigPtr->Latch & ~(1U<<pin))>>pin == PULL_DOWN)
                    {
                        GPIO_PORTD_PDR_R |= (1U<<pin);
                    }
                    else
                    {
                        while(1); /*ERROR*/
                    }
                }
                else if(ConfigPtr->PinDirection[pin] == PORT_PIN_OUT)
                {
                    GPIO_PORTD_DIR_R &= ~(1U<<pin);
                    if(ConfigPtr->PinDirection[pin] == PORT_PIN_IN)
                    {
                        GPIO_PORTD_DIR_R |= (1U<<pin);
                        if((ConfigPtr->OutputLevel & ~(1U<<pin))>>pin == HIGH)
                        {
                            GPIO_PORTD_DATA_R |= (1U<<pin);
                        }
                        else if((ConfigPtr->OutputLevel & ~(1U<<pin))>>pin == LOW)
                        {
                            GPIO_PORTD_DATA_R &= ~(1U<<pin);
                        }
                        else
                        {
                            while(1); /*ERROR*/
                        }
                    }
                    else
                    {
                        while(1); /*ERROR*/
                    }

                }
            }
            GPIO_PORTD_DEN_R = NUMBER_OF_PINS;
            break;

        case PORTE:
            GPIO_PORTE_LOCK_R = UNLOCK;
            GPIO_PORTE_CR_R = NUMBER_OF_PINS;
            for(uint8 pin=0; pin<NUMBER_OF_PINS; pin++)
            {
                if(ConfigPtr->PinDirection[pin] == PORT_PIN_IN)
                {
                    GPIO_PORTE_DIR_R |= (1U<<pin);
                    if((ConfigPtr->Latch & ~(1U<<pin))>>pin == PULL_UP)
                    {
                        GPIO_PORTE_PUR_R |= (1U<<pin);
                    }
                    else if((ConfigPtr->Latch & ~(1U<<pin))>>pin == PULL_DOWN)
                    {
                        GPIO_PORTE_PDR_R |= (1U<<pin);
                    }
                    else
                    {
                        while(1); /*ERROR*/
                    }
                }
                else if(ConfigPtr->PinDirection[pin] == PORT_PIN_OUT)
                {
                    GPIO_PORTE_DIR_R &= ~(1U<<pin);
                    if(ConfigPtr->PinDirection[pin] == PORT_PIN_IN)
                    {
                        GPIO_PORTE_DIR_R |= (1U<<pin);
                        if((ConfigPtr->OutputLevel & ~(1U<<pin))>>pin == HIGH)
                        {
                            GPIO_PORTE_DATA_R |= (1U<<pin);
                        }
                        else if((ConfigPtr->OutputLevel & ~(1U<<pin))>>pin == LOW)
                        {
                            GPIO_PORTE_DATA_R &= ~(1U<<pin);
                        }
                        else
                        {
                            while(1); /*ERROR*/
                        }
                    }
                    else
                    {
                        while(1); /*ERROR*/
                    }

                }
            }
            GPIO_PORTE_DEN_R = NUMBER_OF_PINS;
            break;

        case PORTF:
            GPIO_PORTF_LOCK_R = UNLOCK;
            GPIO_PORTF_CR_R = NUMBER_OF_PINS;
            for(uint8 pin=0; pin<NUMBER_OF_PINS; pin++)
            {
                if(ConfigPtr->PinDirection[pin] == PORT_PIN_IN)
                {
                    GPIO_PORTF_DIR_R |= (1U<<pin);
                    if((ConfigPtr->Latch & ~(1U<<pin))>>pin == PULL_UP)
                    {
                        GPIO_PORTF_PUR_R |= (1U<<pin);
                    }
                    else if((ConfigPtr->Latch & ~(1U<<pin))>>pin == PULL_DOWN)
                    {
                        GPIO_PORTF_PDR_R |= (1U<<pin);
                    }
                    else
                    {
                        while(1); /*ERROR*/
                    }
                }
                else if(ConfigPtr->PinDirection[pin] == PORT_PIN_OUT)
                {
                    GPIO_PORTF_DIR_R &= ~(1U<<pin);
                    if(ConfigPtr->PinDirection[pin] == PORT_PIN_IN)
                    {
                        GPIO_PORTF_DIR_R |= (1U<<pin);
                        if((ConfigPtr->OutputLevel & ~(1U<<pin))>>pin == HIGH)
                        {
                            GPIO_PORTF_DATA_R |= (1U<<pin);
                        }
                        else if((ConfigPtr->OutputLevel & ~(1U<<pin))>>pin == LOW)
                        {
                            GPIO_PORTF_DATA_R &= ~(1U<<pin);
                        }
                        else
                        {
                            while(1); /*ERROR*/
                        }
                    }
                    else
                    {
                        while(1); /*ERROR*/
                    }

                }
            }
            GPIO_PORTF_DEN_R = NUMBER_OF_PINS;
            break;

        default:
            while(1); /*ERROR*/
            break;

        }
    }
}


