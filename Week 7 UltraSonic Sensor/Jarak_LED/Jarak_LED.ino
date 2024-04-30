//Define pin
int triggerPin =  D7;
int echoPin  = D8;
int LED1  = D0;
int hitung = 0;
int kosong = 0;

void setup(){
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop(){
  long duration, jarak,jarak2;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);
  duration = pulseIn(echoPin, HIGH);
  //(Satuan kecepatansuara * waktutempuh)/2
  //(Satuan kecepatan suara = 340m/s)
  jarak2 = (duration*0.034)/2;

  Serial.print(" Jarak = ");  // Print "Jarak = "
  Serial.print(jarak2);     // Print the calculated distance
  Serial.print(" cm");       // Print " cm"
  Serial.println();           // Print a newline for readability

  delay(150);

  if (jarak2 <10){
    digitalWrite(LED1, LOW);
    Serial.print("LED ON ");
    if(kosong==1){
      hitung = hitung +1;
      kosong = 0;
    }

  }else{
    digitalWrite(LED1, HIGH);
    Serial.print("LED OFF ");
    kosong = 1;

  }

  Serial.print("Jumlah: ");
  Serial.print(hitung );
  delay(250);

}