#include "find_corner.h"
#include "irobot_serial.h"
#include "forward_move.h"
#include "get_parallel.h"
#include <Arduino.h>

#define MIN_DIST 30 //e is 30 cm

//find_corner function
Vector find_corner(){

  int starttime;
  starttime = millis();
  forward_move(MIN_DIST);
  int distanceTraveled = (millis() - starttime) / 10;
  //returning the distanceTravelled during forward_move();
  //storing distanceTravelled in variable

  int changeInAngle = get_parallel();
  //returning the changeInAngle during move_parallel();
  //storing changeInAngle in variable

  Vector traveled;
  traveled.distance = distanceTraveled;
  traveled.angle = changeInAngle;
  return traveled; // returning stored values in Vector struct.
}
