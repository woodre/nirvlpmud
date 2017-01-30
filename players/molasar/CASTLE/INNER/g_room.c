
#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

int i;
object kguard, armor, helmet, shield, sword;

extra_reset() {
   i = 0;
   if(!present("kguard")) {
     while(i<2) {
     i += 1;
     kguard = clone_object("players/molasar/MONSTERS/kguard");
     sword = clone_object("players/molasar/WEAPONS/shortsword");
     armor = clone_object("players/molasar/ARMOR/leather_armor");
     helmet = clone_object("players/molasar/ARMOR/helmet");
     shield = clone_object("players/molasar/ARMOR/shield");
     transfer(sword, kguard);
     transfer(shield, kguard);
     transfer(helmet, kguard);
     transfer(armor, kguard);
     kguard->init_command("wield shortsword");
     kguard->init_command("wear shield");
     kguard->init_command("wear helmet");
     kguard->init_command("wear leather armor");
     move_object(kguard, this_object());
     }
   }
}

init() {
   add_action("north","north");
}

north() {
   this_player()->move_player("north#players/molasar/CASTLE/INNER/meeting");
   return 1;
}

short() { return "Guard's room"; }

long() {
   write("This is the resting room for the King's guards.  A small table "+
         "\nand cot lie near the southern wall of the room.\n");
   write("   There is one obvious exit:  north\n");
}

