/////////////////////////////////////////////////////
void initWifi(){
  Serial.print("Connecting to WiFi. Please wait.");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi initialized");
}

/////////////////////////////////////////////////////
void initIothub(){
  if(!Esp32MQTTClient_Init((const uint8_t *) connectionString)){
    _connected = false;
    return;
  }
  _connected = true;
}
