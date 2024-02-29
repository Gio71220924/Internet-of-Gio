const int analogpin = A0;
float value;
int led12 = D2;


void setup(){
  Serial.begin(9600);
}


void loop(){
  value = analogRead(analogpin);
  float persamaan = value*255/1024;
  Serial.println(persamaan);
  delay(255);
  analogWrite(led12, persamaan);
}