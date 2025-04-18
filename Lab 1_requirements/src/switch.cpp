#include <avr/io.h>    // Include for hardware pin control

void initSwitch(){
   // Configure pin 22 as input
   // Set DDR bit to 0 for input mode
   // Using &= ~ to clear the specific bit while preserving others
   DDRA &= ~(1 << DDA0);  
   
   // Enable internal pull-up resistor on pin 22
   // Pull-up keeps pin HIGH when switch is not pressed
   // Pin reads LOW when switch is pressed
   // Using |= to set the specific bit while preserving others
   PORTA |= (1 << PORTA0);  
}