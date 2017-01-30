/* Farm1, Barn1, Created <6/13/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A barn";
  long_desc=
    "  The barn is a large building, made of wood, with several windows in\n"+
    "each wall. A stack of hay bales against the southern wall towers over\n"+
    "the barn floor, reaching almost to the ceiling. There are wooden stalls\n"+
    "built further to the east, and the ground here is littered with strands\n"+
    "of hay. There are numerous tools on a rack that has been built into the\n"+
    "northern wall. A double door in the western wall leads to the path, and\n"+
    "the barn continues to the east.\n";
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
    "tools",
    "Several farming tools, including rakes, shovels and numerous others",
    "rakes",
    "Long rakes, with wooden handles and metal prongs",
    "shovels",
    "The shovels are square and pointed in shape, made of metal with wooden\n"+
    "handles",
    "rack",
    "A long, sturdy metal rack",
    "door",
    "The barn doors are made of the same panels as the barn, and they have\n"+
    "been left ajar",
    "path",
    "A narrow dirt path" });
  dest_dir=({ 
    PATH+"barn2","east",
    PATH+"path7","west" });
}
