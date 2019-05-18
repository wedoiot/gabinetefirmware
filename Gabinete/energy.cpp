#include "energy.h"

void energy_management(){
 switch(gabineteData.energy.state){
    case(NORMAL):
      if(digitalRead(EnergySensorPin)==ENERGY_FAIL_LEVEL){
        //the system will be waiting N seconds while  the seccionalizator reconect the energy flow
        gabineteData.energy.state=TEMPORARY_FAILURE;
        gabineteData.energy.remain_time_for_alert=gabineteData.energy.timeout;
      }
    break;
    case(TEMPORARY_FAILURE):
      gabineteData.energy.remain_time_for_alert-=last_spend_time;
      if(gabineteData.energy.remain_time_for_alert<=0){
        gabineteData.energy.state=CRITICAL_FAILURE;
        //mqttClient.publish(topics_tx_labels.energy_state,"CRITICAL_FAILURE");
        MQTT_Publish(topics_tx_labels.energy_state,"CRITICAL_FAILURE");
        Serial.println(F("ENERGY CRITICAL"));
      }else if(digitalRead(EnergySensorPin)!=ENERGY_FAIL_LEVEL){
        gabineteData.energy.state=NORMAL;
        Serial.println(F("ENERGY FAILED but dont worry!"));
        }
    break;
    case(CRITICAL_FAILURE):
      if(digitalRead(EnergySensorPin)!=ENERGY_FAIL_LEVEL){
        gabineteData.energy.state=NORMAL;
        //mqttClient.publish(topics_tx_labels.energy_state,"NORMAL");
        MQTT_Publish(topics_tx_labels.energy_state,"NORMAL");
        Serial.println(F("ENERGY RETURN TO NORMAL STATE"));
      }
    break;
  }
}
