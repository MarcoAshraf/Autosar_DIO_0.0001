/*
 * Port.h
 *
 *  Created on: Oct 7, 2023
 *      Author: Marco Ashraf
 */

#ifndef PORT_H_
#define PORT_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUMBER_OF_PORTS 8
#define NUMBER_OF_PINS 8
#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3
#define PORTE   4
#define PORTF   5

#define PULL_DOWN 0
#define PULL_UP 1
#define HIGH    1
#define LOW     0

#define UNLOCK 0x4C4F434B


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef uint8 Port_PintType;

typedef enum
{
    PORT_PIN_IN = 0,
    PORT_PIN_OUT

}Port_PinDirectionType;

typedef uint8 Port_PinModeType;

typedef struct
{
    uint8 PORT;
    Port_PinDirectionType PinDirection[NUMBER_OF_PINS];
    uint8 Latch;
    uint8 OutputLevel;

}Port_ConfigType;



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description: Initializes the Port Driver module.
 *
 * Parameters(In): ConfigPtr Pointer to configuration set.
 *
 * Returns: None
 */
void Port_Init (const Port_ConfigType* ConfigPtr);
#endif /* PORT_H_ */
