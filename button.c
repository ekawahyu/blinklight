/*
 * button.c
 *
 *  Created on: Jun 19, 2014
 *      Author: Administrator
 */

#include "cc253x.h"
#include "compiler.h"

void config_button(void) {
	P0SEL = P0SEL & 0xFE;
	P0DIR = P0DIR & 0xFD;
}

