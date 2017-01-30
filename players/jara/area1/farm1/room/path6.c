/* Farm1, Path 6, Created <6/12/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A farm trail";
  long_desc=
    "  The path continues along the northern side of the large barn, just\n"+
    "southwest of the cornfields. A farmhouse is visible further in the\n"+
    "distance, with a set of stone steps leading to the porch. The ground\n"+
    "here is littered with straws of hay, and a chicken hutch stands in the\n"+
    "field just north of the house.\n";
  items=({
    "hutch",
    "The small chicken hutch is built of wood and metal wire",
    "trail", 
    "A narrow dirt path, mixed with sand and bits of gravel",
    "barn",
    "A wooden barn, with a slanted roof and high walls. A stack of hay\n"+
    "bales are visible beside the barn",
    "bales",
    "Thick, round bales of hay",
    "hay",
    "The fresh hay is light tan in color",
    "fields",
    "The field holds several rows of cornstalks",
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
    PATH+"path5","east",
    PATH+"path7","southwest" });
}
