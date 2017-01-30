#include "../DEFS.h"

status main(string str) {
  /* directional system                                  */
  /* allows pilot to aim the mech in a certain direction */
  int ok;
  string dir;
  if(!str) {
    write("Usage: aim <direction>\n");
    return 1;
  }
  switch(str) {
    case "n": ok = 1; dir = "n"; break;
    case "north": ok = 1; dir = "n"; break;
    case "s": ok = 1; dir = "s"; break;
    case "south": ok = 1; dir = "s"; break;
    case "e": ok = 1; dir = "e"; break;
    case "east": ok = 1; dir = "e"; break;
    case "w": ok = 1; dir = "w"; break;
    case "west": ok = 1; dir = "w"; break;
    case "ne": ok = 1; dir = "ne"; break;
    case "northeast": ok = 1; dir = "ne"; break;
    case "se": ok = 1; dir = "se"; break;
    case "southeast": ok = 1; dir = "se"; break;
    case "nw": ok = 1; dir = "nw"; break;
    case "northwest": ok = 1; dir = "nw"; break;
    case "sw": ok = 1; dir = "sw"; break;
    case "southwest": ok = 1; dir = "sw"; break;
  }
  if(!ok) {
    write(str+" is not a valid direction.  Your choices are:\n"+
          "'n, e, s, w, ne, nw, se, or sw'\n");
    return 1;
  }
  ETP->set_aim(dir);
  tell_room(ROOM, capitalize((string)ETP->query_myname())+" faces "+dir+".\n");
  return 1;
}
