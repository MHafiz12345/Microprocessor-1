# Lab 1: LED Pattern with Variable Speed

![LED Pattern Board](https://github.com/user-attachments/assets/616e23ba-3b91-4ecd-b0b6-edc916c8a576)

## 🔧 Overview

This project controls a sequence of 8 LEDs on an AVR microcontroller board using low-level register manipulation. The LEDs are arranged in 4 pairs and blink in a symmetric pattern from the outermost pair toward the center, then reverse. A physical switch adjusts the blinking speed, introducing user interaction and control flow based on input detection.

The implementation showcases use of SFR (Special Function Register) macros and bitwise operations to configure ports, drive LEDs, and read switch input without relying on high-level abstractions.

## 🎯 Project Behavior

* LEDs light up **inward**, starting with the **outermost pair**, one pair at a time.
* After reaching the **innermost pair**, the sequence reverses and LEDs blink **outward**.
* The **default delay** between transitions is **100ms**.
* When the **switch is pressed**, the delay **slows down to 1000ms**, creating a clear speed shift.

## ⚙️ Functional Breakdown

### `initLED()`
Configures the correct data direction registers (DDR) to set pins 4–11 as **output**. Each pin controls one LED.

### `turnOnLED(unsigned int led)` and `turnOffLED(unsigned int led)`
Turns on/off a specific LED pair based on the index:
* `0`: Outermost pair
* `1`: Second pair
* `2`: Third pair
* `3`: Innermost pair

Each pair uses separate PORTs (B, G, H, E) for LED control.

### `runLED(unsigned int led)`
Handles the main logic to ensure **only one LED pair is on** at a time by turning all others off before activating the desired pair.

### `initSwitch()`
Sets **pin 22** as an input and enables an **internal pull-up resistor**. The pin reads LOW when the switch is pressed and HIGH when released.

### `main()`
Runs an infinite loop that:
1. Cycles LEDs inward (`0` → `3`)
2. Cycles LEDs outward (`2` → `1`)
3. Checks switch state to adjust delay dynamically

## 🛠️ Key Features

* **Low-level programming** using direct register manipulation
* Use of **bit masking** for non-intrusive pin configuration
* Modular design with reusable LED and switch control functions
* Real-time **input-driven behavior** using a physical switch
* Conforms to **good coding practices** with meaningful comments

## 📁 File Structure

```
├── led.c    # LED control logic
├── led.h    # LED function declarations
├── switch.c # Switch setup logic
├── switch.h # Switch function declarations
├── main.c   # Main control loop
```

## 🧠 Concepts in Use

* Bitwise operations (`|`, `&`, `~`)
* Data direction and output registers (DDRx, PORTx)
* Debouncing with delay
* Basic embedded control flow
* Hardware abstraction via functions


## 🔌 Hardware Requirements

* AVR ATmega2560 microcontroller board
* 8 LEDs connected to pins 4-11
* Push button connected to pin 22
* Power supply (5V)
