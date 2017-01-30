
#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

object elf, sword;
int i;

extra_reset() {
  i = 0;
   if(!present("elf")) {
     while(i<2) {
       i += 1;
       elf = clone_object("players/molasar/MONSTERS/elf_guard");
       sword = clone_object("players/molasar/WEAPONS/sword");
       transfer(sword, elf);
       elf->init_command("wield sword");
       elf->set_ac(10);
       move_object(elf, this_object());
     }
   }
}

short() { return "Entrance room"; }

long() {
   write("This is the entrance room to the chambers of the King of the city.\n");
   write("The chambers lies to the southeast, while the exit to the lower\n");
   write("level of the city id southeast.\n");
   write("   There are two obvious exits:  southeast and southwest\n");
}

init() {
   add_action("southeast","southeast");
   add_action("southwest","southwest");
}

southeast() {
   this_player()->move_player("southeast#players/molasar/FOREST/UPPER/plat12");
   return 1;
}

southwest() {
   this_player()->move_player("southwest#players/molasar/FOREST/UPPER/plat10");
   return 1;
}

