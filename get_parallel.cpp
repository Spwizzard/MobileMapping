#include "irobot_serial.h"
#include "get_ultrasonic.h"
#include <Arduino.h>

void get_parallel() {
  
  float sensorL = get_ultrasonic(CM,'L');
  float sensorR = get_ultrasonic(CM,'R');
  while((sensorR - sensorL) < .1 && (sensorR - sensorL) > -.1){
    
    if((sensorR - sensorL) > 0){
    serial_drive(100,CLOCKWISE);
    delay(100);
    sensorL = get_ultrasonic(CM,'L');
    sensorR = get_ultrasonic(CM,'R');
    }
    else{
    serial_drive(100,COUNT_CLOCKWISE);
    delay(100);
    sensorL = get_ultrasonic(CM,'L');
    sensorR = get_ultrasonic(CM,'R');
    }
  
  serial_drive(0,-90);   
  }
}

