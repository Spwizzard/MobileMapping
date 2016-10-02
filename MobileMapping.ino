#include "get_ultrasonic.h"
#include "find_corner.h"
#include "irobot_serial.h"

void setup() {
  serial_setup();
}

void loop() {
  find_corner();
  Serial.
}
