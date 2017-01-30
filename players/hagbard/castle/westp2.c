#include "room.h"
object howard, weapon;


extra_reset() {

    if(!howard || !living(howard) || !present("dolphin")) {
      howard = clone_object("obj/monster");
      call_other(howard, "set_name", "howard");
      call_other(howard, "set_alias", "dolphin");
      call_other(howard, "set_short", "Howard the dolphin");
      call_other(howard, "set_long", "Howard the dolphin.  He is singing"
      + " merrily.\n");
      call_other(howard, "set_al", 400);
      call_other(howard, "set_level", 5);
      call_other(howard, "set_hp", 120);
      move_object(howard, this_object());
}
}

#undef EXTRA_RESET
#define EXTRA_RESET\
   extra_reset();


TWO_EXIT("/players/hagbard/castle/westp", "east",
         "players/hagbard/sub/contower", "north",
"You are in a strange looking room.",
"You are in a strange looking place.  You look out through a window into what\n"
+
"you perceive as the ocean.  You see a dolphin.  He is singing.  He tells you\n"
+
"his name is Howard and how he hates sharks or something to that effect.\n",1)
