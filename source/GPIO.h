/*
 * GPIO.h
 *
 *  Created on: Sep 4, 2018
 *      Author: Resh
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "DataTypeDefinitions.h"

/** Selects a pullup resistor */
#define GPIO_PS    0x00000001
/** Enables the pulldown or pullup resistors*/
#define GPIO_PE    0x00000002
/** Selects alternative function 1 (GPIO) */
#define GPIO_MUX1  0x00000100
typedef const uint32 GPIO_pinControlRegisterType;

#define GPIO_CLOCK_GATING_PORTA  0x200;
#define GPIO_CLOCK_GATING_PORTB  0x400;
#define GPIO_CLOCK_GATING_PORTC  0x800;
#define GPIO_CLOCK_GATING_PORTD  0x1000;
#define GPIO_CLOCK_GATING_PORTE  0x2000;


typedef struct
{
	uint8 flagPortA : 1;
	uint8 flagPortB : 1;
	uint8 flagPortC : 1;
	uint8 flagPortD : 1;
	uint8 flagPortE : 1;
} GPIO_interruptFlags_t;

/*! This definition is used to configure whether a pin is an input or an output*/
typedef enum {GPIO_INPUT,/*!< Definition to configure a pin as input */
			  GPIO_OUTPUT /*!< Definition to configure a pin as output */
			 }GPIO_PIN_CONFIG;
/*! These constants are used to select an specific port in the different API functions*/
typedef enum{GPIO_A, /*!< Definition to select GPIO A */
			 GPIO_B, /*!< Definition to select GPIO B */
			 GPIO_C, /*!< Definition to select GPIO C */
			 GPIO_D, /*!< Definition to select GPIO D */
			 GPIO_E, /*!< Definition to select GPIO E */
			 GPIO_F  /*!< Definition to select GPIO F */
			} GPIO_portNameType;

/*! This data type is used to configure the pin control register*/
typedef const uint32 GPIO_pinControlRegisterType;
uint8 GPIO_clockGating(GPIO_portNameType portName);
uint8 GPIO_pinControlRegister(GPIO_portNameType portName,uint8 pin,GPIO_pinControlRegisterType* pinControlRegister);
void GPIO_dataDirectionPORT(GPIO_portNameType portName, uint32 direction);
void GPIO_dataDirectionPIN(GPIO_portNameType portName, uint8 state, uint8 pin);


#endif /* GPIO_H_ */
