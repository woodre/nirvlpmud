
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
                         "    Harrowers Way: east and west\n");
          sign->set_read("Try looking at it\n");
          sign->set_weight(10000);
          move_object(sign, this_object());
     }
}

TWO_EXIT(
     "players/bastion/antaria/belgaers/road6", "east",
     "players/bastion/antaria/belgaers/road8", "west",
     "Crossroads",
     "You come upon the intersection of two roads, stretching out into\n"+
     "the wilderness. A sign is here.\n",
     1)
