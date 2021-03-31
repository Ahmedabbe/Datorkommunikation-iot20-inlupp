#include <DHT.h>
#include <RH_ASK.h>
#include <SPI.h>
#include <string.h>

#define DHT_PIN 13
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);
RH_ASK driver(2000, 11, 12, 0);

char msg[64];

void setup() {
  Serial.begin(115200);
  dht.begin();
  driver.init();
}

void loop() {
  readDHTData();
  sendDHTData();
  delay(1500);
}
