#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc=GRN+"14th and C"+NORM;
  long_desc=
"The hustle and bustle of the big city can be felt all around:\n"+
"large buildings on every side, sidewalks filled with busy\n"+
"people, streets full of cars, the smell of pollution in the\n"+
"air.  It's a wonder that people actually live around here.\n"+
"To the west is the entrance to the "+BLU+"Bureau of Printing and\n"+
"Engraving"+NORM+".  South of here is the "+MAG+"14th Street Bridge"+
NORM+",\n"+"and to the southwest the mighty "+BLU+"Jefferson Memorial"+
NORM+"can be\nseen in the distance.\n\n"; 

  items=({
"buildings", "Old dirty buildings of no particular significance",
"sidewalks", "Be careful not to step on a crack",
  });

  dest_dir=({
    DCSTR+"s002", "north",
    DCSTR+"s001a", "south",
    DCBLDG+"t/bt01", "west",
  });
}

init() {
  ::init();
}
