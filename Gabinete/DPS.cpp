#include "DPS.h"

void dps_management(){
   if (digitalRead(DPSSensorPin)==HIGH && gabineteData.dps==DPS_NORMAL ){
      MQTT_Publish(topics_tx_labels.door, "FAILURE");
      Serial.println(F("DPS FAILD"));
      gabineteData.dps=FAILURE;
    }if (digitalRead(DPSSensorPin)==LOW && gabineteData.dps==FAILURE ){
      MQTT_Publish(topics_tx_labels.dps, "NORMAL");
      Serial.println(F("DPS FIXED"));
      gabineteData.dps=DPS_NORMAL;
    }
}
