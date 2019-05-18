#ifndef _PIN_OUT_H
#define _PIN_OUT_H
/*---------------------------------------------------------------------------
 | BOARD                             |  Pin  | Configurate as
 |-----------------------------------|--------------------------------------|
 | Door                              |   2   | Input and enable interrupt   |
 | DPS                               |   3   | Input and enable interrupt   |
 | Energy detect                     |   4   | Input                        |
 | Relay1                            |   5   | output                       |
 | Relay2                            |   6   | output                       |
 *---------------------------------------------------------------------------
*/
/*Pin asigment*/
#include "event.h"

const uint8_t DoorSensorPin          = 3;
const uint8_t DPSSensorPin           = 7;
const uint8_t EnergySensorPin        = 4;
const uint8_t Relay1Pin              = 5;
const uint8_t Relay2Pin              = 6;
  void GPIO_init();
  void DoorOpenCallback(void);
#endif
