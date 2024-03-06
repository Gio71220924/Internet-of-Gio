// potentio ke yang ga ada garis
// photoresistor ke yang ada garis
const int led1 = 2;
const int led2 = 4;
const int led3 = 7;
const int led4 = 8;
const int potensio = A0;

const int led5 = 3;
const int led6 = 5;
const int led7 = 6;
const int led8 = 9;
const int photor = A1;


void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(potensio, INPUT);
  
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(photor, INPUT);
}

void loop()
{
  int potensioV = analogRead(potensio);
  Serial.print(potensioV);
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  
  if (potensioV<135){
  	digitalWrite(led1, LOW);
  	digitalWrite(led2, LOW);
  	digitalWrite(led3, LOW);
  	digitalWrite(led4, LOW);
  } else if (potensioV<270){
    digitalWrite(led1, HIGH);
  	digitalWrite(led2, LOW);
  	digitalWrite(led3, LOW);
  	digitalWrite(led4, LOW);
  } else if (potensioV<405){
    digitalWrite(led1, HIGH);
  	digitalWrite(led2, HIGH);
  	digitalWrite(led3, LOW);
  	digitalWrite(led4, LOW);
  } else if (potensioV<540){
    digitalWrite(led1, HIGH);
  	digitalWrite(led2, HIGH);
  	digitalWrite(led3, HIGH);
  	digitalWrite(led4, LOW);
  } else {
    digitalWrite(led1, HIGH);
  	digitalWrite(led2, HIGH);
  	digitalWrite(led3, HIGH);
  	digitalWrite(led4, HIGH);
  }
  
  Serial.print(" ");
  
  int photorV = analogRead(photor);
  Serial.print(photorV);
  
  if (photorV<135){
  	digitalWrite(led5, LOW);
  	digitalWrite(led6, LOW);
  	digitalWrite(led7, LOW);
  	digitalWrite(led8, LOW);
  } else if (photorV<270){
    digitalWrite(led5, HIGH);
  	digitalWrite(led6, LOW);
  	digitalWrite(led7, LOW);
  	digitalWrite(led8, LOW);
  } else if (photorV<405){
    digitalWrite(led5, HIGH);
  	digitalWrite(led6, HIGH);
  	digitalWrite(led7, LOW);
  	digitalWrite(led8, LOW);
  } else if (photorV<540){
    digitalWrite(led5, HIGH);
  	digitalWrite(led6, HIGH);
  	digitalWrite(led7, HIGH);
  	digitalWrite(led8, LOW);
  } else {
    digitalWrite(led5, HIGH);
  	digitalWrite(led6, HIGH);
  	digitalWrite(led7, HIGH);
  	digitalWrite(led8, HIGH);
  }

 
  Serial.println("");
}