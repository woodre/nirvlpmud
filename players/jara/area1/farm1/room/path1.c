/* Farm1, Path 1, Created <5/22/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A farm trail";
  long_desc=
    "  A fence borders the path to the east and west, with several rows of\n"+
    "corn growing within the field. The ears of corn are visible underneath\n"+
    "the light green husks, and a small scarecrow has been erected in the\n"+
    "field to the west. A large barn is visible in the distance, and the\n"+
    "dirt trail intersects with the path outside the city to the north.\n";
  items=({
    "trail", 
    "A narrow dirt path, mixed with sand and bits of gravel",
    "barn",
    "A wooden barn, with a slanted roof and high walls. A stack of hay\n"+
    "bales are visible beside the barn",
    "bales",
    "Thick, round bales of hay",
    "hay",
    "Thick, round bales of hay, light tan in color",
    "field",
    "The field holds several rows of cornstalks",
    "cornstalks",
    "The cornstalks are approximately five feet tall and hold numerous\n"+
    "ears of corn",
    "scarecrow",
    "A tattered and worn scarecrow, stuffed with hay and dressed in faded\n"+
    "clothing. He is on a large post",
    "post",
    "The post is made of wood and approximately seven feet tall",
    "corn",
    "Dark green in color, the cornstalks hold fresh ears of corn",
    "dirt",
    "Moist from recent rains, the dirt is dark brown in color",
    "fence",
    "A wooden fence that has been built beside the path" });
  dest_dir=({ 
    "/players/jara/area1/paths/room/path25.c","northeast",
    PATH+"path2","south" });
}
