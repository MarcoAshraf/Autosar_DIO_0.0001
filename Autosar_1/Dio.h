/*
 * Dio.h
 *
 *  Created on: Oct 7, 2023
 *      Author: Marco Ashraf
 */

#ifndef DIO_H_
#define DIO_H_



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define STD_LOW 0U
#define STD_HIGH 1U

#define NUMBER_OF_PORTS 8
#define NUMBER_OF_PINS 8
#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3
#define PORTE   4
#define PORTF   5


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef uint8 Dio_ChannelType;    /*0-47*/
typedef uint8 Dio_PortType;       /*0-7*/
typedef uint8 Dio_LevelType;      /*0/1*/
typedef uint8 Dio_PortLevelType;  /*<8*/


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description:  Returns the value of the specified DIO channel. *
 * Parameters: None
 * Returns: Dio_Level-Type STD_HIGH The physical level of the corresponding Pin is STD_HIGH
 *                         STD_LOW The physical level of the corresponding Pin is STD_LOW
 */
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);

/*
 * Description: Srvice to set a level of a channel.
 *
 * Parameters(In): ChannelId : ID of DIO channel
 *                 Level : Value to be written
 * Returns: None
 */
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);

/*
 * Description: Returns the level of all channels of that port.
 * Parameters(In): PortId : ID of DIO Port
 * Returns: Dio_PortLevelType : Level of all channels of that port
 */
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);

/*
 * Description: Service to set a value of the port.
 * Parameters(In): PortId : ID of DIO Port
 *                 Level : Value to be written
 * Returns: None
 */
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);



#endif /* DIO_H_ */
