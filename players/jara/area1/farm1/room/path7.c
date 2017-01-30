/* Farm1, Path 7, Created <6/12/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A farm trail";
  long_desc=
    "  The path opens up into an irregular area, bordered by worn grass.\n"+
    "Further to the south, a set of stairs lead to the porch of the house,\n"+
    "and the barn doors are directly to the east. The barn doors are ajar,\n"+
    "and the ground is littered with straws of hay. An outhouse stands in\n"+
    "a field southeast of the path, and the path continues north toward the\n"+
    "corn fields.\n";
  items=({
    "outhouse",
    "The small outhouse is made of wood, and there is a door in the wall",
    "doors",
    "The double doors are made of the same wood as the barn, and have been\n"+
    "left ajar",
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
    "house",
    "A two-story farmhouse, with a small porch and several windows",
    "windows",
    "The windows have four panes, and are dirty from the dust" });
  dest_dir=({ 
    PATH+"path6","northeast",
    PATH+"barn1","east",
    PATH+"path8","south" });
}
