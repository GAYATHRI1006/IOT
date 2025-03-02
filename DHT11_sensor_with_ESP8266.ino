#include <ESP8266WiFi.h>   // Required for ESP8266 boards (even if not connecting to WiFi)
#include <DHT.h>

// DHT11 Sensor Configuration
#define DHTPIN D4       // DHT11 sensor data pin connected to NodeMCU D4 (GPIO2)
#define DHTTYPE DHT11   // Define sensor type as DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);  // Start Serial Monitor with a baud rate of 115200
  dht.begin();           // Initialize the DHT sensor
  Serial.println("DHT11 Sensor Reading Started");
}

void loop() {
  // Read temperature in Celsius and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  delay(2000); // Wait 2 seconds between measurements
}