#include "/players/feldegast/defines.h"
inherit ROOM;
  int locked;
reset(arg) {
  locked=1;
  if (arg) return;
  set_light(1);
  short_desc="The "+HIB+"Crystal"+NORM+" Tower's Foyer";
  long_desc=
"  This is an elegantly furnished room at the bottom of a marble\n"+
"staircase running clockwise up the center of the crystal tower.\n"+
"A smaller staircase leading down is hidden in the marble\n"+
"staircase's arc.  An iron banded oak door, fit for a siege, leads\n"+
"out.\n";
  items=({
  });
  dest_dir=({
    "/players/feldegast/closed/tower/outside","south",
    "/players/feldegast/closed/tower/tower1","up",
    "/players/feldegast/closed/tower/towersub1","down"
  });
}
