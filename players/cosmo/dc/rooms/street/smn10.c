#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"North Side of the Mall"+NORM;
  long_desc=
"Natural History to the north\n"+
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
    DCBLDG+"d/bd01", "north",
    DCSTR+"smn09", "east",
    DCSTR+"smn11", "west",
  });
}

init() {
  ::init();
}
