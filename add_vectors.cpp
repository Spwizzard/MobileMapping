#include "find_corner.h"
#include "add_vectors.h"
#include <math.h>

/**
 * adds an array of vectors
 * Precondition: all angles must be in degrees
 * @param vectors an array of Vector structures to add into one resultant vector
 * @param length the length of the vectors array (can calculate as sizeof(vectors)/sizeof(vectors[0]))
 * @return the resultant vector from adding all the vectors in the vectors array (angle of resultant vector will be in degrees)
 */
struct Vector add_vectors(struct Vector vectors[], int length) {
	struct Vector resultant_vector;
	resultant_vector.distance = 0;
	resultant_vector.angle = 0;

	// parse through the array of vectors and add each to the resultant to find the total resultant
	for (int i = 0; i < length; i++) {
		resultant_vector = add_two_vectors(resultant_vector, vectors[i]);
	}

	return resultant_vector;
}

/**
 * adds two vectors together to get one resultant vector
 * Precondition: all angles must be in degrees
 * @param v1 a Vector struct to be added
 * @param v2 another Vector struct to be added
 * @return the resultant vector from adding Vectors v1 and v2 (angle of resultant vector will be in degrees)
 */
struct Vector add_two_vectors(struct Vector v1, struct Vector v2) {
	struct Vector resultant_vector;

	// calculate coordinates of resultant vector
	double x1 = v1.distance * cos(v1.angle * TO_RADIANS);
	double y1 = v1.distance * sin(v1.angle * TO_RADIANS);

	// calculate coordinates of current vector
	double x2 = v2.distance * cos(v2.angle * TO_RADIANS);
	double y2 = v2.distance * sin(v2.angle * TO_RADIANS);

	// sum x and y parts
	double x = x1 + x2;
	double y = y1 + y2;

	printf("%f, %f, %f, %f\n", x1,y1,x2,y2);

	// set the new resultant vector
	resultant_vector.distance = (int) rint(sqrt((x*x) + (y*y)));
	resultant_vector.angle = (int) rint(atan2(y, x) * TO_DEGREES);

	return  resultant_vector;
}


