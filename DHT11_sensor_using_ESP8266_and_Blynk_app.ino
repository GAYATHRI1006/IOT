

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// WiFi credentials
char ssid[] = "Oppo";
char pass[] = "Gayu@1006";

// DHT sensor configuration
#define DHTPIN D2         // Connect DHT sensor data pin to D2 (GPIO4 on NodeMCU may also be used)
#define DHTTYPE DHT11     // Change to DHT22 if using that sensor
DHT dht(DHTPIN, DHTTYPE);

// Blynk timer
BlynkTimer timer;

// Function to read sensor data and send to Blynk
void sendSensorData() {
  float temperature = dht.readTemperature(); // Temperature in Celsius
  float humidity    = dht.readHumidity();    // Humidity in %

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Send sensor data to Blynk virtual pins (using V4 for Temperature and V5 for Humidity)
  Blynk.virtualWrite(V4, temperature);
  Blynk.virtualWrite(V5, humidity);
}

void setup() {
  Serial.begin(115200);
  delay(100);

  // Initialize the DHT sensor
  dht.begin();

  // Initialize Blynk with the Auth Token and WiFi credentials
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Set a timer to send sensor data every 2 seconds
  timer.setInterval(2000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}