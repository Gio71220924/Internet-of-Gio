// Both On and Off
const int ledPin1 = D0; // LED pertama
const int ledPin2 = D1; // LED kedua
const int buttonPin = D2; // Tombol untuk kedua LED

bool ledState = LOW; // Awalnya kedua LED dimatikan

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Set pin tombol sebagai input dengan resistor pull-up
}

void loop() {
  // Membaca status tombol
  if (digitalRead(buttonPin) == LOW) {
    // Toggle status kedua LED
    ledState = !ledState;
    digitalWrite(ledPin1, ledState);
    digitalWrite(ledPin2, ledState);
    // Tunggu hingga tombol dilepas
    while (digitalRead(buttonPin) == LOW) {
      delay(10);
    }
  }
}
