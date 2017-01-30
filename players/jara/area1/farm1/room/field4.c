/* Farm 1, Field 4, Created <6/11/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A cornfield";
  long_desc=
    "  A fence borders the field in all directions, and several rows of corn\n"+
    "grow in uniform lines in a north and south direction. The field con-\n"+
    "tinues to the west and north, and a scarecrow has been erected on a\n"+
    "wooden post in the middle of the field. A large barn is to the south,\n"+
    "just beyond the fence, and the trail travels east and west just to the\n"+
    "south.\n";
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
    PATH+"field3","west",
    PATH+"field2","north" });
}
