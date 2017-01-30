#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A sandy beach";
  long_desc=
"     You are on a sandy beach.  The cool blue water laps up\n"+
"against the shore.  A swirling blue portal is a little further\n"+
"to the north.  To the southwest, you see a ship in the water.\n"+
"To the east, a path leads into the jungle.\n";
  items=({
    "portal","It shimmers through several shades of blue.",
    "water","Cool blue water with bits of plankton in it",
    "beach","A broad stretch of sand along the coast of this island",
    "shore","The shore goes north and curves slightly southeast here",
    "path","A dirt path leading into the jungle.  It appears to be\n"+
           "well-travelled.\n",
    "jungle","A thick tangle of vegetation spreading across the entire island",
    "ship","A sleak, fast vessel bristling with cannons.  Perfect for piracy.\n"
  });
  dest_dir=({
    "/players/feldegast/island/beach1","north",
    "/players/feldegast/island/jungle_path","east",
    "/players/feldegast/island/beach2","south"
  });
}   
