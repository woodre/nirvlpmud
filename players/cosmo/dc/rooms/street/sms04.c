#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"South Side of the Mall"+NORM;
  long_desc=
"Merry-go-Round to the north (on the Mall)\n"+
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
    DCBLDG+"m/bm01", "north",
    DCSTR+"sms03", "east",
    DCSTR+"sms05", "west",
  });
}

init() {
  ::init();
}
