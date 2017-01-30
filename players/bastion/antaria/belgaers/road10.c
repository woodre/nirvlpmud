
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object sign;
     if(!present("sign")) {
          sign=clone_object("obj/treasure");
          sign->set_id("sign");
          sign->set_short("a sign");
          sign->set_long("The sign reads:\n\n"+
                         "    Sax Way: north and south\n"+
                         "    Harrowers Way: east and west\n");
          sign->set_read("Try looking at it\n");
          sign->set_weight(10000);
          move_object(sign, this_object());
     }
}


ONE_EXIT(
     "players/bastion/antaria/belgaers/road9", "east",
     "Crossroads",
     "Two roads meet here, a sign to document their passing. In the\n"+
     "brush near the roadside, you note a small humanoid skeleton.\n",
     1)
