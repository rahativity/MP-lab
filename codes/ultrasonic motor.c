#include <LiquidCrystal.h>

// LCD Pins matching your Proteus schematic: RS=13, E=12, D4=11, D5=10, D6=9, D7=8
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// Sensor and Relay Pins
const int trigPin = 6;
const int echoPin = 5;
const int relayPin = 7;

// Distance threshold in cm (adjust as needed)
const int distanceThreshold = 20;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);

  // Initialize 20x4 LCD (LM044L)
  lcd.begin(20, 4);
  lcd.setCursor(0, 0);
  lcd.print("ULTRASONIC SYSTEM");
}

void loop() {
  // Send a 10us HIGH pulse to Trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read Echo pulse duration and calculate distance in cm
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  // Display Distance on LCD
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm    ");

  // Control Relay & Motor based on threshold
  lcd.setCursor(0, 2);
  if (distance > 0 && distance < distanceThreshold) {
    digitalWrite(relayPin, HIGH);
    lcd.print("Motor Status: ON ");
  } else {
    digitalWrite(relayPin, LOW);
    lcd.print("Motor Status: OFF");
  }

  delay(200);
}