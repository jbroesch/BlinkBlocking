
#include <xc.h>
#include "timer.h"

volatile unsigned int timer1Count = 0;

// Interrupt handler for timer 0.
void __attribute__((__interrupt__,no_auto_psv)) _T1Interrupt(void)
{
	timer1Count++; // Increment the timer count.
	IFS0 = IFS0 & 0xFFF7;   // Clear the interrupt flag.
}

void timer1Init(unsigned int count)
{
	// Timer 1 setup.
	IPC0  = IPC0 | 0b0001000000000000;  // Priority level is 1.
	IEC0  = IEC0 | 0b0000000000001000;  // Timer1 interrupt enabled.
	PR1   = count;          			// Interrupt period.
	T1CON = 0b1000000000110000;         // Timer1 enabled, clock divider = 256.
}
