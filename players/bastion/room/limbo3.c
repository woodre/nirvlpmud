
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object ob, mon;
     if(!present("glabrezu")) {
          ob=clone_object("players/bastion/monster/demon3");
          mon=clone_object("obj/money");
          mon->set_money(750 + random(300));
          move_object(mon, ob);
          move_object(ob, this_object());
     }
     return 1;
}

ONE_EXIT("players/bastion/room/limbo2", "east",
     "Limbo",
     "You are floating in the timeless continuum of limbo. Asteroids,\n"+
     "galaxies and more terrestrial bits of matter form the firmament\n"+
     "about you.\n",
     1)
