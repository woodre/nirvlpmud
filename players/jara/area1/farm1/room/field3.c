/* Farm 1, Field 3, Created <6/11/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A cornfield";
  long_desc=
    "  A fence borders the field in all directions, and a gate marks the\n"+
    "exit. Several rows of corn grow in uniform lines in a north and south\n"+
    "direction. The field of corn continues to the east and north, and a\n"+
    "scarecrow stands erect on a wooden post in the middle of the field.\n"+ 
    "A large barn is to the south, beyond the gate, and the dirt trail goes\n"+
    "east and west along the fence.\n";
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
    PATH+"field1","north",
    PATH+"field4","east",
    PATH+"path4","south" });
}
