// Kelap kelip with button pressed

const int ledPin1 = D0; // LED pertama
const int ledPin2 = D1; // LED kedua
const int buttonPin = D2; // Tombol untuk kedua LED

bool forwardDirection = true; // Flag to track the direction of the burst sequence

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Set pin tombol sebagai input dengan resistor pull-up
}

void loop() {
  // Membaca status tombol
  if (digitalRead(buttonPin) == LOW) {
    // Toggle direction
    forwardDirection = !forwardDirection;
    
    // Perform burst sequence
    while (digitalRead(buttonPin) == LOW) { // Continue burst sequence until button is released
      if (forwardDirection) {
        // Forward burst sequence
        digitalWrite(ledPin1, HIGH); // Turn on LED 1
        digitalWrite(ledPin2, HIGH); // Turn on LED 2
        delay(100); // Wait for a short duration
        digitalWrite(ledPin1, LOW); // Turn off LED 1
        digitalWrite(ledPin2, LOW); // Turn off LED 2
        delay(100); // Wait for a short duration
      } else {
        // Reverse burst sequence
        digitalWrite(ledPin2, HIGH); // Turn on LED 2
        digitalWrite(ledPin1, HIGH); // Turn on LED 1
        delay(100); // Wait for a short duration
        digitalWrite(ledPin2, LOW); // Turn off LED 2
        digitalWrite(ledPin1, LOW); // Turn off LED 1
        delay(100); // Wait for a short duration
      }
    }
  }
}
