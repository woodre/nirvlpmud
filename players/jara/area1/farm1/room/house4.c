/* Farm1, House4 (kitchen), Created <6/14/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="An old Farmhouse- Kitchen";
  long_desc=
    "  The kitchen is a large room with wooden floors and a small, metal\n"+
    "fireplace. The cupboards line the southern wall, and a rack of cooking\n"+
    "pots hangs from the ceiling. There is a window in the northern wall,\n"+
    "overlooking the barn and chicken hutch, and colorful, handmade curtains\n"+
    "line the border of the window. A dishrag is on the counter beside the\n"+
    "sink, and the main room of the farmhouse is just to the west.\n";
  items=({
"floors",
    "The floor is made of light colored wooden panels, nailed together with\n"+
    "thick metal nails",
    "nails",
    "The round heads of the metal nails are all that is visible in the floor",
    "rack",
    "A metal rack hanging from the ceiling. It holds several cooking pots\n"+
    "utensils",
    "pots",
    "Thick, iron pots and skillets used for cooking",
    "utensils",
    "Wooden and metal spoons, forks and knives",
    "window",
    "A single paned window, square in shape",
    "curtains",
    "Cheerful, red curtains with white dots",
    "barn",
    "A large wooden barn",
    "hutch",
    "The chicken hutch is made of wood and metal wiring",
    "dishrag",
    "A worn and filthy rag",
    "sink",
    "A metal pot filled with water and dirty dishes",
    "cupboards",
    "Cupboards made of a light colored wood, with handles and several rows\n"+
    "of shelves",
    "shelves",
    "The shelves hold food and cooking supplies",
    "fireplace",
    "A round metal stove with a pipe that extends from the stove through the\n"+
    "ceiling" });
  dest_dir=({ 
    PATH+"house1","west" });
  if(!present("wife")) {
    ob=clone_object("/players/jara/area1/farm1/mon/wife.c");
    move_object(ob,this_object());
  }
}
