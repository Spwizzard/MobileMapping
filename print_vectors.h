#ifndef PRINTVECTORS_H_
#define PRINTVECTORS_H_

/**
 * Prints out the x and y coordinates for each point in the array of vectors where the would be in a coordinate plane given they are in order
 * outputs as  (x,y)
 * Precondition: vector andlges must be in degrees
 * @param v the array of vectors to find the points in
 * @param length the length of the array of vectors (can calculate as sizeof(v)/sizeof(v[0]))
 */
void print_vectors(struct Vector v[], int length);

#endif
