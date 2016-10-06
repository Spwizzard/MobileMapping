#ifndef GETULTRASONIC_H_
#define GETULTRASONIC_H_

////////////////////////////////////////////////////////////////////////////////
//            SOME PREPROCESSOR DEFINES
////////////////////////////////////////////////////////////////////////////////
//These are the pins to use for Output and Input
//We'll almost certainly have to change these, these are just placeholders
#define OUT_PIN_R 2
#define IN_PIN_R  3
#define OUT_PIN_L 4
#define IN_PIN_L  5

// define options for return values
// We'll use these when we call get_ultrasonic
// We'll calculate dist in mm, then use these values as
// conversion factors
#define MM 1
#define CM 10
#define M  1000

float get_ultrasonic(int type, char side);
void ultrasonic_setup();

#endif
