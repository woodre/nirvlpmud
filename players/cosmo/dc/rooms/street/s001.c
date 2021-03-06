#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"14th St"+NORM;
  long_desc=
"Just\n"+
"off\n"+
"the\n"+
"bridge\n"+
"\n"+
"\n"+
".\n\n"; 

  items=({
"buildings", "Old dirty buildings of no particular significance",
"sidewalks", "Be careful not to step on a crack",
  });

  dest_dir=({
    DCSTR+"s001a", "north",
    DCROOM+"bridge1", "south",
  });
}

init() {
  ::init();
}
