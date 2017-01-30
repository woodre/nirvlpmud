#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"9th and Independence"+NORM;
  long_desc=
"Arts and Industries Building\n"+
"to\n"+
"the\n"+
"north\n"+
"\n"+
"\n"+
".\n\n";

  items=({
"grass","The plush green grass is off in the distance to the north",
"buildings", "Old dirty buildings of no particular significance",
  });

  dest_dir=({
    DCSTR+"s108", "east",
    DCSTR+"s110", "west",
  });
}

init() {
  ::init();
}
