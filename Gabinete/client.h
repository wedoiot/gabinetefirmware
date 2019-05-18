#ifndef _MQTT_CONFIG_H
#define _MQTT_CONFIG_H

#include "topics.h"

void MQTT_Client_init();
typedef enum{
    MQTT_DISCONNECT,
    MQTT_CONNECT_SUCCESS
}Mqtt_conection;
Mqtt_conection MQTT_Check_Connect();
void MQTT_Publish(const char * topic, PROGMEM byte *payload);
#endif
