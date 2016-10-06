#ifndef ADDVECTORS_H_
#define ADDVECTORS_H_

#define TO_RADIANS PI/180
#define TO_DEGREES 180/PI

#include "find_corner.h"

/**
 * adds two vectors together to get one resultant vector
 * Precondition: all angles must be in degrees
 * @param v1 a Vector struct to be added
 * @param v2 another Vector struct to be added
 * @return the resultant vector from adding Vectors v1 and v2 (angle of resultant vector will be in degrees)
 */
Vector add_two_vectors(Vector v1, Vector v2);

/**
 * adds an array of vectors
 * Precondition: all angles must be in degrees
 * @param vectors an array of Vector structures to add into one resultant vector
 * @param length the length of the vectors array (can calculate as sizeof(vectors)/sizeof(vectors[0]))
 * @return the resultant vector from adding all the vectors in the vectors array (angle of resultant vector will be in degrees)
 */
Vector add_vectors(Vector vectors[], int length);

#endif
