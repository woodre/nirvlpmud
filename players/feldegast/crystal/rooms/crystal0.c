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
"  The flight of marble steps spirals down deep into the very bowels\n\
of the earth until it ends abrubtly at a door constructed out of\n\
crystal.\n";
  items=({
    "steps", "The marble steps spiral up from here",
    "door", "It is constructed entirely out of blue crystal",
  });
  dest_dir = ({
    ROOM_DIR + "focus", "north",
    ROOM_DIR + "crystal1", "up",
  });
}
