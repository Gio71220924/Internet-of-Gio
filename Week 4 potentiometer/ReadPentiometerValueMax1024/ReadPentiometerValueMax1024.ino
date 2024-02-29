// Versi 1024
const int analogPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int rawValue = analogRead(analogPin);

  // Map the value from 0-1023 to 0-1024
  int mappedValue = map(rawValue, 0, 1023, 0, 1023);

  // Tampilkan output di serial monitor
  Serial.println("Value: " + String(mappedValue));

  delay(100); // Adjust delay 
}
