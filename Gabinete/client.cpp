//#include <Ethernet.h>
#include <UIPEthernet.h>
#include <PubSubClient.h>
#include "topics.h"
#include "client.h"
#include "credentials.h"
EthernetClient ethClient;
PubSubClient mqttClient(ethClient);

/*callback when arrive a new messages in some subscribed topic*/
void callback(char* topic, byte* payload, unsigned int length) {
  int32_t data=0;
  unsigned int i=0;
  Serial.print(F("Message arrived ["));
  Serial.print(topic);
  Serial.print("] ");
  /*process payload acordly with the topic arrived*/
  if (strcmp(topic,topics_rx_labels.relay1)==0){
    if(payload[0]=='O'&& payload[1]=='N'){
        digitalWrite(Relay1Pin,RELAY_ON);
        gabineteData.relay1.state=ON;
        Serial.print(F("RELAY1:ON"));
        relay1_flag=1;
    }else if(payload[0]=='O'&&payload[1]=='F' && payload[2]=='F'){
        digitalWrite(Relay1Pin,RELAY_OFF);
        gabineteData.relay1.state=OFF;
        Serial.print(F("RELAY1:OFF"));
    }  
  }else if(strcmp(topic,topics_rx_labels.relay2)==0){
    if(payload[0]=='O'&& payload[1]=='N'){
        digitalWrite(Relay2Pin,RELAY_ON);
        gabineteData.relay2.state=ON;
        relay2_flag=1;
    }else if(payload[0]=='O'&&payload[1]=='F' && payload[2]=='F'){
        digitalWrite(Relay2Pin,RELAY_OFF);
        gabineteData.relay2.state=OFF;
    }  
  }else if(strcmp(topic,topics_rx_labels.relay1_active_time)==0){
    data=0;
    for (i=0;i<length;i++) {
      Serial.print((char)payload[i]);
      data+=(payload[i]-0x30)*pow(10,(length-i-1)); 
    }
    Serial.print(data);
    gabineteData.relay1.active_time=data;
    gabineteData.relay1.remain_time=data;
  }else if(strcmp(topic,topics_rx_labels.relay2_active_time)==0){
    data=0;
    for (i=0;i<length;i++) {
      Serial.print((char)payload[i]);
      data+=(payload[i]-0x30)*pow(10,(length-i-1)); 
    }
    gabineteData.relay2.active_time=data;
    gabineteData.relay2.remain_time=data;
  }else if(strcmp(topic,topics_rx_labels.reboot_mode)==0){
    if(strcmp(payload,"MANUAL")==0){
        gabineteData.reboot.mode=MANUAL;
    }else if(strcmp(payload,"AUTOMATIC")==0){
        gabineteData.reboot.mode=AUTOMATIC;
    }  
  }else if(strcmp(topic,topics_rx_labels.energy_timeout)==0){
    data=0;
    for (i=0;i<length;i++) {
      Serial.print((char)payload[i]);
      data+=(payload[i]-0x30)*pow(10, i);
    }
    gabineteData.energy.timeout=data;
  }
}
  
void MQTT_Client_init(){
  if (Ethernet.begin(mac) == 0) {
    Serial.println(F("Failed to configure Ethernet using DHCP"));
  }
  mqttClient.setClient(ethClient);
  mqttClient.setServer(MQTT_BROKER_IP, MQTT_PORT);
  mqttClient.setCallback(callback);

}


Mqtt_conection MQTT_Check_Connect(){
  Mqtt_conection MQTT_State;
  /*check if client MQTT is connected*/
  MQTT_State=MQTT_CONNECT_SUCCESS;
  if (!mqttClient.connected()) {
      Serial.print(F("Connecting ..."));
      MQTT_State=MQTT_DISCONNECT;
      //se puede utilizar para hacer el reinicio automatico despues de intentarse conectar 12 veces 1 min
      if (mqttClient.connect(CLIENT_ID,MQTT_USER,MQTT_PASSWORD)) {
        Serial.println(F("connected"));
        mqttClient.subscribe(topics_rx_labels.relay1);
        mqttClient.subscribe(topics_rx_labels.relay2);
        mqttClient.subscribe(topics_rx_labels.relay1_active_time);
        mqttClient.subscribe(topics_rx_labels.relay2_active_time);
        mqttClient.subscribe(topics_rx_labels.reboot_mode);
        mqttClient.subscribe(topics_rx_labels.energy_timeout);
        MQTT_State=MQTT_CONNECT_SUCCESS;
      } 
  }else{
    mqttClient.loop();
  }
  return MQTT_State;
}
void MQTT_Publish(const char * topic, PROGMEM byte *payload){
    mqttClient.publish(topic,payload);
  }
