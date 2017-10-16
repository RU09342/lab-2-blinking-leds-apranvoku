# Off Board Blink
##Author: Ardit Pranvoku  

To run this code, simply import the project folder into code composer, build, then debug.
Blinks 2 LEDs on the board at a half duty cycles.
Any board specific pins and pits will be substituted with the variable X.
The watchdog timer must be stopped with the line WDTCTL = WDTPW + WDTHOLD or WDTCTL = WDTPW | WDTHOLD.
Else, the processor will reset.

The desired button pin and bit must be to 0 to configure it to be an input.
Also,  PXREN |= BITX; must be used to enable the pullup resistor for that button.     
By using the line PM5CTL0 = ~LOCKLPM5, the default high impedance on the board is disabled.
This high impedance serves to get rid of any cross currents, but is turned off later.

In the code, a button is set as an input. That button is then polled, and if it's pressed,
the processor will toggle a pin on the board. A wire can be run from the pin to 2 LEDs with a 1k resistor in front 
in series to power them.