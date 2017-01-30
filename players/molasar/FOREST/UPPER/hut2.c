
#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

object lord, armor;

extra_reset() {
   if(!present("lord")) {
     lord = clone_object("players/molasar/MONSTERS/elf_lord");
     armor = clone_object("players/molasar/ARMOR/elf_chain");
     transfer(armor, lord);
     lord->init_command("wear chainmail");
     lord->set_ac(10);
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
   this_player()->move_player("out#players/molasar/FOREST/UPPER/plat8");
   return 1;
}

