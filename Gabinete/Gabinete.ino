//#include <Ethernet.h>
#include "DPS.h"
#include "relay.h"
#include "energy.h"
#include "door.h"
#include "GPIO.h"

long previousMillis;

/*---------------------*
 * ISR FOR DPSSENSOR *
 *---------------------*//*
void DPSCallback(void){
  dps_event_flag=1;
}
*/
void setup()
{
  Serial.begin(115200);
  #ifdef DEBUG_ENABLE
    Serial.println(F("System reboot"));
  #endif
  previousMillis = millis();
  MQTT_Client_init();
  GPIO_init();
  previousMillis = millis();
}

void process_manager(){
  door_management();
  dps_management();
  energy_management();
  relay_management();
}
void loop()
{
  static uint8_t reconnect_counter=0;
  if(MQTT_Check_Connect()==MQTT_DISCONNECT){
    #ifdef DEBUG_ENABLE
      Serial.println(F("Try to reconnect"));
    #endif
    
    if(gabineteData.reboot.mode==AUTOMATIC){
      reconnect_counter++;
      if(reconnect_counter==MAX_RECONNECT_EVENT_BEFORE_RESTART){
        #ifdef DEBUG_ENABLE
          Serial.println(F("RELAY1 TURN OFF AUTOMATIC for reboot"));
        #endif
        digitalWrite(Relay1Pin,RELAY_ON);
        gabineteData.relay1.state=ON;
        gabineteData.relay1.remain_time=gabineteData.relay1.active_time;
        relay1_flag=1;
        reconnect_counter=0;
      }
    }
    delay(5000);
  }
  /* check interval*/
  if(millis() - previousMillis > INTERVAL_SAMPLE) {
    process_manager();
    last_spend_time= millis() - previousMillis;
    previousMillis = millis();
  }
}
