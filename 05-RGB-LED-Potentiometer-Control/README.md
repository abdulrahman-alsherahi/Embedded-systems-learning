# RGB LED Control with Potentiometer

A simple Arduino project that controls the color of an RGB LED using a potentiometer.

Turning the potentiometer changes the RGB LED smoothly between different colors.

## Project Overview

The potentiometer provides an analog input to the Arduino.

The Arduino reads a value between:

```text
0 - 1023
```

This value is then used to control the brightness of the red, green, and blue channels of the RGB LED using PWM.

The color transition is approximately:

```text
Red -> Orange -> Yellow -> Green -> Cyan -> Blue
```

## Components

- Arduino Uno R3
- RGB LED
- Potentiometer
- 3 × 220Ω resistors
- Breadboard
- Jumper wires

## Wiring

### RGB LED

| RGB LED | Arduino |
|---|---|
| Red | Pin 9 |
| Green | Pin 10 |
| Blue | Pin 11 |
| Common | GND |

Each RGB color pin is connected through a 220Ω resistor.

### Potentiometer

| Potentiometer | Arduino |
|---|---|
| Left pin | 5V |
| Middle pin | A0 |
| Right pin | GND |

## How It Works

The Arduino reads the potentiometer using:

```cpp
analogRead(A0);
```

The returned value ranges from 0 to 1023.

The project divides this range into different sections.

### Red to Green

From approximately 0 to 449:

- Red brightness decreases.
- Green brightness increases.
- Blue stays off.

### Green

Between approximately 450 and 569:

- Red = 0
- Green = 255
- Blue = 0

This produces a pure green color.

### Green to Blue

From approximately 570 to 1023:

- Green brightness decreases.
- Blue brightness increases.
- Red stays off.

The `map()` function converts the potentiometer value into PWM brightness values between 0 and 255.

## Code

```cpp
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int potPin = A0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

  int value = analogRead(potPin);

  int redValue = 0;
  int greenValue = 0;
  int blueValue = 0;

  if (value < 450) {

    redValue = map(value, 0, 449, 255, 0);
    greenValue = map(value, 0, 449, 0, 255);
    blueValue = 0;

  }

  else if (value < 570) {

    redValue = 0;
    greenValue = 255;
    blueValue = 0;

  }

  else {

    redValue = 0;
    greenValue = map(value, 570, 1023, 255, 0);
    blueValue = map(value, 570, 1023, 0, 255);

  }

  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  delay(10);
}
```

## What I Learned

Through this project I learned:

- How an RGB LED works
- How to use a potentiometer
- How to read analog values with `analogRead()`
- How PWM works with `analogWrite()`
- How to control multiple PWM outputs
- How to use the `map()` function
- How to use `if`, `else if`, and `else`
- How to convert an input signal into an output response

## Embedded Systems Concept

This project demonstrates a basic embedded systems structure:

```text
User Input
    ↓
Potentiometer
    ↓
Analog Input
    ↓
Arduino
    ↓
Processing
    ↓
PWM Output
    ↓
RGB LED
```

The same concept can later be applied to sensors, motors, displays, fans, and other embedded devices.

## Project Image

![RGB LED Potentiometer Project](images/rgb-led-project.jpg)

## Future Improvements

Possible future improvements:

- Add a push button to select color modes
- Add automatic color fading
- Display RGB values in the Serial Monitor
- Control RGB brightness using multiple potentiometers
- Replace the potentiometer with a sensor
