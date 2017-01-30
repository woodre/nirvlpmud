/* Path 6, Created <5/17/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway";
  long_desc=
    "  The path winds southeast of the stables, through the lush, green\n"+
    "fields. The grass here is well maintained, and patches of wild flowers\n"+
    "spread in all directions. The stable and a fenced pasture are to the\n"+
    "north, the barn just beyond the pasture. A wooden fence borders the\n"+
    "path directly south, and several small sheep are grazing nearby.\n";
  items=({
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
    "The fenced pasture is bordered by a wooden fence and several sheep\n"+
    "are grazing on the grass",
    "barn",
    "The barn has a slanted roof, and high walls",
    "sheep",
    "The small sheep are plump and fluffy. Their white coats are soft\n"+
    "with wool" });
  dest_dir=({ 
    PATH+"path7","east",
    PATH+"path5","southwest" });
}
