#ifndef _CONFIG_H
#define _CONFIG_H
#include <stdio.h>
#include <string.h>
#include "GPIO.h"

#define DEBUG_ENABLE
/*Direccion MAC*/

const uint8_t mac[] =       { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 };
#define MQTT_BROKER_IP      "192.168.1.4"
#define MQTT_PORT           1883
#define SERIAL_DEBUG        1
#define CLIENT_ID           "GAB1"
#define COMPANY             "ESO"
#define MAX_RECONNECT_EVENT_BEFORE_RESTART 3 //20

#define RELAY_ON_TIME_MS          5000 
#define INTERVAL_SAMPLE           100 // 1 sec delay between publishing
#define ENERGY_FAIL_LEVEL         HIGH
#define DPS_FAIL_LEVEL            HIGH
#define DOOR_OPEN_LEVEL           HIGH
#define RELAY_ON                  HIGH
#define RELAY_OFF                 LOW
#define ENERGY_CRITICAL_TIME      18000 //5 second       

  typedef struct{
    char *dps;
    char *energy_state;
    char *door;
  }topics_transmit_struct;

  typedef enum{
    OFF,
    ON
  }RelayState;

  typedef enum{
    MOMENTARY,
    FIX
  }RelayMode;

  typedef enum{
    DPS_NORMAL,
    FAILURE
  }DPSState;    

  typedef enum{
    CLOSE,
    OPEN
  }DoorState;  

  typedef enum{
    NORMAL,
    TEMPORARY_FAILURE,
    CRITICAL_FAILURE
  }EnergyState;

  typedef enum{
    MANUAL,
    AUTOMATIC
  }RebootMode; 
    
  typedef struct{
    int32_t      timeout;
    int32_t      remain_time_for_alert;
    EnergyState   state;
  }EnergyInfo;
      
  typedef struct{
    RebootMode    mode;
  }RebootInfo;  
  
  typedef struct{
    int32_t      active_time;
    int32_t      remain_time;
    RelayMode     mode;
    RelayState    state;
  }RelayInfo;   
  
  typedef struct{
    RelayInfo     relay1;
    RelayInfo     relay2;
    DPSState      dps;
    DoorState     door;
    EnergyInfo    energy;
    RebootInfo    reboot;
  }data_str ;

extern data_str gabineteData;
extern unsigned long last_spend_time;
#endif
