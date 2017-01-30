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
"  Multicolored light streams through a pair of stained glass windows,\n\
painting the room in shades of blue, green, red, yellow, and purple.\n\
This is the Crystal Tower's training hall, where crystal mages are\n\
taught the ways of magic.\n";

  items=({
    "light", "Everywhere you look, you see light",
    "windows", "The windows depict two women, both alike yet unalike, like night and day",
    "hall", "reflexive",
  });
  dest_dir = ({
    ROOM_DIR + "crystal2", "west",
  });
}
