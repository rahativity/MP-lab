const int pirPin = 12;
const int ledPin = 13;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("PIR Sensor Initialized...");
}

void loop() {
  int sensorState = digitalRead(pirPin);

  if (sensorState == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("No motion.");
  }

  delay(500);
}
