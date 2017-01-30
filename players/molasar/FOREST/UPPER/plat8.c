
#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

object elf, sword, shield;

extra_reset() {
   if(!present("elf")) {
     elf = clone_object("players/molasar/MONSTERS/elf_guard");
     sword = clone_object("players/molasar/WEAPONS/sword");
     shield = clone_object("players/molasar/ARMOR/shield");
     transfer(sword, elf);
     transfer(shield, elf);
     elf->init_command("wear shield");
     elf->init_command("wield sword");
     move_object(elf, this_object());
   }
}

short() { return "A platform"; }

long() {
   write("This is the southern most platform.  A small hut is near the \n");
   write("southern edge of the platform.\n");
   write("   There are three obvious exits:  northeast, northwest, and in\n");
}

init() {
   add_action("in","in");
   add_action("northwest","northwest");
   add_action("northeast","northeast");
}

in() {
   if(present("elf")) {
     write("The guard says:  You have no business in there.\n");
     return 1;
   }
   this_player()->move_player("into the hut#players/molasar/FOREST/UPPER/hut2");
   return 1;
}

northeast() {
   this_player()->move_player("northeast#players/molasar/FOREST/UPPER/plat5");
   return 1;
}

northwest() {
   this_player()->move_player("northwest#players/molasar/FOREST/UPPER/plat2");
   return 1;
}

