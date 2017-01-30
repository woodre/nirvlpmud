#include "/players/feldegast/defines.h"
inherit ROOM;

object hag;
reset(arg) {
  if (arg) return;
  if(!hag) {
    hag=clone_object("/players/feldegast/island/path/horbella");
    move_object(hag,this_object());
  }
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
    "/players/feldegast/island/path/path2","north",
    "/players/feldegast/island/path/path4","south"
  });
}

realm() { return "NT"; }
