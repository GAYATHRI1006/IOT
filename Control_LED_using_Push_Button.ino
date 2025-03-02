// Pin Definitions
const int buttonPin = 2;    // Pin for the push button
const int ledPin = 13;      // Pin for the LED

// Variable Definitions
int buttonState = 0;         // Variable to hold button state
int lastButtonState = 0;     // Variable to hold previous button state
bool ledState = false;       // Variable to track LED state

void setup() {
  // Initialize the button pin as input with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Initialize the LED pin as output
  pinMode(ledPin, OUTPUT);
  
  // Start with the LED off
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);
  
  // Check if the button was pressed (transition from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Toggle the LED state
    ledState = !ledState;
    
    // Update the LED based on the state
    digitalWrite(ledPin, ledState ? HIGH : LOW);
    
    // Delay to debounce the button (avoid multiple toggles on a single press)
    delay(200);
  }

  // Save the current button state as the last state for next loop
  lastButtonState = buttonState;
}
