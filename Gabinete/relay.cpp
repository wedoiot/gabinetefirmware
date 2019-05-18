#include "relay.h"

void relay_management(){
    if(relay1_flag==1 && gabineteData.relay1.mode==MOMENTARY){
      gabineteData.relay1.remain_time-=last_spend_time;
      if(gabineteData.relay1.remain_time<=0){
        digitalWrite(Relay1Pin,RELAY_OFF);
        gabineteData.relay1.remain_time=gabineteData.relay1.active_time;
        gabineteData.relay1.state=OFF;
        Serial.println(F("RELAY1 TURN OFF AUTOMATIC"));
        relay1_flag=0;
      }
    }
    if(relay2_flag==1 && gabineteData.relay2.mode==MOMENTARY){
      gabineteData.relay2.remain_time-=last_spend_time;
      if(gabineteData.relay2.remain_time<=0){
        digitalWrite(Relay2Pin,RELAY_OFF);
        gabineteData.relay2.remain_time=gabineteData.relay2.active_time;
        gabineteData.relay2.state=OFF;
        Serial.println(F("RELAY2 TURN OFF AUTOMATIC"));
        relay2_flag=0;
      }
    }
}
