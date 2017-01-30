#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"10th and Independence"+NORM;
  long_desc=
"Smithsonian Institute\n"+
"to\n"+
"the\n"+
"north\n"+
"National Museum of African Art to the south\n"+
"\n"+
".\n\n";

  items=({
"grass","The plush green grass is off in the distance to the north",
"buildings", "Old dirty buildings of no particular significance",
  });

  dest_dir=({
    DCSTR+"s109", "east",
    DCSTR+"s111", "west",
  });
}

init() {
  ::init();
}
