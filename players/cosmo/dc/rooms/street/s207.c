#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"7th and Constitution"+NORM;
  long_desc=
"\n"+
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
    DCSTR+"smn07", "south",
    DCSTR+"s206", "east",
    DCSTR+"s208", "west",
  });
}

init() {
  ::init();
}
