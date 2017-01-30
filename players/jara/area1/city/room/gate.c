/* City Gate, Created <6/15/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="The City Gates";
  long_desc=
    "  The massive gate to the city is barred closed, and the high stone\n"+
    "walls are too smooth to climb. Several small shrubs have been planted\n"+
    "at the base of the walls, and the delicate flowers are in bloom. There\n"+
    "is a path leading southwest toward an intersection, and a smaller path\n"+
    "dotted with horse tracks that heads in a southeastern direction.\n";
    items=({
    "gate",
    "The wooden gate to the city is built of thick, wooden planks and sturdy\n"+
    "metal links",
    "shrubs",
    "Short, squatty shrubs with delicate yellow flowers" });
  dest_dir=({ 
    "/players/jara/area1/stable/path.c","southeast",
    "/players/jara/area1/paths/room/path3.c","southwest" });
}
