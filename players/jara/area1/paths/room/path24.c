/* Path 24, Created <5/16/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway";
  long_desc=
"  The path winds through the open field outside the city wall. There\n"+
"is a wooden fence that borders the path to the south, and a large barn\n"+
"is visible to the southwest. There are patches of wild flowers growing\n"+
"on both sides of the path, and deeply rutted wagon tracks are visible\n"+
"in the moist dirt of the pathway.\n";
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
    "walls",
    "The walls of the city are made of stone, light gray in color. The\n"+
    "walls stand approximately twelve feet high, and weeds sprout up\n"+
    "at the base of the wall",
    "flowers",
    "The flowers are lavender and yellow in color",
    "tracks",
    "The wagon tracks are wide, and deeply rutted in the mud",
    "dirt",
    "Moist from recent rains, the dirt is dark brown in color",
    "fence",
    "A wooden fence that has been built beside the path" });
  dest_dir=({ 
    PATH+"path23","southeast",
    PATH+"path25","west" });
}
