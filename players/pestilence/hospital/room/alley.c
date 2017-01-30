#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIK+"Dark Alleyway"+NORM+"";
long_desc =
  "    This is a dark and gloomy alleyway next to the hospital.\n"+
  "It doesn't seem like a nice place to visit alone.  Water drips\n"+
  "from the side of the building.  Dumpsters line the wall all\n"+
  "full and heaping with stinky garbage.  Out leads back to the\n"+
  "parking lot.\n";
set_light(1);

items = ({
  "desk","This is the help desk.",
  "walls","The walls are a dull blue, with chairs lined against them.",
  "chairs","Several wooden chairs lined against the walls.",
  "hallways","Long sterilized hallways extend in the north,east,west directions.",
  "path","A small worn path leding to the southwest",
});

dest_dir = ({

  "/players/pestilence/hospital/room/parkinglot.c","out",
});
}
