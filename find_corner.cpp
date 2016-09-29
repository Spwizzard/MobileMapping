#include "find_corner.h"
#include "irobot_serial.h"
#include "forward_move.h"

#define MIN_DIST 10 //10 cm

//find_corner function
Vector find_corner(){
    
  serial_16_read(DISTANCE_READ); //setting initial distanceTravelled to 0.
  //forward_move(MIN_DIST);
  int distanceTraveled = serial_16_read(DISTANCE_READ); 
  //returning the distanceTravelled during forward_move();
  //storing distanceTravelled in variable
  
  serial_16_read(ANGLE_READ);   //setting initial changeInAngle to 0.
  //move_parallel();
  int changeInAngle = serial_16_read(ANGLE_READ);  
  //returning the changeInAngle during move_parallel();
  //storing changeInAngle in variable

  Vector traveled;
  traveled.distance = distanceTraveled;
  traveled.angle = changeInAngle;
  return traveled; // returning stored values in Vector struct.
}
