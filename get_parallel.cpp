#include "irobot_serial.h"
#include "get_ultrasonic.h"
#include <Arduino.h>

float get_parallel() {
  
  float sensorL = get_ultrasonic(CM,'L');
  float sensorR = get_ultrasonic(CM,'R');
  float angle = 90;
  while(abs(sensorR - sensorL) > 0.1) {
    if((sensorR - sensorL) > 0){
      serial_drive(20,COUNT_CLOCKWISE);
      delay(20);
      sensorL = get_ultrasonic(CM,'L');
      sensorR = get_ultrasonic(CM,'R');
      angle -= 0.273;
    }
    else{
      serial_drive(20,CLOCKWISE);
      delay(20);
      sensorL = get_ultrasonic(CM,'L');
      sensorR = get_ultrasonic(CM,'R');
      angle += 0.273;
    }
  }
  serial_drive(20, CLOCKWISE);
  delay(6600);
  serial_drive(0,0);
  return angle;
}

