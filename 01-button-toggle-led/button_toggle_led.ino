int button = 2;
int led = 8;

bool ledOn = false;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {

  if (digitalRead(button) == LOW) {

    ledOn = !ledOn;

    digitalWrite(led, ledOn);

    delay(200);

    while (digitalRead(button) == LOW) {

    }
  }
}
