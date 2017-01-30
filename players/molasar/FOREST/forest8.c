
#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

object elf, shield, weap;

extra_reset() {
   if(!present("elf")) {
     elf = clone_object("players/molasar/MONSTERS/elf_soldier");
     shield = clone_object("players/molasar/ARMOR/shield");
     weap = clone_object("players/molasar/WEAPONS/guisarme");
     transfer(shield, elf);
     transfer(weap, elf);
     elf->init_command("wear shield");
     elf->init_command("wield guisarme");
     move_object(elf, this_object());
   }
}


short() { return "A forest"; }

long() {
   write("You are in a great forest.\n");
   write("   There are two obvious exits:  east, and west\n");
}

init() {
   add_action("east","east");
   add_action("west","west");
}

east() {
   this_player()->move_player("east#players/molasar/FOREST/forest9");
   return 1;
}

west() {
   this_player()->move_player("west#players/molasar/FOREST/forest7");
   return 1;
}

