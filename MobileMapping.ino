#include "get_ultrasonic.h"
#include "find_corner.h"
#include "irobot_serial.h"
#include "get_parallel.h"
#include "forward_move.h"
#include "add_vectors.h"
#include "print_vectors.h"

Vector resultant_vector;
Vector vectors[10];
int i = 0;

int state = 0;

void setup() {
  Serial.begin(9600);
  serial_setup();
  ultrasonic_setup();
}

void loop() {
  switch(state) {
    case 0:
           forward_move(30);
           get_parallel();
           forward_move(30);
           get_parallel();
           state++;
           break;
   case 1:
           vectors[i] = find_corner();
           Serial.print(vectors[i].distance);
           Serial.print(",");
           Serial.print(vectors[i].angle);
           Serial.print("\n");
           print_vectors(vectors, i + 1);
           resultant_vector = add_vectors(vectors, i + 1);
           if(abs(resultant_vector.distance) < 0.5) {
            state++;
           }
           i++;
           break;
  }
}
