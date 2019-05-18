
#include "door.h"

void door_management(){
  if(door_event_flag==1){
    door_event_flag=0;
    delay(50);//debounce no is recomended ISR 
    if (digitalRead(DoorSensorPin)==DOOR_OPEN_LEVEL){
      //mqttClient.publish(topics_tx_labels.door, "OPEN");
      MQTT_Publish(topics_tx_labels.door, "OPEN");
      Serial.println(F("DOOR OPEN"));
    }else{
      //mqttClient.publish(topics_tx_labels.door, "CLOSE");
      MQTT_Publish(topics_tx_labels.door, "CLOSE");
      Serial.println(F("DOOR CLOSE"));
    }
  }
}
