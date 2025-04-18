#include <avr/io.h>      // Include for hardware register access (DDRB, PORTB, etc.)
#include <util/delay.h>  // Include for delay functions
#include "led.h"         // Include the LED header file

// Initialize all LED pins as outputs
void initLED(){
    // Configure pins 4-11 as outputs using Data Direction Registers (DDR)
    // When a DDR bit is set to 1, that pin becomes an output
    // Using |= to set specific bits while leaving others unchanged
    
    // Set pins 4 and 5 of Port B as outputs
    DDRB |= (1 << DDB4) | (1 << DDB5);
    
    // Set pins 3, 4, 5, and 6 of Port H as outputs
    DDRH |= (1 << DDH3) | (1 << DDH4) | (1 << DDH5) | (1 << DDH6);
    
    // Set pin 3 of Port E as output
    DDRE |= (1 << DDE3);
    
    // Set pin 5 of Port G as output
    DDRG |= (1 << DDG5);
}

// Function to turn ON specific LED pairs
// Parameter led: 0 = outermost pair, 3 = innermost pair
void turnOnLED(unsigned int led){
    if (led == 0) {
        // Turn on outermost LED pair
        // Using |= with PORT register sets pin to HIGH (LED ON)
        PORTB |= (1 << PB5);  // Turn on first LED of pair
        PORTG |= (1 << PG5);  // Turn on second LED of pair
    }
    else if (led == 1) {
        // Turn on second LED pair from outside
        PORTE |= (1 << PE3);  // Turn on first LED of pair
        PORTB |= (1 << PB4);  // Turn on second LED of pair
    }
    else if (led == 2) {
        // Turn on third LED pair from outside
        PORTH |= (1 << PH6);  // Turn on first LED of pair
        PORTH |= (1 << PH3);  // Turn on second LED of pair
    }
    else if (led == 3) {
        // Turn on innermost LED pair
        PORTH |= (1 << PH5);  // Turn on first LED of pair
        PORTH |= (1 << PH4);  // Turn on second LED of pair
    }
}

// Function to turn OFF specific LED pairs
// Parameter led: 0 = outermost pair, 3 = innermost pair
void turnOffLED(unsigned int led){
    if (led == 0) {
        // Turn off outermost LED pair
        // Using &= ~ with PORT register sets pin to LOW (LED OFF)
        PORTB &= ~(1 << PB5);  // Turn off first LED of pair
        PORTG &= ~(1 << PG5);  // Turn off second LED of pair
    }
    else if (led == 1) {
        // Turn off second LED pair from outside
        PORTE &= ~(1 << PE3);  // Turn off first LED of pair
        PORTB &= ~(1 << PB4);  // Turn off second LED of pair
    }
    else if (led == 2) {
        // Turn off third LED pair from outside
        PORTH &= ~(1 << PH6);  // Turn off first LED of pair
        PORTH &= ~(1 << PH3);  // Turn off second LED of pair
    }
    else if (led == 3) {
        // Turn off innermost LED pair
        PORTH &= ~(1 << PH5);  // Turn off first LED of pair
        PORTH &= ~(1 << PH4);  // Turn off second LED of pair
    }
}

// Function to manage LED pattern
// Ensures only one LED pair is on at a time
void runLED(unsigned int led){
    // Turn off all LEDs except the current pair
    // Loop through all LED pairs (0-3)
    for(unsigned int i = 0; i < 4; i++) {
        // If this isn't the LED pair we want on
        if(i != led) {
            turnOffLED(i);  // Turn it off
        }
    }
    // Turn on the desired LED pair
    turnOnLED(led);
}