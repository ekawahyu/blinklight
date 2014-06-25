/*
 * blinklight.c
 *
 *  Created on: Jun 16, 2014
 *      Author: Administrator
 */

#include "cc253x.h"
#include "compiler.h"
#include "led.h"
#include "button.h"
#include "interrupt.h"

#define BLINKGREEN 1
#define BLINKRED 2
#define BLINKYELLOW 3
#define DARK 0

int state = DARK;

int delay(void) {
	volatile int i;
	i = 0;
	while (i < 30000) {
		i++;
	}
	return 0;
}

int changestate(int state) {
	if (state == DARK) {
		return BLINKGREEN;
	}
	else if (state == BLINKGREEN) {
		return BLINKRED;
	}
	else if (state == BLINKRED) {
		return BLINKYELLOW;
	}
	else if (state == BLINKYELLOW){
		return BLINKGREEN;
	}
	else {
		return -1;
	}
}

void led_isr(void) __interrupt(P0INT_VECTOR) {
	state = changestate(state);

	P0IF = 0;
	P0IFG = P0IFG & 0xFD;
}

int main(void) {//config_led(LED1)
	//int state = DARK;
	config_led();
	config_button();
	config_interrupt();

	while(1) {
		if (state == BLINKGREEN) {
		LED1 = 1;
		LED2 = 0;
		LED3 = 0;
		delay();
		LED1 = 0;
		delay();
		}
		else if (state == BLINKRED) {
	    LED1 = 0;
		LED2 = 1;
		LED3 = 0;
		delay();
		LED2 = 0;
		delay();
		}
		else if (state == BLINKYELLOW) {
		LED1 = 0;
		LED2 = 0;
		LED3 = 1;
		delay();
		LED3 = 0;
		delay();
		}
		else {
			LED1 = 0;
			LED2 = 0;
			LED3 = 0;
		}
	}
	/*while(1) {
		if (BUTTON == 1) {
			while (BUTTON == 1){};
			state = changestate(state);
			delay();
		}

		//2nd part
		if (state == BLINKGREEN) {
			LED1 = 1;
			LED2 = 0;
			LED3 = 0;
			delay();
			LED1 = 0;
			delay();
		}
		else if (state == BLINKRED) {
			LED1 = 0;
			LED2 = 1;
			LED3 = 0;
			delay();
			LED2 = 0;
			delay();
		}
		else if (state == BLINKYELLOW){
			LED1 = 0;
			LED2 = 0;
			LED3 = 1;
			delay();
			LED3 = 0;
			delay();
		}
		else {
			LED1 = 0;
			LED2 = 0;
			LED3 = 0;
			delay();
		}
	}*/

	return 0;
}


