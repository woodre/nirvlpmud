#include "/players/feldegast/defines.h"
inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The Heart of the Jungle";
  long_desc=
"     The path ends here at the steps of a pyramid in the heart of\n"+
"the jungle.  Like the eye of a storm, the jungle stays far away\n"+
"from the pyramid's shadow.\n";
  items=({
    "pyramid","A huge construct of stone and mortar",
    "jungle","A dark place where few streaks of light penetrate the canopy"
  });
  dest_dir=({
    "/players/feldegast/island/path/pyramid","climb",
    "/players/feldegast/island/path/path6","south"
  });
}

realm() { return "NT"; }
