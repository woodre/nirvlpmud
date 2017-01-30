inherit "room/room";

#include "defs.h"

void reset(int arg) {

  if(!present("sign"))  {
    MOCO("/players/jareel/general_stuff/wep_shop_sign.c"),this_object()); }
  if(!present("grizwald"))  {
    MOCO("/players/jareel/monsters/town/wep_shop_owner.c"),this_object()); }
  if (arg)
    return;

  set_light(1);
  short_desc=("The Weapons Smith");
  long_desc=
    "   This is a rather cramped weapons shop. Many weapons, some mundane\n"+
    "and some bizarre, line the room.  Near the rear of the store sits a\n"+
    "small counter with a steel box with a small sign set upon it.  The \n"+
    "door to the east will take you back outside to the road.\n";

  items = ({ ITEMS });

  dest_dir = ({
    "/players/jareel/areas/entrance/road10","east",
  });

}

