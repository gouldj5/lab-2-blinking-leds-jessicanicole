#include <msp430.h>

#define BUTTON BIT3
#define LED1 BIT0

void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

P1OUT &= ~LED1;                         // Clear P1.0 output latch for a defined power-on state
P1DIR = LED1;                          // Set P1.0 to output direction

P1DIR &= ~BUTTON; // sets button to input direction
P1REN ^= BUTTON; //Enables a puller-Resistor on the button-pin
P1OUT ^= BUTTON; //Writes a "1" to the portpin, telling the resistor to pullup

while(1)
{
    if (!(BUTTON & P1IN))
       P1OUT |= LED1;  // Blink LED when button is pressed
    else
       P1OUT &= ~LED1; //LED off when button is not pressed
}
}
