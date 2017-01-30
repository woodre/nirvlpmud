/* Farm1, Path 4, Created <5/26/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A farm trail";
  long_desc=
"  A fence borders the path north of the path, with numerous rows of\n"+
"corn growing within the field. The ears of corn are visible underneath\n"+
"the light green husks, and a small scarecrow has been erected in the\n"+
"center of the field. A large barn is directly to the south, and the\n"+
"dirt trail winds to the southwest. A small gate marks the entrance to\n"+
"the field.\n";
  items=({
    "gate",
    "The wooden gate is ajar, and the metal hinges are slightly rusted\n"+
    "around the edges",
    "hinges",
    "The large, metal hinges are nailed to the fence and made of a silver\n"+
    "colored metal",    
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
    PATH+"field3","north",
    PATH+"path3","east",
    PATH+"path5","west" });
}
