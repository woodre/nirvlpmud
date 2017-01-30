
#include "std.h"

reset(arg) {
   if(!arg) 
     set_light(1);
   extra_reset();
}

object king, armor, boots, voulge;

extra_reset() {
   if(!present("king")) {
     king = clone_object("players/molasar/MONSTERS/king");
     armor = clone_object("players/molasar/ARMOR/scalemail");
     boots = clone_object("players/molasar/ARMOR/leather_boots");
     voulge = clone_object("players/molasar/WEAPONS/voulge");
     transfer(armor, king);
     transfer(boots, king);
     transfer(voulge, king);
     king->init_command("wear scalemail");
     king->init_command("wear boots");
     king->init_command("wield voulge");
     king->set_ac(12);
     king->set_wc(22);
     move_object(king, this_object());
   }
}

init() {
   add_action("east","east");
}

east() {
   this_player()->move_player("east#players/molasar/CASTLE/INNER/meeting");
   return 1;
}

short() { return "The King's audience chamber"; }

long() {
   write("This is the King's private audience chamber.  A large throne\n"+
         "is next to the west wall on a raised platform.  Many banners\n"+
         "and flags lie behind the throne.\n");
   write("   There is one obvious exit:  east\n");
}

