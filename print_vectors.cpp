#include <math.h>
#include <stdio.h>
#include <Arduino.h>
#include "add_vectors.h"

/**
 * Prints out the x and y coordinates for each point in the array of vectors where the would be in a coordinate plane given they are in order
 * outputs as (x,y)
 * Precondition: vector andlges must be in degrees
 * @param v the array of vectors to find the points in
 * @param length the length of the array of vectors (can calculate as sizeof(v)/sizeof(v[0]))
 */
void print_vectors(struct Vector v[], int length) {
	// print all of the points on the coordinate place from an array of vectors

	// create default resultant vector
	struct Vector resultant;
	resultant.distance = 0;
	resultant.angle = 0;

	// print out the origin point
	Serial.print("(0,0)\n"); // we may decide this is unnecessary if the last point should be 0,0 too due to the robot coming full circle

	// get the coordinates at each point by printing the x and y coordinates after each vector in the array is added to a resultant vector
	for (int i = 0; i < length; i++) {
		// get the current resultant vector
		resultant = add_two_vectors(resultant, v[i]);

		// get x coord of resultant
		int x = (int) lrint(resultant.distance * cos(resultant.angle * TO_RADIANS));

		// get y coord of resultant
		int y = (int) lrint(resultant.distance * sin(resultant.angle * TO_RADIANS));

		// print the coordinates
		Serial.print("(");
		Serial.print(x);
		Serial.print(",");
		Serial.print(y);
		Serial.print(")\n");
	}
}
