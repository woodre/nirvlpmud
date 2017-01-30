/* Farm1, Path 8, Created <6/2/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="A farm trail";
  long_desc=
    "  The path opens up into an irregular area, bordered by worn grass. A\n"+
    "set of stairs lead south to the porch of the farmhouse, and the chicken\n"+
    "hutch stands just to the west. The cage door is ajar, and the ground is\n"+
    "littered with straws of hay. There is an outhouse in the field to the\n"+
    "east, and the path continues north to the cornfields and barn.\n";
  items=({
    "outhouse",
    "The small outhouse is made of wood, and there is a door in the wall",
    "door",
    "The outhouse door has a crescent moon carved as a window",
    "trail", 
    "A narrow dirt path, mixed with sand and bits of gravel",
    "barn",
    "A wooden barn, with a slanted roof and high walls. A stack of hay\n"+
    "bales are visible beside the barn",
    "bales",
    "Thick, round bales of hay",
    "hay",
    "Thick, round bales of hay, light tan in color",
    "fields",
    "The field holds several rows of cornstalks",
    "field",
    "An open field of grass. The outhouse stands in the center",
    "cornstalks",
    "The cornstalks are approximately five feet tall and hold numerous\n"+
    "ears of corn",
    "corn",
    "Dark green in color, the cornstalks hold fresh ears of corn",
    "dirt",
    "Moist from recent rains, the dirt is dark brown in color",
    "stairs",
    "Stone steps, worn smooth by use, lead to the porch",
    "porch", 
    "A wooden porch built on the front of the small farmhouse",
    "farmhouse",
    "A two-story farmhouse, with a small porch and several windows",
    "windows",
    "The windows have four panes, and are dirty from the dust" });
  dest_dir=({ 
    PATH+"path7","north",
    PATH+"house1","south",
    PATH+"o_h","enter",
    PATH+"hutch","west" });
  if(!present("chick")) {
    ob=clone_object("/players/jara/area1/farm1/mon/chick.c");
    move_object(ob,this_object());
  }
}
