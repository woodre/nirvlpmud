#include "../defs.h"

inherit ROOM;

string short() {
  string str;
  switch(random(6)) {
    case 0: str=HIW; break;
    case 1: str=HIB; break;
    case 2: str=BLU; break;
    case 3: str=BOLD; break;
    case 4: str=BOLD+BLK; break;
    case 5: str=HIR; break;
    default: str=HIB; break;
  }
  return "The "+str+"Crystal"+NORM+" Tower";
}

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  long_desc=
"  This is an elegantly furnished room at the bottom of a marble\n\
staircase running clockwise up the center of the crystal tower.\n\
A smaller staircase leading down is hidden in the marble\n\
staircase's arc.  An iron banded oak door, fit for a siege, leads\n\
out.\n";
  items=({
    "room", "reflexive",
    "staircase", "The marble staircase ascends into the darkness",
    "tower", "reflexive",
    "door", "It is a thick oak door, banded with iron and fit for a siege",
  });
  dest_dir = ({
    ROOM_DIR + "outside", "out",
    ROOM_DIR + "crystal2", "up",
    ROOM_DIR + "crystal0", "down",
  });
}
