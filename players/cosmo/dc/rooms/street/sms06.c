#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"South Side of the Mall"+NORM;
  long_desc=
"Air and Space to the south\n"+
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
    DCSTR+"sms05", "east",
    DCSTR+"sms07", "west",
    DCBLDG+"a/ba01", "south",
  });
}

init() {
  ::init();
}
