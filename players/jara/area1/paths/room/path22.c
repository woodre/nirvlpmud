/* Path 22, Created <5/16/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway";
  long_desc=
    "  The path winds through the open field outside the city wall. A field\n"+
    "of high grass and dense underbrush spreads to the south along the\n"+
    "shoreline, and the path continues east and west. A small, spindly tree\n"+
    "in the field just north of the path holds a strange bird nest. There\n"+
    "are patches of wild flowers growing on both sides of the path, and\n"+
    "deeply rutted wagon tracks are visible in the moist dirt of the path.\n";
  items=({
    "path", 
    "A narrow dirt path, mixed with sand and bits of gravel",
    "field",
    "The field stretches east and west along the shoreline. The high grass\n"+
    "is a deep green in color, and yellow wildflowers are visible in the\n"+
    "undergrowth",
    "grass",
    "The grass is approximately three feet high",
    "underbrush",
    "The underbrush is thick with blackberry vines and weeds",
    "flowers",
    "The flowers are lavender and yellow in color",
    "tracks",
    "The wagon tracks are wide, and deeply rutted in the mud",
    "dirt",
    "Moist from recent rains, the dirt is dark brown in color",
    "tree",
    "The tree stands approximately six feet high, and the narrow branches\n"+
    "twist upwards from the trunk",
    "nest",
    "The nest is oval shaped and rather large. Dried pieces of thick grass\n"+
    "and small branches stick out from the walls" });
  dest_dir=({ 
    PATH+"path21","east",
    PATH+"path23","west" });
}
