#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x3F, 16 column and 2 rows

int trigPin = 9;    // TRIG pin
int echoPin = 10;    // ECHO pin

float duration_us, distance_cm;

void setup() {
  lcd.init();               // initialize the lcd
  lcd.backlight();          // open the backlight 
  pinMode(trigPin, OUTPUT); // config trigger pin to output mode
  pinMode(echoPin, INPUT);  // config echo pin to input mode
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  lcd.clear();
  lcd.setCursor(0, 0); // start to print at the first row
  lcd.print("Lumayo Ka: ");
  lcd.print(distance_cm);

  delay(500);
}
