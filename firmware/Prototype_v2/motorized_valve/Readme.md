# Overview

This simple Arduino example demonstrates driving a stepper motor using a combination of PCA9685 I2C multiplexer board and an ULN2003 Darlington driver. 

One single PCA9685 board can drive up to 4 stepper motors. The example can be easily extended to drive a very large number of stepper motors using one Arduino board, simply by chaining multiple PCA9685 boards.

We demonstrate this using a BYJ48 stepper motor which can be driven straight from the USB bus. 

All components involved are fairly inexpensive (total cost < $15-$20). 

# Mechanical components
- Heavy Duty Brass Replacement Control Needle Valve 1/4" Female NPT X 1/4" Female NPT [link](https://www.amazon.com/Litorange-Replacement-Control-Needle-Connection/dp/B07YFR72JP/). You need to unscrew the brass knob (held in place with epoxy/thread-lock resin which can be molten using a lighter). After unscrewing you have a 1/4" brass stem on which the coupler can be mounted.
- An 5mm to 6.35 mm (1/4") motor stepper coupler or equivalent [link](https://www.amazon.com/gp/product/B07YDGZJCZ/)
- A DIY structure that will hold the motor and the needle valve together in place

# Electronic components
- Arduino Uno or equivalent
- ULN2003 board
- PCA9685 board
- Stepper motor (BYJ48). 5 mm shaft. 
- Breadboard + jumper wires
- 5V power supply, strong enough to drive the stepper motors (< 1A?)

# Connections
- from Arduino Uno to PCA9695
  - 5V    ->    Vcc 
  - GND   ->    GND
  - SCL   ->    SCL
  - SDA   ->    SDA
  - Vin   ->    Power V+ (or from standalone external 5V power source)
  - GND   ->    Power GND

- from Arduino Uno to ULN2003 
  - Vin   ->    Power + (5..12V)	(or from standalone external 5V power source)
  - GND   ->    Power - 
       
- from PCA9685 to ULN2003 board
  - PWM pin 0   ->    IN 1
  - PWM pin 1   ->    IN 2
  - PWM pin 2   ->    IN 3
  - PWM pin 3   ->    IN 4

- from ULN2003 to BYJ48 stepper motor
  - Use the standard 5-pin connector with the default wiring

# Notes
- The stepper motor rotates using default power from USB assuming a high-power USB port (1A minim)
- If you want to drive bigger motors or multiple motors you can supply 5V using an external power source. The ground still needs to be kept common.
- There is no code currently for endstop detection. You would need to control the total travel time in software. 
