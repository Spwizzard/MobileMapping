#include <Arduino.h>
#include "forward_move.h"
#include "get_ultrasonic.h"
#include "irobot_serial.h"

//returns int, may not be the right data type
int forward_move(int e) {
  int wall_1 = (int)get_ultrasonic(CM, 'L');
  int wall_2 = (int)get_ultrasonic(CM, 'R');//wall_1 and wall_2 are the distances from the wall as measured by the left and right sensors, respectively
  
  while(wall_1 > e && wall_2 > e){//e is the pre-determined distance from the wall in cm
    serial_drive(VELOCITY, STRAIGHT);
    delay(500 * e / VELOCITY);//waits for the robot to move e/2 cm before calling get_ultrasonic again
    wall_1 = (int)get_ultrasonic(CM, 'L');
    wall_2 = (int)get_ultrasonic(CM, 'R');//finds new wall_1 and wall_2 values after the robot has moved
  }
  serial_drive(0, STRAIGHT);//stops the robot once it comes within e cm of the wall

  //still need to return distance traveled, there is no serialGetDistance method
}
