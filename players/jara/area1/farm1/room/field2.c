/* Farm 1, Field 2, Created <6/11/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="A cornfield";
  long_desc=
    "  A fence borders the field in all directions, and there is a small\n"+
    "molehill in the fresh dirt here. Several rows of corn grow in uniform\n"+
    "lines in a north and south direction. The field of corn continues to\n"+
    "the west and south, and a scarecrow has been erected on a wooden post\n"+
    "in the middle of the field. A large barn is to the south, just beyond\n"+
    "the fence, and a pathway winds through the field of grass north of the\n"+
    "field.\n";
  items=({
    "molehill",
    "A large pile of freshly dug dirt, leading down within the earth",
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
    PATH+"field1","west",
    PATH+"field4","south" });
  if(!present("rabbit")) {
    ob=clone_object("/players/jara/area1/farm1/mon/rabbit.c");
    move_object(ob,this_object());
  }
}
