/* Path 29 outside the castle, Created <5/17/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A pathway";
  long_desc=
    "  The path winds through the trees and lush grass field of the hill.\n"+
    "There are several short, spindly trees growing on the hill beside the\n"+
    "path, and the castle looms just ahead to the northwest. The gate is\n"+
    "closed, and the windows shuttered. The banners atop the towers rise\n"+
    "gently with each breeze, and the path continues southeast further\n"+
    "down the hill.\n";
  items=({
    "windows",
    "The windows are carved out of the stone walls, square in shape, and\n"+
    "shuttered with wooden slats",
    "field",
    "The lush, green grass is dotted with patches of delicate wild flowers",
    "hill",
    "The low, gently sloping hill has numerous trees and a large castle has\n"+
    "been built on the crest",
    "patches",
    "The irregular shaped patches of wild flowers grow in the grass of the\n"+
    "field and on the hill",
    "crest",
    "The crest of the hill is a few hundred feet further up the path to the\n"+
    "northwest. A castle stands at the crest",
    "grass",
    "The grass is short, and a deep green in color",
    "trees",
    "The short, spindly trees are without leaves, and the branches grow upwards\n"+
    "from the ground",
    "branches",
    "The narrow branches bend and curve upwards from the trunk of the trees",
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
    "dirt",
    "Moist from recent rains, the dirt is dark brown in color" });
  dest_dir=({ 
    "/players/jara/area1/castle/room/gate.c","northwest",
    PATH+"path28","southeast" });
}
