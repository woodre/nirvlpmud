#include "/players/feldegast/defines.h"
inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A path through the jungle";
  long_desc=
"     This is a narrow path going through the heart of\n"+
"the jungle.  Vines and green foliage dangle across\n"+
"it, making travel slow and cumbersome.\n";
  items=({
    "vines","Vines or snakes.  You're just trying to think positively",
    "foliage","Bushes, tall grass, moss, and the roots of tall trees"
  });
  dest_dir=({
    "/players/feldegast/island/path/path5","west",
    "/players/feldegast/island/path/path7","north"
  });
}

realm() { return "NT"; }
