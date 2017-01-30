#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"10th and Constitution"+NORM;
  long_desc=
"Natural History to the south\n"+
"\n"+
"\n"+
"\n"+
"\n"+
"\n"+
"\n"+
".\n\n";

  items=({
"grass","The plush green grass is off in the distance to the north",
"buildings", "Old dirty buildings of no particular significance",
  });

  dest_dir=({
    DCBLDG+"d/bd02", "south",
    DCSTR+"s209", "east",
    DCSTR+"s211", "west",
  });
}

init() {
  ::init();
}
