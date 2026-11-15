// Include the LCD library
#include <LiquidCrystal.h>

// Initialize the LCD with interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// Define the soil moisture sensor pin
const int SensorPin = A0;

void setup()
{
    // Set up the LCD (20 columns and 4 rows)
    lcd.begin(20, 4);

    // Display the title
    lcd.setCursor(0, 0);
    lcd.print("      Test");

    lcd.setCursor(0, 1);
    lcd.print("SOIL MOISTURE SENSOR");
}

void loop()
{
    // Read the analog value from the sensor
    int Val = analogRead(SensorPin);

    // Convert sensor value into percentage
    int Moisture = map(Val, 0, 1023, 0, 100);

    // Display soil moisture on the LCD
    lcd.setCursor(0, 3);
    lcd.print("Soil Moisture: ");
    lcd.print(Moisture);
    lcd.print("%   ");

    delay(500);
}