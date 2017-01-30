/* Farm1, Path 5, Created <5/26/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="A farm trail";
  long_desc=
    "  A fence borders the path to the north, with several rows of corn\n"+
    "growing within the field. The ears of corn are visible underneath the\n"+
    "light green husks, and a small scarecrow has been erected in the center\n"+
    "of the field. The entrance to the barn is to the south, and there is an\n"+
    "outhouse visible to the southwest.\n";
  items=({
    "entrance",
    "The entrance to the barn is a large pair of double doors",
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
    PATH+"path4","east",
    PATH+"path6","west" });
  if(!present("cat")) {
    ob=clone_object("/players/jara/area1/farm1/mon/cat.c");
    move_object(ob,this_object());
  }
}
