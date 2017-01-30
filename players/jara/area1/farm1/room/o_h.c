/* Farm1, Outhouse, Created <6/12/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc="An Outhouse";
  long_desc=
    "  The interior of the outhouse is made of wood, and a small bench has\n"+
    "been built into the rear wall. A large, gaping hole in the center of\n"+
    "the bench opens up into a dark pit beneath the outhouse. The door in\n"+
    "the western wall leads to the field and path, and some tissue has been\n"+
    "folded up on the bench.\n";
  items=({
    "bench",
    "A narrow wooden bench built into the walls of the outhouse. It has\n"+
    "numerous splinters",
    "hole",
    "A round hole, worn smooth, in the bench",
    "pit",
    "The darkness of the pit seems to move and shift slightly",
    "tissue",
    "A small wad of brown tissues",
    "door",
    "The outhouse door has a crescent moon carved as a window" });
  dest_dir=({ 
    PATH+"path8","out" });
}
