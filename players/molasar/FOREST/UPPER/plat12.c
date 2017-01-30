
#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

object elf, sword;

extra_reset() {
   if(!present("elf")) {
     elf = clone_object("players/molasar/MONSTERS/elf_king");
     sword = clone_object("players/molasar/WEAPONS/elfsword");
     transfer(sword, elf);
     elf->init_command("wield elven longsword");
     move_object(elf, this_object());
   }
}

short() { return "King's chambers"; }

long() {
   write("You have entered the King's chambers.  There is a huge chair\n");
   write("near the east wall in from of a table.  Many blueprints for\n");
   write("expansion of the city cover the table.\n");
   write("   There is one obvious exit:  northwest\n");
}

init() {
   add_action("northwest","northwest");
}

northwest() {
   this_player()->move_player("northwest#players/molasar/FOREST/UPPER/plat11");
   return 1;
}

