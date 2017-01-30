/* Path 8, Created <5/19/00> by Jara */

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
    "the south, and several sheep are grazing nearby. The graveyard and a\n"+
    "small chapel are further along the path to the northeast.\n";
  items=({
    "graveyard",
    "Bordered by a metal fence, the graveyard has a sinister appearance",
    "chapel",
    "A small, white chapel with stained glass windows",
    "windows",
    "The windows depict images of angels",
    "trail",
    "The trail leads between two fenced pastures and continues on to the\n"+
    "farmhouse and barn",
    "house",
    "A small cabin, with a chimney. A curl of smoke comes from the chimney",
    "chimney",
    "The red brick chimney is built into the wall of the cabin",
    "barn",
    "The barn has a slanted roof and high walls",
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
    PATH+"path9","northeast",
    PATH+"path7","west" });
}
