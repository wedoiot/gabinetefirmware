  #include "GPIO.h"

  void GPIO_init(){
    pinMode(DoorSensorPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(DoorSensorPin), DoorOpenCallback, CHANGE);
    pinMode(DPSSensorPin, INPUT_PULLUP);
    pinMode(EnergySensorPin,INPUT_PULLUP );
    pinMode(Relay1Pin, OUTPUT);
    pinMode(Relay2Pin, OUTPUT);

    //attachInterrupt(digitalPinToInterrupt(DoorSensorPin), DoorOpenCallback, CHANGE);
  }

  /*---------------------*
 * ISR FOR DOOR SENSOR *
 *---------------------*/
void DoorOpenCallback(void){
  door_event_flag=1;
}
