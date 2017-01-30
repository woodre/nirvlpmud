#include "std_old.h"

object scotty;

extra_reset() {
   object weapon;
    if (!present("scotty")) {
	scotty = clone_object("players/rich/lower/sco.c");
       move_object(scotty,this_object());
     }
    }
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

ONE_EXIT("players/rich/lower/hall1d", "north",

         "Main Engineering",
         "This is main engineering,along the walls you\n" +
         "see the various components of the\n" +
         "impulse and warp drives and various other\n" +
         "systems such as the main anti-matter reactor.\n" +
         "To the north you see a hallway.\n",
         1)
realm(){return "enterprise";}
is_castle() {return 1;}
