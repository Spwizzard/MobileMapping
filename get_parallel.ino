#include <iRobotSerial.h>
//#include "get_ultrasonic"

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
//for direction - true = clockwise, false = counterclockwise
void move_parallel(boolean direction) {
  int type;
  float sensorL = get_ultrasonic(type,'L');
  float sensorR = get_ultrasonic(type,'R');
  while((sensorR - sensorL) < .1 && (sensorR - sensorL) > -.1){
    if((sensorR - sensorL) > 0){
    serialDrive(0,1); 
    }
    else{
    serialDrive(0,-1);
    }
  if(direction){
  serialDrive(0,-90);  
  }
  else{
  serialDrive(0,90);  
  }  
}
}

