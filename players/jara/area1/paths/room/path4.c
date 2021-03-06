/* Path 4, Created <5/17/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway";
  long_desc=
"  The path winds south of the stables, through the lush, green fields.\n"+
"The grass here is well maintained, and patches of wild flowers spread\n"+
"in all directions. The stable and a fenced pasture are north and east,\n"+
"the barn just north of the pasture. The city gate is further down the\n"+
"path to the northwest.\n";
  items=({
    "fields",
    "The field of grass outside the city walls is a lush green color, and\n"+
    "delicate wild flowers grow in abundance on both sides of the path",
    "stables",
    "Just outside the city walls, the stables consist of a large barn,\n"+
    "a fenced pasture and a stable for the horses",
    "path",
    "A dirt path, mixed with sand and bits of gravel",
    "grass",
    "The recently trimmed grass has few weeds and a lush, green color",
    "flowers",
    "The wild flowers are lavender and yellow in color",
    "pasture",
    "The fenced pasture is bordered by a wooden fence and several horses\n"+
    "are grazing within",
    "barn",
    "The barn has a slanted roof, and high walls",
    "gate",
    "A large, wooden gate, built of planks and a small window is visible",
    "window",
    "A barred window within the gate",
    "The wooden barn has a high, slanted roof and a wide, double door",
    "horses",
    "The sturdy horses vary in size and coloring" });
  dest_dir=({ 
    PATH+"path3","northwest",
    PATH+"path5","east" });
}
