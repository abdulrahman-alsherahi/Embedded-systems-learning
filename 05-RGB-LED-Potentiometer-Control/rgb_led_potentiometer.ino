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
