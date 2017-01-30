/* Farm2, Path 1, Created <6/22/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A farm trail";
  long_desc=
        "  The path to the farm is blocked by a wooden gate, tied closed with a\n"+
    "thick rope. The narrow dirt path is littered with debris of dead leaves\n"+
    "and twigs, and the wagon tracks are faint. The fence that borders the\n"+ 
    "farm continues to the east and west, and the sheep are grazing on the\n"+
    "grass within the field.\n";
  items=({
    "gate",
    "A wooden gate, built of the same wood as the fence",
    "rope",
    "A thick rope, tied in a knot",
    "debris",
    "The debris of dead leaves and twigs covers much of the farm trail",
    "leaves",
    "Dried brown and yellowed leaves",
    "twigs",
    "The small twigs have collected in the ruts of the farm trail",
    "tracks",
    "The wagon tracks are faint and appear quite old",
    "sheep",
    "Plump, white sheep, with thick woolen coats",
    "grass",
    "The lush, green grass is kept well-trimmed by the sheep",
    "path", 
    "A narrow dirt path, mixed with sand and bits of gravel",
    "field",
    "The lush green field of grass is grazed upon by several sheep",
    "dirt",
    "Moist from recent rains, the dirt is dark brown in color",
    "fence",
    "A wooden fence that has been built beside the path" });
  dest_dir=({ 
    "/players/jara/area1/paths/room/path7", "northwest" });
}
