/*
 * interrupt.c
 *
 *  Created on: Jun 19, 2014
 *      Author: Administrator
 */

#include "cc253x.h"
#include "compiler.h"

void config_interrupt (void) {
	PICTL = PICTL & 0xFD;
	P0IEN = P0IEN | 0x02;
	EA = 1;

	P0IE = 1;
}
