  #include <ESP8266WiFi.h>
  #include <PubSubClient.h>
  #include "DHT.h"

  #define DHTPIN 4
  #define DHTTYPE DHT11

  //Wifi
  const char *ssid = "sixbrothers";
  const char *password = "password12345";

  // MQTT Broker
  const char *mqtt_broker = "broker.emqx.io";
  const char *topic = "71220924/Sensor";
  const char *mqtt_username = "qwerty";
  const char *mqtt_password = "public";
  const int mqtt_port = 1883;


  DHT dht(DHTPIN, DHTTYPE);
  // int swValue;
  // const int led1 = D0;
  // const int relay = D8;

  WiFiClient espClient;
  PubSubClient client(espClient);

  void setup() {
    // pinMode(led1, OUTPUT);
    Serial.begin(115200);
    Serial.println(F("DHTxx test!"));
    dht.begin();
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
        delay(2000);
      }
    }
    client.subscribe(topic);
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
  int a = 1234;
  char msg_out[20];



  void loop() {
    delay(750);



    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float f = dht.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }

    // Compute heat index in Fahrenheit (the default)
    float hif = dht.computeHeatIndex(f, h);
    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.print(F("Temperatur: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(F("Kelembapan: "));
    Serial.println(h);

    delay(1500);


      int msg_out[] = {t,h};
  delay(2000);

  String jsonStr = "["; // Buat array JSON
  for (int i = 0; i < 2; i++) {
    jsonStr += String(msg_out[i]);
    if (i < 1) {
      jsonStr += ",";
    }
  }
  jsonStr += "]";

  char msg[jsonStr.length() + 1];
  jsonStr.toCharArray(msg, jsonStr.length() + 1);
  client.publish(topic, msg);


}