/////////////////////////////////////////////////////
void readDHTData(){
  char temp[10];
  dtostrf(dht.readTemperature(), 4, 1, temp); //Read temperature to char array
  char hum[10];
  dtostrf(dht.readHumidity(), 4, 1, hum);//Read humidity to char array
  delay(500);
  sprintf(msg, "{\"temp\": %s, \"hum\": %s}", temp, hum); //format to json
  Serial.println(msg);
}

/////////////////////////////////////////////////////
void sendDHTData() {
  driver.send((uint8_t *)msg, strlen(msg)); //send the message as bytes
  driver.waitPacketSent();
  Serial.print("Message sent: ");
  Serial.println(msg);
  Serial.flush();
}
