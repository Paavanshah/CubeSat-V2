#include <DHT.h>

#define DHTPIN 2        // Pin connected to the DHT11 data pin
#define DHTTYPE DHT11   // Define sensor type as DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);   // Initialize serial communication
  dht.begin();          // Start DHT sensor
}

void loop() {
  delay(2000); // Wait between readings (DHT11 is slow)

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check for failed readings
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT11 sensor!");
    return;
  }

  // Print to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
