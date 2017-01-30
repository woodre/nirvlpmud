#include <orientation.h>

private string orientation;  // in what direction are we oriented

// function type string to void, Coogan, 26-Mar-2011
varargs void set_orientation(string direction, int mode) {
  // set it to what the room thinks of this direction
  // this is usable for rooms which want to fool the player
  // like the mirror-maze where the player is turned west in some
  // rooms when he wants to turn east or right, when he wants to turn left
  // also, it is usable for additional orientations like 'to' and 'fro'
  orientation =
    get_location(this_object())->get_orientation(direction, mode) ||
    O_NOWHERE;
}

string get_orientation() {
  return orientation;
}

// function type string to void, Coogan, 26-Mar-2011
void turn_orientation(string direction) {
  switch (direction) {
  case "around": set_orientation(get_orientation(),OM_REVERSE); break;
  case "right":  set_orientation(get_orientation(),OM_RIGHT);   break;
  case "left":   set_orientation(get_orientation(),OM_LEFT);    break;
  default:       set_orientation(direction);                    break;
  }
  return 0;  // Coogan, 26-Mar-2011
}

