int potPin = A0;
int ledPin = 9;
int button = 2;

bool ledOn = false;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  if (digitalRead(button) == LOW) {

    ledOn = !ledOn;

    delay(100);

    while (digitalRead(button) == LOW) {
    }
  }

  if (ledOn == true) {

    int value = analogRead(potPin);

    int brightness = map(value, 0, 1023, 0, 255);

    analogWrite(ledPin, brightness);

  } else {

    analogWrite(ledPin, 0);
  }
}
