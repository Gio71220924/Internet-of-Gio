#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#define DHTPIN D4   //Masukin ke D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
const int relayPin = D1;
float suhu;

const char *ssid = "Redmi10S";
const char *password = "steve123";

const char *mqtt_broker = "broker.emqx.io";
const char *topic = "Tugas IOT 71220924 Giovanka/Sensor suhu dengan relay";
const char *mqtt_username = "qwerty";
const char *mqtt_password = "public";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to the WiFi network");
  // connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while(!client.connected()){
    String client_id = "esp8266-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    if(client.connect(client_id.c_str(), mqtt_username, mqtt_password)){
      Serial.println("Public emqx mqtt broker connected");
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(750);
    }
  }
  client.subscribe(topic);

  pinMode(relayPin, OUTPUT);
  dht.begin();
}

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  Serial.println("------------------------");
}

String msg_out;

void loop() {

  float t = dht.readTemperature();
  int h = dht.readHumidity();
  
  if (t>34){
    digitalWrite(relayPin, LOW);
    Serial.print(" On  ");
  } else {
    digitalWrite(relayPin, HIGH);
    Serial.print(" Off  ");
  }
  Serial.print("Temperatur = ");
  Serial.print(t);
  Serial.print("°C");

  Serial.print(" Kelembapan = ");
  Serial.print(h);
  Serial.print("%\n");

  delay(250);

  msg_out = "Temperature: "+String(t)+"°C     Kelembapan: "+String(h)+" %     " ;
  int str_len = msg_out.length()+1;
  char char_array[str_len];
  msg_out.toCharArray(char_array, str_len);
  client.publish(topic, char_array);
  delay(750);
}