#ifndef _TOPICS_H
#define _TOPICS_H  
#include "config.h"

  typedef struct{
    char *relay1;
    char *relay2;
    char *relay1_active_time;
    char *relay2_active_time;
    char *reboot_mode;
    char *energy_timeout;
  }topics_receive_struct;  

extern const topics_receive_struct topics_rx_labels;
extern const topics_transmit_struct topics_tx_labels;
  #endif
