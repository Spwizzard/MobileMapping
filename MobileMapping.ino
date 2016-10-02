#include "get_ultrasonic.h"
#include "find_corner.h"
#include "irobot_serial.h"
#include "get_parallel.h"
#include "forward_move.h"
#include "add_vectors.h"

Vector vector;
Vector origin;
Vector resultant_vector;

int state = 0;

void setup() {
  serial_setup();
}

void loop() {
  switch(state)
  {case 0: forward_move(15); 
           get_parallel();
           forward_move(15);
           state++;
           break;
   case 1: origin;
           origin.distance = origin.angle = 0;
           vector = find_corner();
           resultant_vector = add_two_vectors(origin,vector);
           state++;
           break;
   case 2: vector = find_corner();
           resultant_vector = add_two_vectors(resultant_vector, vector);
           if(abs(resultant_vector.distance) < 0.5) {
            state++;
           }
           break;
  }
}
