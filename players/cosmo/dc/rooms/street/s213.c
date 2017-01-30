#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"13th and Constitution"+NORM;
  long_desc=
"American\n"+
"History\n"+
"to\n"+
"the\n"+
"south\n"+
"\n"+
"\n"+
".\n\n";

  items=({
"grass","The plush green grass is off in the distance to the north",
"buildings", "Old dirty buildings of no particular significance",
  });

  dest_dir=({
    DCBLDG+"e/be02", "south",
    DCSTR+"s212", "east",
    DCSTR+"s004", "west",
  });
}

init() {
  ::init();
}
