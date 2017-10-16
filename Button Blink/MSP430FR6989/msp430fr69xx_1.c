//******************************************************************************
//   Ardit Pranvoku
//   Built with CCSv4 and IAR Embedded Workbench Version: 4.21
//******************************************************************************
#include <msp430.h>

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

											// Configure GPIO
	P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
	P1DIR |= BIT0;                          // Set P1.0 to output direction

	P1DIR &= ~BIT1;                         // Set P1.1 to input direction
	P1REN |= BIT1;                          // Enable resistor for P5.5

	PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
											// to activate previously configured port settings

	for (;;) {
		if (!(P1IN & BIT1))
		{
			P1OUT |= BIT0;                      // Toggle P1.0 using exclusive-OR
		}
		else {
			P1OUT &= ~BIT0;                     // Clear P1.0 using exclusive-OR
		}

	}
}
