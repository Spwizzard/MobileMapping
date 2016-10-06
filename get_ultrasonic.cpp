#include <Arduino.h>
#include "get_ultrasonic.h"

////////////////////////////////////////////////////////////////////////////////
//
//                          usec_to_mm
//
//  @param uSec:  This is number of microseconds.
//  @return:      The expected distance in mm as a float assuming that the 
//                speed of sound in air is 343.2 m/s.
//
////////////////////////////////////////////////////////////////////////////////
float usec_to_mm(long uSec){
  return (uSec / 2.91) / 2;
}

void ultrasonic_setup() {
  //configure pins, making sure each time they are right
  pinMode(OUT_PIN_R, OUTPUT);
  pinMode(IN_PIN_R,  INPUT);
  pinMode(OUT_PIN_L, OUTPUT);
  pinMode(IN_PIN_L, INPUT);
}

////////////////////////////////////////////////////////////////////////////////
//
//                          get_ultrasonic
//
//  @param type:  This is the factor by which we'll divide our result. Result 
//                starts in mm, then we divide by type to get desired units.
//  @param side:  This should be either 'L' or 'R' (left or right respectively)
//                Refers to which side the sensor is on. 
//
//  @return:  -1.0 if we got no response from the sensor. Indicates some error
//            else, we return perceived distance in specified units as a float
//
////////////////////////////////////////////////////////////////////////////////
float get_ultrasonic(int type, char side){
  int nInPin, nOutPin;
  long lDuration;

  // Decide on the pins
  if(side == 'L'){
    nInPin  = IN_PIN_L;
    nOutPin = OUT_PIN_L;
  }else if(side == 'R'){
    nInPin  = IN_PIN_R;
    nOutPin = OUT_PIN_R;
  }
  
  digitalWrite(nOutPin, LOW);
  delayMicroseconds(2);
  digitalWrite(nOutPin, HIGH);  // send the signal to trigger ultrasonic pulse
  delayMicroseconds(5);
  digitalWrite(nOutPin, LOW);

  lDuration = pulseIn(nInPin, HIGH);  //looking for a HIGH signal from this pin
  if(lDuration <= 0){
    return -1.0;
  }else{
    return usec_to_mm(lDuration) / type;
  }
}
