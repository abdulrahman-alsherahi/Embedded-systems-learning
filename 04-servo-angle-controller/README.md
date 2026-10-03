# Servo Angle Controller

A simple Arduino project that controls the angle of a servo motor using a potentiometer.

## How It Works

The potentiometer provides an analog value from 0 to 1023.

Arduino reads this value using `analogRead()` and converts it to a servo angle from 0° to 180° using `map()`.

The servo then moves to the calculated angle.

## Components

- ELEGOO UNO R3
- Servo Motor
- Potentiometer
- Breadboard
- Jumper Wires

## Connections

### Potentiometer

- One outer pin → 5V
- Middle pin → A0
- Other outer pin → GND

### Servo Motor

- Red → 5V
- Brown / Black → GND
- Orange / Yellow → Pin 9

## Main Concepts

- Analog input
- `analogRead()`
- `map()`
- Servo motor control
- Input → Processing → Output

## Result

Rotating the potentiometer changes the angle of the servo motor in real time.
