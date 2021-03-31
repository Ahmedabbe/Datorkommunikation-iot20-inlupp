#include <ArduinoJson.h>
#include <RH_ASK.h>
#include <SPI.h>
#include <WiFi.h>
#include <Esp32MQTTClient.h>

#define DIFF 0.5 // 
float prevTemp = 0; // for saving last uploaded temp

#define WIFI_SSID "ändra"
#define WIFI_PASS "ändra"
static char* connectionString = "HostName=AhmedAlhasaniIOT20.azure-devices.net;DeviceId=esp32;SharedAccessKey=rEQbiEEJYH0BQW+Y0Y+9mbxcs27f1n16SQpEB49nP7o=";
static bool _connected = false;

RH_ASK driver(2000, 4, 5, 0); //radiohead setup

/////////////////////////////////////////////////////
void setup() {
  Serial.begin(115200);
  delay(500);
  initWifi();
  driver.init();
  initIothub();
}

void loop() {
  manageData();
}
