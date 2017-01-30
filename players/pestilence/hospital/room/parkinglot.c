#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+BLU+"Hospital Parking Lot"+NORM+"";
long_desc =
  "    This is a large parking lot for the Amity Memorial Hospital.\n"+
  "There are many cars here.  The hospital on the north side of the\n"+
  "parking lot, with North Main Street, to the south of the lot. In\n"+
  "the north east corner you can see a small alley way, running along\n"+
  "the side of the hospital.\n";
set_light(1);

items = ({
  "desk","This is the help desk.",
  "walls","The walls are a dull blue, with chairs lined against them.",
  "chairs","Several wooden chairs lined against the walls.",
  "hallways","Long sterilized hallways extend in the north,east,west directions.",
  "path","A small worn path leding to the southwest",
});

dest_dir = ({

  "/players/pestilence/hospital/room/lobby.c","north",
  "/players/pestilence/amity/room/nmain3.c","south",
  "/players/pestilence/hospital/room/alley.c","northeast",
});
}
