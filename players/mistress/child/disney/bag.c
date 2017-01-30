#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
   if(!present("bag")); {\
      object bag;\
    bag = clone_object("obj/bag");\
    call_other(bag, "set_name", "A goofy bag");\
    call_other(bag, "set_short", "A goofy looking bag");\
    call_other(bag, "set_long", "It's a bag, what did you expect?\n");\
    call_other(bag, "set_alias", "bag");\
    call_other(bag, "set_weight", 1);\
    call_other(bag, "set_value", 10);\
    move_object(bag, "players/mistress/child/disney/bag");\
   } \

ONE_EXIT("players/mistress/child/disney/pluto","south",
   "Bag room",
   "\nA tree blocks your way.\n",1)
