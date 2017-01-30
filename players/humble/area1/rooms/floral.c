/* COPYRIGHT VITAL CORP, outline derived from Vital Code*/


#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIM+"Floral Department"+NORM;
    long_desc =
    "This is your local QFC "+HIM+"Floral Department"+NORM+" .  As you enter\n"+
    "the area a woman named Cici pops out from behind a counter.\n"+
     "The Department is tucked away from the clutter of the\n"+
    "store and is quite cozy.  It smells of morning dew.\n"+
    "As you walk about the department you see some beautiful\n"+
    "bouquets and flower arrangements, as well as some single\n"+
    "roses for sale.  The sound of children screaming down the aisle\n"+
    "brings you back to reality and your sense of comfort and ease is gone.\n";

    items =
    ({
    "bouquet",
    "This is a beautiful bouquet of roses",
    "flowers",
    "A beautiful arrangment of flowers",
    "rose",
    "A single rose",
    });
    dest_dir =
    ({
    RPATH+"checkstand1",        "east"
    });

    move_object(clone_object("players/humble/area1/mobs/jamie.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/cici.c"), this_object());
  }
}
