
#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

object elf, shield, weap;
int i;

extra_reset() {
   i = 0;
   if(!present("elf")) {
    while(i<2) {
     i += 1;
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
}


short() { return "A forest"; }

long() {
   write("You are in a great forest.\n");
   write("   There are three obvious exits:  north, east, and west\n");
}

init() {
   add_action("north","north");
   add_action("east","east");
   add_action("west","west");
}

north() {
   this_player()->move_player("north#players/molasar/FOREST/forest13");
   return 1;
}

east() {
   this_player()->move_player("east#players/molasar/FOREST/forest17");
   return 1;
}

west() {
   this_player()->move_player("west#players/molasar/FOREST/forest11");
   return 1;
}

