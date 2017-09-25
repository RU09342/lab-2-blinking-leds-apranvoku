
//******************************************************************************
//  MSP430FR5x9x Demo - Toggle P1.0 using software
//
//  Description: Toggle P1.0 using software.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//           MSP430FR5994
//         ---------------
//     /|\|               |
//      | |               |
//      --|RST            |
//        |               |
//        |           P1.0|-->LED
//
//   William Goh
//   Texas Instruments Inc.
//   October 2015
//   Built with IAR Embedded Workbench V6.30 & Code Composer Studio V6.1
//******************************************************************************
#include <msp430.h>

int main(void)
{

    WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT

    // Configure GPIO
    P1OUT &= ~BIT0;      // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction

    P4OUT &= ~BIT7;      // Clear P1.1 output latch for a defined power-on state
    P4DIR |= BIT7;                          // Set P1.1 to output direction

    P2DIR &= ~BIT1;                         // Set P2.1 to input direction
    P2REN |= BIT1;                          // Enable resistor for P2.1
    P2OUT |= BIT1;

    while (1)
    {
         const int duty = 500;
         int load;

         for (load = 0; load < duty ; load++)
         {
             int i;
             for (i = 0; i < duty; i ++)
             {
                 if(!(P2IN & BIT1))    //If button is pressed, leds are flipped
                 {
                     if(i > load)     //if i is less then steadily increasing load, LED is flipped on.
                                      //Led fraction of time flipped on increases as time increases.
                       {
                          P4OUT &= ~BIT7;
                          P1OUT |= BIT0;
                       }
                     else
                        {
                          P4OUT |= BIT7;
                          P1OUT &= ~BIT0;
                        }

                 }
                 else
                 {
                     if(i < load)
                           {
                               P4OUT &= ~BIT7;
                               P1OUT |= BIT0;
                           }
                     else
                           {
                               P4OUT |= BIT7;
                               P1OUT &= ~BIT0;
                           }
                 }
             }
         }
   }
}
