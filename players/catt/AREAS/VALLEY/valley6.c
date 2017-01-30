#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object missionary;
object aide;

   if(!present("missionary")) {
      missionary = clone_object(NPC+"VAL_missionary");
      move_object(missionary, this_object());
   }
   if (!present("aide")) {
      aide = clone_object(NPC+"VAL_aide");
      move_object(aide, this_object());
  }
}

ONE_EXIT(VALLEY+"valley5","west",
  
           "A small meeting place",
           "This is a secluded meeting place where missionaries come\n" +
        "to meet in privacy..... don't disturb them!\n", 1)


