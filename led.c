/*
 * led.c
 *
 *  Created on: Jun 18, 2014
 *      Author: Administrator
 */

#include "cc253x.h"
#include "compiler.h"

void config_led(void) {
	P1SEL = P1SEL & 0xFE;
	P1DIR = P1DIR | 0x01;//P1SEL selects function P1DIR selects I/O

	P1SEL = P1SEL & 0xFD;
	P1DIR = P1DIR | 0x02;

	P1SEL = P1SEL & 0xEF;
	P1DIR = P1DIR | 0x10;
}
