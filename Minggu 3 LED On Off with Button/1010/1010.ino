// One on and one off
const int ledPin1 = D0; // LED pertama
const int ledPin2 = D1; // LED kedua
const int buttonPin1 = D2; // Tombol untuk LED pertama
const int buttonPin2 = D3; // Tombol untuk LED kedua

int ledState1 = LOW; // Menyimpan status LED pertama (mati)
int ledState2 = LOW; // Menyimpan status LED kedua (mati)

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP); // Set pin tombol 1 sebagai input dengan resistor pull-up
  pinMode(buttonPin2, INPUT_PULLUP); // Set pin tombol 2 sebagai input dengan resistor pull-up
}

void loop() {
  // Tombol untuk LED pertama
  if (digitalRead(buttonPin1) == LOW) {
    // Toggle status LED pertama
    ledState1 = !ledState1;
    digitalWrite(ledPin1, ledState1); // Mengaktifkan atau mematikan LED pertama
    // Tunggu hingga tombol dilepas
    while (digitalRead(buttonPin1) == LOW) {
      delay(10);
    }
  }

  // Tombol untuk LED kedua
  if (digitalRead(buttonPin2) == LOW) {
    // Toggle status LED kedua
    ledState2 = !ledState2;
    digitalWrite(ledPin2, ledState2); // Mengaktifkan atau mematikan LED kedua
    // Tunggu hingga tombol dilepas
    while (digitalRead(buttonPin2) == LOW) {
      delay(10);
    }
  }
}
