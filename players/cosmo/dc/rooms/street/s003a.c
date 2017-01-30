#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"14th St at the Mall"+NORM;
  long_desc=
".\n\n";

  items=({
"grass","The plush green grass is off in the distance to the north",
"buildings", "Old dirty buildings of no particular significance",
  });

  dest_dir=({
    DCSTR+"s004", "north",
    DCSTR+"s003", "south",
    DCSTR+"smn13", "east",
  });
}

init() {
  ::init();
}
