/* Path 25, Created <5/16/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A pathway";
  long_desc=
"  The path winds through an open field outside the city. There is a\n"+
"wooden fence that borders the path to the south, and a path leading\n"+
"southwest leads toward a farm. A large barn, visible in the distance,\n"+
"is just beyond the rows of corn are growing in the field to the south.\n"+
"The dirt path is rutted deeply with wagon tracks, and patches of wild\n"+
"flowers grow in abundance in the grass to the north.\n";
  items=({
    "path", 
    "A narrow dirt path, mixed with sand and bits of gravel",
    "barn",
    "A wooden barn, with a slanted roof and high walls. A stack of hay\n"+
    "bales are visible beside the barn",
    "bales",
    "Thick, round bales of hay",
    "hay",
    "Thick, round bales of hay, light tan in color",
    "flowers",
    "The flowers are lavender and yellow in color",
    "tracks",
    "The wagon tracks are wide, and deeply rutted in the mud",
    "corn",
    "Dark green in color, the corn stalks hold fresh ears of corn",
    "dirt",
    "Moist from recent rains, the dirt is dark brown in color",
    "fence",
    "A wooden fence that has been built beside the path" });
  dest_dir=({ 
    PATH+"path24","east",
    PATH+"path26","northwest",
    "/players/jara/area1/farm1/room/path1.c","southwest" });
}
