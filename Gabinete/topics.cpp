#include "topics.h"
const topics_receive_struct topics_rx_labels={
    COMPANY"/"CLIENT_ID"/RELAY1/STATE",
    COMPANY"/"CLIENT_ID"/RELAY2/STATE",
    COMPANY"/"CLIENT_ID"/RELAY1/ACTIVE_TIME",
    COMPANY"/"CLIENT_ID"/RELAY2/ACTIVE_TIME",
    COMPANY"/"CLIENT_ID"/REBOOT/MODE",
    COMPANY"/"CLIENT_ID"/ENERGY/TIMEOUT",
  };
  
 const  topics_transmit_struct topics_tx_labels={
    COMPANY"/"CLIENT_ID"/DPS/STATE",
    COMPANY"/"CLIENT_ID"/ENERGY/STATE",
    COMPANY"/"CLIENT_ID"/DOOR/STATE",
  };