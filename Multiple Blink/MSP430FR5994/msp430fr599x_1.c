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

    P1OUT &= ~BIT1;                         // Clear P1.1 output latch for a defined power-on state
    P1DIR |= BIT1;                          // Set P1.1 to output direction

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

	while (1)
	{
		volatile unsigned int j;
		
			P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
		__delay_cycles(10000);             // Delay for 10000*(1/MCLK)=0.01s
		j++;								//increment j
		if (j % 6 == 0) {					//if j is divisible by 6, toggle 1.1
			P1OUT ^= BIT1;                      // Toggle P1.1 using exclusive-OR
		}
	}
}

