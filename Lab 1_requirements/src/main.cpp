#include <avr/io.h>        // Include for hardware register access (PINA, etc.)  
#include <util/delay.h>    // Include for delay functions like _delay_ms
#include "led.h"          // Include the LED control functions
#include "switch.h"       // Include the switch control functions

int main() {
   // Initialize hardware
   initLED();     // Set up LED pins as outputs 
   initSwitch();  // Set up switch pin as input with pull-up resistor
   
   // Main program loop - runs forever
   while(1) {
       // Forward sequence: Light LEDs from outer pairs to inner pairs
       // Loop from i=0 (outermost) to i=3 (innermost)
       for(unsigned int i = 0; i < 4; i++) {
           runLED(i);   // Turn on current LED pair, turn off others
           
           // Check if switch is pressed
           // PINA & (1 << PINA0) reads switch state
           // ! inverts it because switch is active LOW (pressed = 0)
           if(!(PINA & (1 << PINA0))) {
               _delay_ms(1000);  // Switch pressed - slow delay (1 second)
           } else {
               _delay_ms(100);   // Switch not pressed - fast delay (0.1 seconds)
           }
       }
       
       // Backward sequence: Light LEDs from middle pairs to outer pairs
       // Loop from i=2 (third pair) down to i=1 (second pair)
       for(unsigned int i = 2; i > 0; i--) {
           runLED(i);   // Turn on current LED pair, turn off others
           
           // Same switch check as above
           if(!(PINA & (1 << PINA0))) {
               _delay_ms(1000);  // Switch pressed - slow delay
           } else {
               _delay_ms(100);   // Switch not pressed - fast delay
           }
       }
   }
   
   return 0;  // Never reached due to infinite loop
}