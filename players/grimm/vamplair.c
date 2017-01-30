#include "/players/grimm/header"
#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET ex_reset();
ONE_EXIT(ROOT(alley3),"up",
         "Vampire Lair",
         "You have entered the lair of a blood thirsty vampire!  Apparently\n"
       + "this is the very same vampire who has been taking helpless victims\n"
       + "from the streets and draining them of thier blood.  In the corner\n"
       + "of the lair you see a large black coffin that must be his sleeping\n"
       + "chambers.\n",1)
ex_reset() {
   object weapon, vampire, armor;
   if(!present("vampire")) {
      vampire = clone_object(DIR8(vampire));
      weapon = clone_object(DIR3(sword1));
      armor = clone_object(DIR4(armor));
      move_object(weapon, vampire);
      move_object(armor,vampire);
      move_object(vampire, this_object());
   }
}
