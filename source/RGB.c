/*
 * LED.c
 *
 *  Created on: Sep 4, 2018
 *      Author: Resh
 */
#include "RGB.h"

void sws(){
	GPIOC->PDDR&= ~(0x40);
	GPIOA->PDDR&= ~(0x10);
}

void sw2(){
	GPIOC->PDDR&= ~(0x40);
}

void sw3(){
	GPIOA->PDDR&= ~(0x10);
}


//mi delay de 65000
void delay(uint16 delay){
	volatile int counter, counter2; /** contadores para lograr el delay */

	for(counter2=16; counter2 > 0; counter2--){ /** se recorre el contador desde el valor maximo hasta 0 */
		for(counter=delay; counter > 0; counter--);

	}
}

void yellow(){
	GPIOB->PDOR = ~(RED); //Red led on
	GPIOE->PDOR = ~(GREEN); // Green led on
}


void red(){
	GPIOB->PDOR = ~(RED);//Red led on
	GPIOE->PDOR = ~(GREEN); // Green led off
}

void purple(){
	GPIOB->PDOR = ~(RED+BLUE); //Sumo el azul y el rojo para obtener morado
}

void blue(){
	GPIOB->PDOR = ~(BLUE); // solo el led azul
	GPIOE->PDOR = ~(0x0);//apago el verde
}

void green(){
	GPIOB->PDOR = ~(0x0);//apago los del puerto b
	GPIOE->PDOR = ~(GREEN); //enciendo solo el verde
}

void white(){
	GPIOB->PDOR = ~(RED+BLUE); //prendo todos los colores RGB
	GPIOE->PDOR = ~(GREEN);
}

void noColor(){
	GPIOB->PDOR = ~(0x0);/** no se le asigna color al LED */
	GPIOE->PDOR = ~(0x0);
}
