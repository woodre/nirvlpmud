
#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

object lord, sword, oint;

extra_reset() {
   if(!present("lord")) {
     lord = clone_object("players/molasar/MONSTERS/elf_lord");
     sword = clone_object("players/molasar/WEAPONS/redsword");
     oint = clone_object("players/molasar/OBJ/red_oint");
     transfer(sword, lord);
     transfer(oint, lord);
     move_object(lord, this_object());
   }
}

short() { return "Inside a hut"; }

long() {
   write("You are inside the dwelling of an elvish lord.  Many garrish\n");
   write("paintings line the wall.  The place is immaculately well kept\n");
   write("and free of any debris.\n");
   write("   There is one obvious exit:  out\n");
}

init() {
   add_action("out","out");
}

out() {
   this_player()->move_player("out#players/molasar/FOREST/UPPER/plat9");
   return 1;
}

