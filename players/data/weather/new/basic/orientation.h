/*
    basic/orientation.h - orientation constants definitions
    Jan 1992 by marion@cs.tu-berlin.de
    -- rewritten (using <orientation.h> and enlarged by Ugh -- May-18-1998)
*/

#ifndef _basic_orientation_h
#define _basic_orientation_h

#include <orientation.h>

#define ORIENTATION_LONG \
  O_NORTH, \
  O_NORTH_EAST, \
  O_EAST, \
  O_SOUTH_EAST, \
  O_SOUTH, \
  O_SOUTH_WEST, \
  O_WEST, \
  O_NORTH_WEST, \
  O_UP, \
  O_DOWN, \
  O_IN, \
  O_OUT, \
  O_NORTH_NORTH_EAST, \
  O_EAST_NORTH_EAST, \
  O_EAST_SOUTH_EAST, \
  O_SOUTH_SOUTH_EAST, \
  O_SOUTH_SOUTH_WEST, \
  O_WEST_SOUTH_WEST, \
  O_WEST_NORTH_WEST, \
  O_NORTH_NORTH_WEST, \
  O_NOWHERE

#define ORIENTATION_SHORT \
  OS_NORTH, \
  OS_NORTH_EAST, \
  OS_EAST, \
  OS_SOUTH_EAST, \
  OS_SOUTH, \
  OS_SOUTH_WEST, \
  OS_WEST, \
  OS_NORTH_WEST, \
  OS_UP, \
  OS_DOWN, \
  OS_IN, \
  OS_OUT, \
  OS_NORTH_NORTH_EAST, \
  OS_EAST_NORTH_EAST, \
  OS_EAST_SOUTH_EAST, \
  OS_SOUTH_SOUTH_EAST, \
  OS_SOUTH_SOUTH_WEST, \
  OS_WEST_SOUTH_WEST, \
  OS_WEST_NORTH_WEST, \
  OS_NORTH_NORTH_WEST, \
  OS_NOWHERE

#define ORIENTATION_FORWARD \
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20

#define ORIENTATION_REVERSE \
  4, 5, 6, 7, 0, 1, 2, 3, 9, 8,11,10,16,17,18,19,12,13,14,15,20

#define ORIENTATION_RIGHT \
  2, 3, 4, 5, 6, 7, 0, 1,20,20,20,20,14,15,16,17,18,19,12,13,20 

#define ORIENTATION_LEFT \
  6, 7, 0, 1, 2, 3, 4, 5,20,20,20,20,18,19,12,13,14,15,16,17,20 

#define ORIENTATION_DELTA \
  ({ 0, -1,  0}), \
  ({ 1, -1,  0}), \
  ({ 1,  0,  0}), \
  ({ 1,  1,  0}), \
  ({ 0,  1,  0}), \
  ({-1,  1,  0}), \
  ({-1,  0,  0}), \
  ({-1, -1,  0}), \
  ({ 0,  0,  1}), \
  ({ 0,  0, -1}), \
  ({ 0,  0,  0}), \
  ({ 0,  0,  0}), \
  ({ 1, -2,  0}), \
  ({ 2, -1,  0}), \
  ({ 2,  1,  0}), \
  ({ 1,  2,  0}), \
  ({-1,  2,  0}), \
  ({-2,  1,  0}), \
  ({-2, -1,  0}), \
  ({-1, -2,  0}), \
  ({ 0,  0,  0})

#endif /* _basic_orientation_h */
