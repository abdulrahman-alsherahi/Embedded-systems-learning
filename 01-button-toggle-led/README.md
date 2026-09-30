# Button Toggle LED

A simple Arduino project where a push button toggles an external LED ON and OFF.

## Components

- Arduino UNO R3
- Push Button
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires

## Wiring

### Button
- One side → Digital Pin 2
- Other side → GND

### LED
- Digital Pin 8 → 220Ω resistor → LED
- Other LED leg → GND

## Behavior

- First press → LED ON
- Second press → LED OFF
- Every press toggles the LED state

## Concepts Learned

- Digital input
- Digital output
- `INPUT_PULLUP`
- `digitalRead()`
- `digitalWrite()`
- Boolean state control
