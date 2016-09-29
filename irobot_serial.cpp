#include "irobot_serial.h"
#include <Arduino.h>
#include <stdint.h>
#include <SoftwareSerial.h>

SoftwareSerial softSerial = SoftwareSerial(rxPin, rxPin);

void serial_setup() {
  // set pin modes
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  // start SoftwareSerial port at baud 57600 (iRobot default)
  softSerial.begin(57600);

  // starts iRobot OI
  softSerial.write(128);
  // set mode to safe
  softSerial.write(131);
}

void serial_out(int opcode, unsigned char sequence[]) {
  softSerial.write(opcode);
  for(int i = 0; i < (sizeof(sequence)/sizeof(int)); i++) {
    softSerial.write(sequence[i]);
  }
}

void serial_drive(int velocity, int radius) {
  unsigned char sequence[4];
  sequence[0] = (unsigned char)(velocity >> 8);
  sequence[1] = (unsigned char)velocity;
  sequence[2] = (unsigned char)(velocity >> 8);
  sequence[3] = (unsigned char)radius;
  serial_out(137, sequence);
}

void serial_read(unsigned char packID, unsigned char sequence[], int len) {
  unsigned char id[] = {packID};
  serial_out(142, id);
  delay(250);
  
  int avail = softSerial.available();
  // should NOT happen
  if(avail < len) {
    len = avail;
  }
  
  for(int i = 0; i < len; i++) {
    sequence[i] = softSerial.read();
  }
}

int serial_16_read(unsigned char packID) {
  unsigned char sequence[2];
  serial_read(packID, sequence, 2);

  //                      low                      high
  int16_t val = (int16_t)(sequence[1]) | (int16_t)(sequence[0] << 8);
  return (int) val;
}

