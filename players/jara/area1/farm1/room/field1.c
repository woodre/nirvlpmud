/* Farm 1, Field 1, Created <6/11/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A cornfield";
  long_desc=
    "  A fence borders the field in all directions, and a gate marks the\n"+
    "exit further to the south. Several rows of corn grow in uniform lines\n"+ 
    "in a north and south direction. The field of corn continues to the east\n"+
    "and south, and a scarecrow has been erected on a wooden post in the\n"+
    "middle of the field. A large barn is to the south, just beyond the\n"+
    "gate. A pathway winds through the field of grass north of the field.\n";
  items=({
    "pathway", 
    "The pathway is rutted with wagon tracks, and it travels east and west\n"+
    "just north of the fence",
    "tracks",
    "The deeply rutted wagon tracks are still moist from a recent rain",
    "grass",
    "A lush, green field of grass",
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
    PATH+"field2","east",
    PATH+"field3","south" });
}
