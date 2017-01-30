#include "/players/feldegast/closed/shortcut.h"

inherit ROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A path in the jungle";
  long_desc=
"     This is a well used path through the jungle.  To the west\n"+
"you hear the sounds of the ocean.  You can just barely make out\n"+
"a few huts to the east.\n";
  items=({
    "huts","You can just barely make out a few huts to the east.\n"+
           "Perhaps it is a village of some sort?"
  });
  dest_dir=({
    "/players/feldegast/island/beach3","west",
    "/players/feldegast/island/village1","east"

  });
}   
