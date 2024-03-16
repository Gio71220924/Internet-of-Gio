// auth dashboard blynk lihat di dashboard
#define BLYNK_TEMPLATE_ID "TMPL6lDuO6Jvu"
#define BLYNK_TEMPLATE_NAME "Blynk"
#define BLYNK_AUTH_TOKEN "cev188B-iI-yukYnz_BkqveK0pqleizr"

// wifi esp dan blynk library
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
#include "DHT.h"

#define DHTPIN 4    //Masukin ke D2 di arduinonya
#define DHTTYPE DHT11 


// ssid pass untuk setting wifi
DHT dht(DHTPIN, DHTTYPE);
char ssid[] = "Redmi10S";   //sesuai kan sama SSID dan password, bisa pake Hotspot
char pass[] = "steve007";


void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(750);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
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

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  Blynk.virtualWrite(V5, t);    //Samain kek di datastream Blynknya.
  Blynk.virtualWrite(V6, h);
  Blynk.virtualWrite(V7, hic);
  Blynk.run();
}
