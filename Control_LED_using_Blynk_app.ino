/* New Blynk App - Home Automation for ESP32 */

// Blynk Configuration
#define BLYNK_TEMPLATE_ID "TMPL3dQdKPDhy"
#define BLYNK_TEMPLATE_NAME "TRAFFIC LIGHT"
#define BLYNK_AUTH_TOKEN "aOmm8p6gRMyOkeOTYRjFIZ9FhAJjwJEp"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// WiFi Credentials
char ssid[] = "realme 9i 5G";      // Enter your WiFi Name
char pass[] = "harini@123";  // Enter your WiFi Password

// Define relay pins (ESP32 GPIOs)
// Adjust these GPIO numbers as needed for your ESP32 board and wiring
#define relay1  16
#define relay2  17
#define relay3  18
#define wifiLed  5

// Blynk Virtual Pin Controls
BLYNK_WRITE(V0) {
  digitalWrite(relay1, param.asInt() ? LOW : HIGH);
}

BLYNK_WRITE(V1) {
  digitalWrite(relay2, param.asInt() ? LOW : HIGH);
}

BLYNK_WRITE(V2) {
  digitalWrite(relay3, param.asInt() ? LOW : HIGH);
}

void setup() {
  Serial.begin(115200);
  delay(100);

  // Set pin modes
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(wifiLed, OUTPUT);

  // Turn off relays initially (assuming active LOW relay modules)
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(wifiLed, HIGH);

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}