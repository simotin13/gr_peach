#include "iodefine.h"

#define LED_PTN_RED_RED		(0x3000)
#define LED_PTN_RED_GREEN	(0x5000)
#define LED_PTN_RED_BLUE	(0x9000)

int main(void) {
	uint32_t i;

	// 54. GPIO
	// Pn  : 出力値: 0:Low 1:Hi
	// PMn : 0:Out 1:In
	// PMCn: 0: Port 1: Multiplexer

	// P6_0 SW0: In
	GPIOPM6  = 0x01;
	GPIOPMC6 = 0x00;
    while(1) {
    	GPIOP6 = LED_PTN_RED_RED;
    	for(uint32_t i = 0; i < 1000000; i++);
    	GPIOP6 = LED_PTN_RED_GREEN;
    	for(i = 0; i < 1000000; i++);
    	GPIOP6 = LED_PTN_RED_BLUE;
    	for(i = 0; i < 1000000; i++);
    }

    return 0;
}

