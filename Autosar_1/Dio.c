/*
 * Dio.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Marco Ashraf
 */

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include <imp_dataTypes.h>
#include "Dio.h"
#include "tm4c123gh6pm.h"

/*#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )*/


/*
 * Description:  Returns the value of the specified DIO channel. *
 * Parameters: None
 * Returns: Dio_Level-Type STD_HIGH The physical level of the corresponding Pin is STD_HIGH
 *                         STD_LOW The physical level of the corresponding Pin is STD_LOW
 */
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    uint8 temp = ChannelId / NUMBER_OF_PORTS;
    Dio_LevelType res = STD_HIGH;
    switch(temp)
    {
    case PORTA:
        temp %= NUMBER_OF_PINS;
        if( (GPIO_PORTA_DATA_R &  (1U<<temp)) >> temp)
        {
            res = STD_HIGH;
        }
        else
        {
            res = STD_LOW;
        }
        break;

    case PORTB:
        temp %= NUMBER_OF_PINS;
        if( (GPIO_PORTB_DATA_R &  (1U<<temp)) >> temp)
        {
            res = STD_HIGH;
        }
        else
        {
            res = STD_LOW;
        }
        break;

    case PORTC:
        temp %= NUMBER_OF_PINS;
        if( (GPIO_PORTC_DATA_R &  (1U<<temp)) >> temp)
        {
            res = STD_HIGH;
        }
        else
        {
            res = STD_LOW;
        }
        break;

    case PORTD:
        temp %= NUMBER_OF_PINS;
        if( (GPIO_PORTD_DATA_R &  (1U<<temp)) >> temp)
        {
            res = STD_HIGH;
        }
        else
        {
            res = STD_LOW;
        }
        break;

    case PORTE:
        temp %= NUMBER_OF_PINS;
        if( (GPIO_PORTE_DATA_R &  (1U<<temp)) >> temp)
        {
            res = STD_HIGH;
        }
        else
        {
            res = STD_LOW;
        }
        break;

    case PORTF:
        temp %= NUMBER_OF_PINS;
        if( (GPIO_PORTF_DATA_R &  (1U<<temp)) >> temp)
        {
            res = STD_HIGH;
        }
        else
        {
            res = STD_LOW;
        }        break;

    default:
        while(1); /*ERROR*/
        break;
    }

    return res;

}


/*
 * Description: Srvice to set a level of a channel.
 *
 * Parameters(In): ChannelId : ID of DIO channel
 *                 Level : Value to be written
 * Returns: None
 */
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8 temp = ChannelId / NUMBER_OF_PORTS;
    if(Level != STD_LOW && Level != STD_HIGH)
    {
        while(1); /*ERROR*/
    }
    else
    {
        switch(temp)
        {
        case PORTA:
            temp %= NUMBER_OF_PINS;
            GPIO_PORTA_DATA_R |= 1U<<Level;
            break;

        case PORTB:
            temp %= NUMBER_OF_PINS;
            GPIO_PORTB_DATA_R |= 1U<<Level;

            break;

        case PORTC:
            temp %= NUMBER_OF_PINS;
            GPIO_PORTC_DATA_R |= 1U<<Level;

            break;

        case PORTD:
            temp %= NUMBER_OF_PINS;
            GPIO_PORTD_DATA_R |= 1U<<Level;

            break;

        case PORTE:
            temp %= NUMBER_OF_PINS;
            GPIO_PORTE_DATA_R |= 1U<<Level;

            break;

        case PORTF:
            temp %= NUMBER_OF_PINS;
            GPIO_PORTF_DATA_R |= 1U<<Level;
            break;

        default:
            while(1); /*ERROR*/
            break;
        }
    }

}


/*
 * Description: Returns the level of all channels of that port.
 * Parameters(In): PortId : ID of DIO Port
 * Returns: Dio_PortLevelType : Level of all channels of that port
 */
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    Dio_PortLevelType res;
    switch (PortId)
    {
    case PORTA:
        res = (uint8)GPIO_PORTA_DATA_R;
        break;

    case PORTB:
        res = (uint8)GPIO_PORTB_DATA_R;
        break;

    case PORTC:
        res = (uint8)GPIO_PORTC_DATA_R;
        break;

    case PORTD:
        res = (uint8)GPIO_PORTD_DATA_R;
        break;

    case PORTE:
        res = (uint8)GPIO_PORTE_DATA_R;
        break;

    case PORTF:
        res = (uint8)GPIO_PORTF_DATA_R;
        break;

    default:
        while(1); /*ERROR*/
        break;
    }
    return res;
}


/*
 * Description: Service to set a value of the port.
 * Parameters(In): PortId : ID of DIO Port
 *                 Level : Value to be written
 * Returns: None
 */
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
    if(Level > NUMBER_OF_PINS)
    {
        while(1); /*ERROR*/
    }
    else
    {
        switch (PortId)
        {
        case PORTA:
            GPIO_PORTA_DATA_R = Level;
            break;

        case PORTB:
            GPIO_PORTB_DATA_R = Level;
            break;

        case PORTC:
            GPIO_PORTC_DATA_R = Level;
            break;

        case PORTD:
            GPIO_PORTD_DATA_R = Level;
            break;

        case PORTE:
            GPIO_PORTE_DATA_R = Level;
            break;

        case PORTF:
            GPIO_PORTF_DATA_R = Level;
            break;

        default:
            while(1); /*ERROR*/
            break;
        }
    }

}



