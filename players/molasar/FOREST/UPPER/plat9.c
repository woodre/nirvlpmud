
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
   write("This is the northern most platform.  A small hut is near the \n");
   write("northern edge of the platform.\n");
   write("   There are three obvious exits:  southeast, southwest, and in\n");
}

init() {
   add_action("in","in");
   add_action("southwest","southwest");
   add_action("southeast","southeast");
}

in() {
   if(present("elf")) {
     write("The guard says:  You have no business in there.\n");
     return 1;
   }
   this_player()->move_player("into the hut#players/molasar/FOREST/UPPER/hut1");
   return 1;
}

southeast() {
   this_player()->move_player("southeast#players/molasar/FOREST/UPPER/plat7");
   return 1;
}

southwest() {
   this_player()->move_player("southwest#players/molasar/FOREST/UPPER/plat4");
   return 1;
}

