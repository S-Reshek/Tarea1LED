/*
 * Copyright (c) 2016, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    RGDLEDSW.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "MK64F12.h"
#include "GPIO.h"
#include "RGB.h"
#include "DataTypeDefinitions.h"


int main(void) {

GPIO_clockGating(GPIO_A);
GPIO_clockGating(GPIO_B);
GPIO_clockGating(GPIO_C);
GPIO_clockGating(GPIO_E);

GPIO_pinControlRegisterType pinControlRegisterGPIO = GPIO_MUX1;
GPIO_pinControlRegisterType pinControlRegisterPS = GPIO_PS;
GPIO_pinControlRegisterType pinControlRegisterPE = GPIO_PE;


GPIO_pinControlRegister(GPIO_A,BIT4, &pinControlRegisterGPIO);
GPIO_pinControlRegister(GPIO_B,BIT21,&pinControlRegisterGPIO);
GPIO_pinControlRegister(GPIO_B,BIT22,&pinControlRegisterGPIO);
GPIO_pinControlRegister(GPIO_C,BIT6, &pinControlRegisterGPIO);
GPIO_pinControlRegister(GPIO_E,BIT26,&pinControlRegisterGPIO);

GPIO_pinControlRegister(GPIO_A,BIT4, &pinControlRegisterPS);
GPIO_pinControlRegister(GPIO_C,BIT6, &pinControlRegisterPS);

GPIO_pinControlRegister(GPIO_A,BIT4, &pinControlRegisterPE);
GPIO_pinControlRegister(GPIO_C,BIT6, &pinControlRegisterPE);

GPIO_dataDirectionPIN(GPIO_A,0x0,BIT4);
GPIO_dataDirectionPIN(GPIO_C,0x0,BIT6);
GPIO_dataDirectionPIN(GPIO_B,0x1, BIT21);
GPIO_dataDirectionPIN(GPIO_B,0x1,BIT22);
GPIO_dataDirectionPIN(GPIO_E,0x1,BIT26);

uint8 color = 0;
uint32 inputValueSW2;
uint32 inputValueSW3;

while(1){

	inputValueSW2 = GPIOC->PDIR;
	inputValueSW2 = inputValueSW2 & 0x40;
	inputValueSW3 = GPIOA->PDIR;
	inputValueSW3 = inputValueSW3 & 0x10;

	if(FALSE == inputValueSW2){
		if(color > 0){
			color --;
		}
	}


	if(FALSE == inputValueSW3){
		if(color < 4){
			color ++;
			}
		}

	switch (color){

	case 0:
		green();
		break;
	case 1:
		blue();
		break;
	case 2:
		purple();
		break;
	case 3:
		red();
		break;
	case 4:
		yellow();
		break;
	case 5:
		white();
		break;
	default:
		break;

	}

}
return 0;
}
