/*
 * LED.h
 *
 *  Created on: Sep 4, 2018
 *      Author: Resh
 */

#ifndef RGB_H_
#define RGB_H_

#include "GPIO.h"
#include "DataTypeDefinitions.h"
#include "MK64F12.h"

#define RED  0x400000
#define GREEN 0x4000000
#define BLUE  0x200000


void yellow();
void red();
void purple();
void blue();
void green();
void white();
void noColor();

void delay(uint16);

void sws();
void sw2();
void sw3();


#endif /* RGB_H_ */

