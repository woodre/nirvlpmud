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
  return "The "+str+"Crystal"+NORM+" Focus";
}

string query_focus() { return "crystalmage"; }

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  long_desc=
"  This chamber appears to mimic the interior of a faceted blue\n\
crystal.  At its widest point, the room is approximately twenty\n\
meters across.  The room crackles with magical energy as chromatic\n\
phantasms and flashing illusions dance in its many facets.\n";
  items=({
    "chambers", "reflexive",
    "crystal", "reflexive",
    "room", "reflexive",
    "energy", "It seems to crackle in the air",
    "phantasms", "They dance about in the room's many facets",
    "illusions", "They dance about in the room's many facets",
  });
  dest_dir = ({
    ROOM_DIR + "crystal0", "out",
  });
}
