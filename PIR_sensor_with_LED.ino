#define PIR_PIN 2      // PIR sensor output pin
#define RED_LED 9      // Red LED pin
#define GREEN_LED 10   // Green LED pin

void setup() {
    pinMode(PIR_PIN, INPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    
    // Start with the red LED on
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
}

void loop() {
    int motion = digitalRead(PIR_PIN);
    
    if (motion == HIGH) {  // If motion is detected
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);
    } else {  // If no motion is detected
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);
    }
}
