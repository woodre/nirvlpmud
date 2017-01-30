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
"  You are on a landing of the huge marble staircase that spirals up\n\
the center of the Crystal Tower.  A pair of highbacked antique\n\
chairs sit opposite each other in a small alcove with a window\n\
that overlooks the clearing beneath the tower.  To the north is\n\
a tall stone arch that leads to the tower's chapel.  A passageway\n\
leads east into the training hall and to the west is a storage room.\n\
A bulletin board is posted on the wall here.\n";
  items=({
     "staircase", "It is constructed of white marble and runs up and down the center\n"+
                  "of the tower",
     "tower", "reflexive",
     "chairs", "A pair of highbacked antique chairs sit opposite each other in a small\n"+
               "alcove with a window that overlooks the clearing beneath the tower",
     "alcove", "It holds two antique chairs and a window",
     "arch", "It leads into the tower's chapel",
     "passageway", "It leads east into the training hall",
  });
  dest_dir = ({
    ROOM_DIR + "chapel", "north",
    ROOM_DIR + "storage", "west",
    ROOM_DIR + "advance", "east",
    ROOM_DIR + "crystal3", "up",
    ROOM_DIR + "crystal1", "down",
  });
}
