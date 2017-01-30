/* Path 2, Created <5/14/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="An intersection";
  long_desc=
    "  The path widens at the intersection, and a large post stands beside\n"+
    "the path. The path leading south enters a field of high grass that\n"+
    "stretches several miles along the shoreline, while the path to the\n"+
    "north leads to a city. Wagon tracks are visible in the moist dirt of\n"+
    "the paths, as are several horseshoe prints. A third path leads to the\n"+
    "west.\n";
  items=({
    "path",
    "The dirt path is mixed with sand and bits of gravel",
    "post",
    "The sign post lists the destinations:\n"+
    "  \n"+
    " North- City of Zerchar\n"+
    " South- The Docks\n"+
    " West- Zerchar Castle\n"+
    " ",
    "field",
    "The grassy field is thick with blackberry vines, weeds, and a dense\n"+
    "underbrush",
    "shoreline",
    "The shoreline is not visible beyond the high grass",
    "tracks",
    "The tracks of horsedrawn wagons and riders",
    "vines",
    "Thickets of blackberry vines, with ripe blackberries and thorns",
    "weeds", 
    "The weeds hold small, yellow wildflowers" });
  dest_dir=({ 
    PATH+"path1","south",
    PATH+"path21","west",
    PATH+"path3","north" });
}
