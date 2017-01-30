/* Farm1, Barn2, Created <6/14/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="A barn";
  long_desc=
    "  The barn is a large building, made of wood, with several windows in\n"+
    "each wall. A stack of hay bales against the southern wall towers over\n"+
    "the barn floor, reaching almost to the ceiling. There are wooden stalls\n"+
    "built against the northern wall, and the ground here is littered with\n"+
    "strands of hay. A saddle rack in the corner holds several worn saddles\n"+
    "and horse tack. The barn continues to the west.\n";
  items=({
    "windows",
    "Dusty windows built into the walls of the barn. They are square in shape",
    "hay",
    "The hay is light tan in color and very fresh",
    "bales",
    "Thick, round bales of hay",
    "floor",
    "A wooden floor, covered with dirt and strands of hay",
    "ceiling",
    "A high ceiling with thick wooden beams",
    "stalls",
    "Rectangular stalls, built to house animals",
    "ground",
    "The ground floor of the barn is covered with a thick layer of dirt and\n"+
    "strands of hay",
    "rack",
    "A wooden rack with pegs used to hold saddles, bridles and other tack",
    "saddles", 
    "The saddles are well worn and made of thick leather, and adorned with\n"+
    "brilliant pieces of silver",
    "tack",
    "The saddles, bridles, blankets and brushes are all hanging on the racks" });
  dest_dir=({ 
    PATH+"barn1","west" });
  if(!present("colt")) {
    ob=clone_object("/players/jara/area1/farm1/mon/colt.c");
    move_object(ob,this_object());
  }
}
