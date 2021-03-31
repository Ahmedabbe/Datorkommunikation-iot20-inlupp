/////////////////////////////////////////////////////
void manageData(){
  uint8_t incMsg[64]; //incoming rf433 message
  uint8_t incMsgLen = sizeof(incMsg);
  
  if(driver.recv(incMsg, &incMsgLen)){ //if a rf433 message is received, deserialize
    DynamicJsonDocument jsonBuffer(1024); 
    deserializeJson(jsonBuffer, incMsg);
    
    float temp = jsonBuffer["temp"]; //extract temp value
    
    if(checkTempDiff(temp)){ //check if temp change warrants iothub update
      char payload[64];
      serializeJson(jsonBuffer, payload); //reserialize message for upload
  
      sendIotMessage(payload);
      
    }else{
      Serial.println("Awaiting significant change in temp reading..");
      delay(4000);
    }
  }
}
/////////////////////////////////////////////////////
void sendIotMessage(char* payload){
  if(_connected){
      Esp32MQTTClient_SendEvent(payload);
      Serial.print("Payload sent: ");
      Serial.println(payload);
  }
}

/////////////////////////////////////////////////////
bool checkTempDiff(float currentTemp) {
  if (currentTemp == 0) return false;
  if (currentTemp < (prevTemp - DIFF) || currentTemp > (prevTemp + DIFF)) { //check if temp difference exceedes 0.5
    prevTemp = currentTemp;
    return true;
  }
  return false;
}
