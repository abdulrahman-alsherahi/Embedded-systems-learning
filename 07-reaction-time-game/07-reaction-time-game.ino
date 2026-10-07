#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int button = 7;
int led = 8;
int buzzer = 9;

unsigned long startTime;
unsigned long reactionTime;

void setup() {
  lcd.begin(16, 2);

  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {

  digitalWrite(led, LOW);

  lcd.clear();
  lcd.print("Get Ready");

  delay(random(2000, 5000));

  lcd.clear();
  lcd.print("PRESS!");

  digitalWrite(led, HIGH);
  tone(buzzer, 1000, 200);

  startTime = millis();

  while (digitalRead(button) == HIGH) {
  }

  reactionTime = millis() - startTime;

  digitalWrite(led, LOW);

  lcd.clear();
  lcd.print("Time:");

  lcd.setCursor(0, 1);
  lcd.print(reactionTime);
  lcd.print(" ms");

  delay(3000);
}
