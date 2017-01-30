/* Farm1, House2 (lower bedroom), Created <6/14/00> by Jara */

#include "defs.h"
inherit "room/room";

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="An old Farmhouse- Bedroom";
  long_desc=
    "  The bedroom holds a small bed, with worn sheets and a pillow. A crate\n"+
    "beside the bed has been pushed up against the wall for use as a night-\n"+
    "stand, and an oil lamp is standing on the crate. A pair of overalls lay\n"+
    "on the floor beside the doorway, and a dirty white shirt is tucked in\n"+
    "the folds of the overalls. A door in the eastern wall leads to the main\n"+
    "room of the farmhouse. \n";
  items=({
    "bed",
    "A single person bed, with a wooden headboard",
    "sheets",
    "The sheets are worn and tattered about the edges",
    "pillow",
    "The pillow is flat and offwhite in color",
    "crate",
    "A small, wooden crate",
    "lamp",
    "A metal oil lamp with a glass covering",
    "overalls",
    "Handmade overalls, with several patches on the legs",
    "shirt",
    "A white shirt, covered with dirt and sweat stains",
    "door",
    "A wooden door, rectangular in shape, just high enough to pass\n"+
    "through",
    "floor",
    "The floor is made of light colored wooden panels, nailed together with\n"+
    "thick metal nails",
    "nails",
    "The round heads of the metal nails are all that is visible in the floor" });
  dest_dir=({ 
    PATH+"house1","east" });
  if(!present("son")) {
    ob=clone_object("/players/jara/area1/farm1/mon/son.c");
    move_object(ob,this_object());
  }
}
