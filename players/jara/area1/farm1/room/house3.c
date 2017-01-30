/* Farm1, House3 (master bedroom), Created <6/14/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="An old Farmhouse- Upstairs Bedroom";
  long_desc=
    "  The upstairs bedroom holds a large bed, with worn sheets and two\n"+
    "pillows. There is a small, wooden table pushed up against the southern\n"+
    "wall, which holds a lamp and a deck of playing cards. A patchwork quilt\n"+
    "lays at the end of the bed and a painting of a mountain scene hangs\n"+
    "crookedly on the eastern wall. There are stairs leading downstairs to\n"+
    "the main room of the farmhouse.\n";
  items=({
    "bed",
    "A double wide bed, with an elaborately carved wooden headboard",
    "sheets",
    "The sheets are worn and tattered about the edges",
    "pillows",
    "The pillows are flat and offwhite in color",
    "table",
    "The table has three legs and it is made of a dark wood",
    "painting",
    "The painting is a beautiful scene of a snow covered mountain",
    "stairs",
    "A narrow flight of stairs with a wooden handrail",
    "handrail",
    "The handrail is made of wood, and circular in shape",
    "lamp",
    "A metal oil lamp with a glass covering",
    "cards",
    "A worn deck of playing cards. The edges have been worn smooth",
    "quilt",
    "The quilt is designed of several different fabrics, all sewn together",    
    "floor",
    "The floor is made of light colored wooden panels, nailed together with\n"+
    "thick metal nails",
    "nails",
    "The round heads of the metal nails are all that is visible in the floor" });
  dest_dir=({ 
    PATH+"house1","down" });
  if(!present("derk")) {
    ob=clone_object("/players/jara/area1/farm1/mon/derk.c");
    move_object(ob,this_object());
  }
}
