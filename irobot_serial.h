#ifndef IROBOTSERIAL_H_
#define IROBOTSERIAL_H_

// serial pin to read from
#define rxPin -1
// serial pin to write on
#define txPin -1
// special case values in irobot documentation for radius
#define CLOCKWISE 0xFFFF
#define COUNT_CLOCKWISE 1
#define STRAIGHT 0x8000

// packID of distance and angle sensor
#define DISTANCE_READ 19
#define ANGLE_READ 20

// setup of pins, etc.
void serial_setup();

// send command to iRobot with opcode followed by sequence of bytes
void serial_out(int opcode, unsigned char sequence[]);

/*  tell iRobot to drive 
 *  int velocity - velocity to drive at (-500 - 500 mm/s)
 *  int radius - radius to turn around (-2000 - 2000 mm)
 *   special values of radius:
 *   CLOCKWISE - turn in place clockwise
 *   COUNT_CLOCKWISE - turn in place counter clockwise
 *   STRAIGHT - head in a straight line
 */
void serial_drive(int velocity, int radius);

/*  request data from sensor
 *  unsigned char packID - the packet ID of the sensor to read from
 *  unsigned char[] sequence - an array to fill with the returned data
 *  int len - the number of bytes to read
 *  modifies unsigned char[] sequence
 *    the stream of bytes that was read in by the sensor
 */
void serial_read(unsigned char packID, unsigned char sequence[], int len);

/*  request data from sensor formatted as 16 bit int
 *  unsigned char packID - the packetID of the sensor to read from
 *    DISTANCE_READ - read the distance traveled
 *    ANGLE_READ - read the ange turned
 *  returns the value returned by the sensor (read as a 16 bit signed int)
 */
int serial_16_read(unsigned char packID);

#endif
