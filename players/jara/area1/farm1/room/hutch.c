/* Farm1, Chicken Hutch, Created <6/12/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="The Chicken Hutch";
  long_desc=
    "  The small chicken hutch is made of wood and metal wire, woven tightly\n"+
    "together to prevent the loss of chickens. The ground here is littered\n"+
    "with strands of hay and the dirt is muddied from a fresh rain. Small\n"+
    "pieces of grain are scattered about beneath the hutch, and the door to\n"+
    "the hutch is ajar. The path is to the east, with the steps to the porch\n"+
    "leading south from the path.\n";
  items=({
    "hutch",
    "The wooden chicken hutch is rectangular in shape and houses several wooden\n"+
    "boxes for chickens to roost in. The floor of the hutch is covered in hay",
    "boxes",
    "The boxes have holes wide enough for chickens to pass through, and the roof\n"+
    "is hinged",
    "floor",
    "The floor of the hutch is about three feet off the ground and covered in a\n"+
    "thick layer of hay",
    "hay",
    "The hay is light tan in color",
    "wire",
    "Metal wire woven together to prevent animals from entering the hutch",
    "dirt",
    "The dirt is moist from recent rains",
    "grain", 
    "The fresh grain is used for chicken feed",
    "door",
    "A hinged door, made of the same materials as the hutch",
    "path",
    "The irregularly shaped path opens up just to the east",
    "farmhouse",
    "A two-story farmhouse, with a porch",
    "porch",
    "A wooden porch built beside the farmhouse",
    "steps",
    "Stone steps leading from the ground to the porch of the farmhouse" });
  dest_dir=({ 
    PATH+"path8","east" });
  if(!present("hen")) {
    ob=clone_object("/players/jara/area1/farm1/mon/hen.c");
    move_object(ob,this_object());
  }
  if(!present("chick")) {
    ob=clone_object("/players/jara/area1/farm1/mon/chick2.c");
    move_object(ob,this_object());
  }
  if(!present("rooster")) {
    ob=clone_object("/players/jara/area1/farm1/mon/rooster.c");
    move_object(ob,this_object());
  }
}
