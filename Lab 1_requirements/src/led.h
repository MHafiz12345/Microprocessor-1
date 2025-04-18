// This prevents the header from being included multiple times
#ifndef LED_H
#define LED_H

// Function to set up LED pins as outputs
void initLED();

// Function to turn on a specific pair of LEDs
// Parameter led: which LED pair to turn on (0-3)
//   0 = outermost pair
//   1 = second pair
//   2 = third pair
//   3 = innermost pair
void turnOnLED(unsigned int led);

// Function to turn off a specific pair of LEDs
// Parameter led: which LED pair to turn off (0-3)
void turnOffLED(unsigned int led);

// Function to control LED pattern
// Turns on specified LED pair and ensures others are off
// Parameter led: which LED pair to control (0-3)
void runLED(unsigned int led);

#endif
