/* Path 7, Created <5/17/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway";
  long_desc=
    "  The path winds through the lush, green fields just south of the city\n"+
    "walls. The grass here is well maintained, and patches of wild flowers\n"+
    "spread in all directions. A wooden fence borders the path directly to\n"+
    "the south, and several sheep are grazing nearby. A narrow dirt trail\n"+
    "leads southeast toward a farmhouse.\n";
  items=({
    "trail",
    "The trail leads between two fenced pastures and continues on to the\n"+
    "farmhouse and barn",
    "house",
    "A small cabin, with a chimney. A curl of smoke comes from the chimney",
    "chimney",
    "The red brick chimney is built into the wall of the cabin",
    "barn",
    "The barn has a slanted roof and high walls",
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
    "sheep",
    "The small sheep are plump and fluffy. The sheep fur is soft and thick\n"+
    "with wool" });
  dest_dir=({ 
    PATH+"path8","east",
    "/players/jara/area1/farm2/room/path1.c","southeast",
    PATH+"path6","west" });
}
