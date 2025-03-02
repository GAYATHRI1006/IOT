int ledPin = 13;    // Pin where the LED is connected
int buttonPin = 7;  // Pin where the pushbutton is connected
bool isButtonPressed = false;  // Track the state of the button

void setup() {
  // Initialize LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Initialize button pin as an input with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Read the state of the pushbutton
  isButtonPressed = digitalRead(buttonPin) == LOW; // Button is pressed when LOW
  
  if (isButtonPressed) {
    // If the button is pressed, make the LED blink
    digitalWrite(ledPin, HIGH);  // Turn LED on
    delay(500);                   // Wait for 500ms
    digitalWrite(ledPin, LOW);   // Turn LED off
    delay(500);                   // Wait for 500ms
  } else {
    // If the button is not pressed, keep the LED off
    digitalWrite(ledPin, LOW);   // Ensure the LED is off
  }
}

