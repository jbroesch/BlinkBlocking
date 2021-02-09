/**********************************************************************
* LED flashing routine.
* © James D. Broesch, 2021
* 
* This version uses blocking calls. 
* FileName:        main.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       dsPIC33FJ256GP506
* Compiler:        MPLAB® XC
*
************************************************************************/
#include <xc.h>
#include "sask.h"
#include "timer.h"
#include "dscInit.h"

// Declare the timer count that is available in the timer driver.
extern unsigned int timer1Count;

int main(void)
{

	// Initialize the DSC.
	dscInit();

	// Initialize the board and the drivers
	SASKInit();

	// Use timer 1 as a real time clock.
	// 1 tick = 15,625 * 256 clock cycles = 100ms.
	timer1Init(15625);

        // Initialize the timer count.
        timer1Count = 0;

	while (1) //Infinite loop.
	{
		RED_LED = SASK_LED_ON; // Turn on the LED.	
		while(timer1Count < 10); // Wait one second.
		timer1Count = 0;
		RED_LED = SASK_LED_OFF; // Turn off the LED.
		while(timer1Count < 10); // Wait one second.
		timer1Count = 0;
	}
}
