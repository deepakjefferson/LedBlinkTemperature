#include <elapsedMillis.h>

const int sensorPin = A0; // LM35 sensor connected to analog pin A0
const int ledPin = 13;    // Onboard LED connected to digital pin 13

float temperatureC = 0; // Variable to store temperature in Celsius
int ledState = LOW;     // Variable to store the LED state
elapsedMillis interval; // Timer to keep track of interval

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read the sensor value
  float voltage = sensorValue * (5.0 / 1023.0); // Convert sensor value to voltage
  temperatureC = voltage * 100.0; // Convert voltage to temperature in Celsius

  // Check temperature and set blinking interval accordingly
  if (temperatureC < 30) {
    if (interval >= 250) {
      interval = 0; // Reset the interval
      ledState = !ledState; // Toggle LED state
      digitalWrite(ledPin, ledState); // Set the LED with the ledState
    }
  } else {
    if (interval >= 500) {
      interval = 0; // Reset the interval
      ledState = !ledState; // Toggle LED state
      digitalWrite(ledPin, ledState); // Set the LED with the ledState
    }
  }
}