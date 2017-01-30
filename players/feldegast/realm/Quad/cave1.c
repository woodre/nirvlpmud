#include "../def.h"
inherit MYROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A dim cave";
  long_desc=
"    Light filters into this dank cave from the entrance to\n"+
"the south.  The uneven floor of the cave slopes down and\n"+
"to the north.\n";
  items=({
    "entrance","The light coming from the entrance fills the cave with\n"+
               "odd shadows",
    "floor","The floor of the cave is uneven, but you notice the tracks\n"+
            "of some sort of biped"
  });
  dest_dir=({
    PATH+"Quad/cave3","north",
    PATH+"trail3a","south"
  });
}   
init() {
  ::init();
  add_action("search","search");
}
search(str) {
  write("You notice many tracks of some sort of biped.\n");
  return 1;
}
