inherit "room/room";

#include "defs.h"

void reset(int arg) {

  if(!present("sign"))  {
    MOCO("/players/jareel/general_stuff/heal_shop_sign.c"),this_object()); }
  if(!present("azzared"))  {
    MOCO("/players/jareel/monsters/town/heal_shop_owner.c"),this_object()); }
  if (arg)
    return;

  set_light(1);
  short_desc=("The healing salve");
  long_desc=
    "  You have entered a healing shop. Lining stone walls are several\n"+
    "shelves and strata, each covered with multi-colored potions and\n"+
    "mystical vines.  Near the rear of the store a steel box and a wood\n"+
    "sign sits on the counter.  The door to the east leads back to the\n"+
    "road outside.\n";

  items = ({ ITEMS });

  dest_dir = ({
    "/players/jareel/areas/entrance/road9","east",
  });

}

