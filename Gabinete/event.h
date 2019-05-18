#ifndef _EVENT_H
#define _EVENT_H
#include <stdio.h>
#include <string.h>

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

typedef struct{
  uint8_t door_event_flag       :1;
  uint8_t dps_event_flag        :1;
  uint8_t energy_event_flag     :1;
  uint8_t relay1_flag           :1;
  uint8_t relay2_flag           :1;
  uint8_t reboot_flag           :1;
}SystemEvent; 
#define door_event_flag             eventflags.door_event_flag 
#define dps_event_flag              eventflags.dps_event_flag         
#define energy_event_flag           eventflags.energy_event_flag      
#define relay1_flag                 eventflags.relay1_flag            
#define relay2_flag                 eventflags.relay2_flag            
#define reboot_flag                 eventflags.reboot_flag 
extern SystemEvent eventflags;

#endif
