//Versi 4 lampu max 255


const int potentiometerPin = A0; 
const int lampuPin = D1; 
const int lampuPin2 = D2; 
const int lampuPin3 = D3; 
const int lampuPin4 = D4; 

void setup() {
  Serial.begin(9600);

  pinMode(potentiometerPin, INPUT);

  pinMode(lampuPin, OUTPUT);
  pinMode(lampuPin2, OUTPUT);
  pinMode(lampuPin3, OUTPUT);
  pinMode(lampuPin4, OUTPUT);

  Serial.println("ESP8266 Potentiometer Brightness Control");
}

void loop() {
   int potValue = analogRead(potentiometerPin);

  int brightness = map(potValue, 0, 1023, 0, 255);
  
  // If the potentiometer is at its maximum value, turn off the lights completely
  if (potValue == 1023) {
    digitalWrite(lampuPin, LOW);
    digitalWrite(lampuPin2, LOW);
    digitalWrite(lampuPin3, LOW);
    digitalWrite(lampuPin4, LOW);
  } else {
    analogWrite(lampuPin, 255 - brightness);
    analogWrite(lampuPin2, 255 - brightness);
    analogWrite(lampuPin3, 255 - brightness);
    analogWrite(lampuPin4, 255 - brightness);
  }

  Serial.print("Potentiometer Value: ");
  Serial.println(brightness);

  delay(100);
}
