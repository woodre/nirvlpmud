/* Path 27, Created <5/17/00> by Jara */

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
    "The path itself is rutted deeply with wagon tracks, and there is a\n"+
    "magnificent castle on a hill to the northwest.\n";
  items=({
    "castle",
    "A stone castle, with two towers and a massive wooden gate",
    "towers",
    "The towers of the castle are round and there are red and white banners\n"+
    "flying at the top of each tower",
    "gate",
    "The wooden gate is barred closed",
    "banners",
    "The triangular banners have a white top half and a red bottom half",
    "path", 
    "A narrow dirt path, mixed with sand and bits of gravel",
    "flowers",
    "The flowers are lavender and yellow in color",
    "tracks",
    "The wagon tracks are wide, and deeply rutted in the mud",
    "trees",
    "The short trees are sparse, and the branches grow upwards from the\n"+
    "ground. There are no leaves",
    "dirt",
    "Moist from recent rains, the dirt is dark brown in color" });
  dest_dir=({ 
    PATH+"path28","north",
    PATH+"path26","south" });
}
