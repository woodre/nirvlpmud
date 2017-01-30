/* Path 9, Created <5/21/00> by Jara */

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
    "the south, and several sheep are grazing nearby. The corner of city\n"+
    "wall is to the north, while a graveyard and a small chapel are further\n"+
    "along the path to the northeast.\n";
  items=({
    "corner",
    "The corner of the city wall marks the southeastern border of the city",
    "wall",
    "The wall is approximately twelve feet high and made of dark, grey\n"+
    "stone bricks",
    "bricks",
    "Large, grey stone bricks, square in shape",
    "graveyard",
    "Bordered by a metal fence, the graveyard has a sinister appearance",
    "chapel",
    "A small, white chapel with stained glass windows",
    "windows",
    "The windows depict images of angels",
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
    "The small sheep are plump and fluffy. Their white coats are soft\n"+
    "with wool" });
  dest_dir=({ 
    PATH+"path10","northeast",
    PATH+"path8","southwest" });
}
