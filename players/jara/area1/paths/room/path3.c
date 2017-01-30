/* Path 3, Created <5/14/00> by Jara */

#include "defs.h"
#include "/players/jara/misc/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway";
  long_desc=
    "  The path reaches an intersection, and a small sign has been stuck in\n"+
    "the ground just beside the path. The grass here is a brilliant green,\n"+
    "and patches of wildflowers spread in all directions. The stable and a\n"+
    "large fenced pasture are beyond the path to the east, and there is a\n"+
    "barn north of the pasture. The city gate is to the northeast.\n";
  items=({
    "gate",
    "The city gate is made of sturdy wooden planks, and a small, barred\n"+
    "window is visible in the center of the gate",
    "window",
    "The window is barely a foot high and barred with thick, metal rods",
    "path",
    "A dirt path, mixed with sand and bits of gravel",
    "sign",
    "A wooden sign, handpainted white:\n"+
    " \n"+
    HIW+"  Graveyard"+NORM+" ---->\n"+
    " \n"+
    "The sign is old and well worn",
    "grass",
    "The recently trimmed grass has few weeds and a lush, green color",
    "flowers",
    "The wild flowers are lavender and yellow in color",
    "stable",
    "The stable is composed of a large, fenced pasture and a wooden barn",
    "pasture",
    "The fenced pasture is bordered by a wooden fence and several horses\n"+
    "are grazing within",
    "barn",
    "The wooden barn has a high, slanted roof and a wide, double door",
    "horses",
    "The sturdy horses vary in size and coloring" });
  dest_dir=({ 
    PATH+"path2","south",
    "/players/jara/area1/city/room/gate.c","northeast",
    PATH+"path4","southeast" });
}
