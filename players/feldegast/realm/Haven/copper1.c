#include "../def.h"
inherit ROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Copper Street";
  long_desc=
"    Heaps of refuse lie forgotten on this narrow street\n"+
"on the less prosperous side of Haven.  To the west is a\n"+
"rundown poorhouse.  Copper street continues to the south.\n";

  items=({
    "street","Although this street is still cobbled, there are many\n"+
             "loose stones and mud covers many others",
    "poorhouse","A rundown old building supported by good intentions\n"+
                "more than anything else",
    "refuse","You refuse to look any closer at the refuse"
  });
  dest_dir=({
    PATH+"Haven/azure1","north",
    PATH+"Haven/poorhouse","west",
    PATH+"Haven/copper2","south"
  });
}   
