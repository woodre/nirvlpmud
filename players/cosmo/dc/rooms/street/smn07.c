#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"North Side of the Mall"+NORM;
  long_desc=
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
    DCSTR+"s207", "north",
    DCSTR+"sm07", "south",
    DCSTR+"smn06", "east",
    DCSTR+"smn08", "west",
  });
}

init() {
  ::init();
}
