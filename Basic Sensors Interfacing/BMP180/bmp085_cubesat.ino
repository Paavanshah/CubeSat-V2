#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>

// Create an Adafruit_BMP085 object
Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP180 Test"));

  // Check if the sensor is connected. If not, halt the program.
  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP085 sensor, check wiring!"));
    while (1) {}
  }
}

void loop() {
  // Read and print the temperature in Celsius
  Serial.print(F("Temperature = "));
  Serial.print(bmp.readTemperature());
  Serial.println(F(" *C"));

  // Read and print the pressure in Pascals
  Serial.print(F("Pressure = "));
  Serial.print(bmp.readPressure());
  Serial.println(F(" Pa"));

  // Read and print the altitude in meters
  Serial.print(F("Altitude = "));
  Serial.print(bmp.readAltitude());
  Serial.println(F(" meters"));

  Serial.println(); // Add a blank line for readability
  delay(2000); // Wait for 2 seconds before the next reading
}