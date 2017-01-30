/* Path 14, Created <5/21/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway";
  long_desc=
    "  The forest begins just north and east of the path, and the pathway\n"+
    "narrows as it enters the shelter of the trees. The thick canopy blocks\n"+
    "most light from passing to the forest floor, but a dense underbrush is\n"+
    "visible on each side of the trail. The path continues soutwest along\n"+
    "the city walls.\n";
  items=({
    "trail",
    "The narrow trail enters the forest. It has bits of gravel and dirt,\n"+
    "as well as debris from the forest canopy and underbrush",
    "debris",
    "The debris on the trail consists of twigs, leaves and branches",
    "forest", 
    "The forest has a thick, green canopy and dense underbrush",
    "canopy",
    "The forest canopy lets little light through the leaves",
    "underbrush",
    "Dense shrubs and bushes of underbrush",
    "walls",
    "The wall is approximately twelve feet high and made of dark, grey\n"+
    "stone bricks",
    "bricks",
    "Large, grey stone bricks, square in shape",
    "path",
    "A dirt path, mixed with sand and bits of gravel" });
  dest_dir=({ 
    "/players/jara/area1/forest/room/enter.c","northeast",
    PATH+"path13","southwest" });
}
