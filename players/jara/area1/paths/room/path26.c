/* Path 26, Created <5/16/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A pathway";
  long_desc=
    "  The path winds through an open field outside the city. There are\n"+
    "several short, spindly trees growing throughout the grass, and an\n"+
    "abundance of wild flowers spread in patches on both sides of the path.\n"+
    "The path itself is rutted deeply with wagon tracks, and a farm is\n"+
    "visible to the south.\n";
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
    "grass",
    "The grass is short, and dark green in color",
    "tracks",
    "The wagon tracks are wide, and deeply rutted in the mud",
    "trees",
    "The short trees are sparse, and the branches grow upwards from the\n"+
    "ground. There are no leaves",
    "dirt",
    "Moist from recent rains, the dirt is dark brown in color",
    "farm",
    "The farm to the south is bordered by a wooden fence, and a large\n"+
    "barn is visible",
    "fence",
    "A wooden fence that has been built beside the path" });
  dest_dir=({ 
    PATH+"path27","north",
    PATH+"path25","southeast" });
}
