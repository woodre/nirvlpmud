/* Path 21, Created <5/16/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway";
  long_desc=
    "  The path winds through the open field outside the city wall. A field\n"+
    "of high grass and dense underbrush spreads to the south along the\n"+
    "shoreline, and an interesection lies to the east. There are several\n"+
    "patches of wild flowers growing on both sides of the path, and deeply\n"+
    "rutted wagon tracks are visible in the moist dirt of the pathway.\n";
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
    "vines",
    "The vines are weighted down with ripe blackberries",
    "intersection",
    "The intersection is marked by a tall signpost",
    "signpost",
    "The post stands approximately six feet high. The lettering is not\n"+
    "visible from this distance",
    "flowers",
    "The flowers are lavender and yellow in color",
    "tracks",
    "The wagon tracks are wide, and deeply rutted in the mud",
    "dirt",
    "Moist from recent rains, the dirt is dark brown in color" });
  dest_dir=({ 
    PATH+"path2","east",
    PATH+"path22","west" });
}
