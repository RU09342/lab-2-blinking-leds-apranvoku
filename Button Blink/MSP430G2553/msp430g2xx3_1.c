//******************************************************************************
//   Ardit Pranvoku
//   Built with CCSv4 and IAR Embedded Workbench Version: 4.21
//******************************************************************************

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= 0x01;                            // Set P1.0 to output direction

  P1DIR &= ~BIT3;                         // Set P1.3 to input direction
  P1REN |= BIT3;                          // Enable resistor for P1.3

  for (;;)
  {
	  volatile unsigned int k;
      if(!(P1IN & BIT3))
      {
          P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
		  k = 10000;                              // Delay
		  do (k--);
		  while (k != 0);
      }
      else{
          P1OUT &= ~BIT0;                     // Clear P1.0 using exclusive-OR
  }
}
