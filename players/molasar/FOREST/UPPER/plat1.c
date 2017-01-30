
#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

object elf, armor, shield, weap;
int i;

extra_reset() {
   i = 0;
   if(!present("elf")) {
     while(i<2) {
       i += 1;
       elf = clone_object("players/molasar/MONSTERS/elf_guard");
       armor = clone_object("players/molasar/ARMOR/leather_armor");
       shield = clone_object("players/molasar/ARMOR/shield");
       weap = clone_object("players/molasar/WEAPONS/guisarme");
       transfer(armor, elf);
       transfer(shield, elf);
       transfer(weap, elf);
       elf->init_command("wear leather armor");
       elf->init_command("wield guisarme");
       elf->init_command("wear shield");
       move_object(elf, this_object());
     }
   }
}

short() { return "Atop a platform"; }

long() {
   write("This is the first platform you reach upon entering the city.\n");
   write("Two small walkways lead to platforms to the northeast and the\n");
   write("southeast.  This platform mainly serves as a check point.\n");
   write("   There are three obvious exits:  west, northeast, and southeast\n");
}

init() {
   add_action("west","west");
   add_action("northeast","northeast");
   add_action("southeast","southeast");
}

west() {
   this_player()->move_player("west#players/molasar/FOREST/UPPER/entry");
   return 1;
}

northeast() {
   if(present("guard") && this_player()->query_alignment() < 0) {
     write("The guard says:  I think you better leave.\n"+
           "                 We don't want any trouble from you.\n");
     return 1;
   }
   this_player()->move_player("northeast#players/molasar/FOREST/UPPER/plat4");
   return 1;
}

southeast() {
   if(present("guard") && this_player()->query_alignment() < 0) {
     write("The guard says:  I think you better leave.\n"+
           "                 We don't want any trouble from you.\n");
     return 1;
   }
   this_player()->move_player("southeast#players/molasar/FOREST/UPPER/plat2");
   return 1;
}

