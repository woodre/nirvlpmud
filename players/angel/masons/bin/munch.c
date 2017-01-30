#include "defs.h"

status main(string str, int glevel) {
   object target;

   if(!str || str != "corpse") {
      notify_fail("Usage: munch corpse\n");
      return 0;
   }
   target = present("corpse",environment(this_player()));
   if(!target) {
      notify_fail("You see no corpse to munch on.\n");
      return 0;
   }
   if(this_player()->query_spell_point() < MUNCH_COST) {
      notify_fail("You do not have the needed sp to munch a corpse.\n");
      return 0;
   }
   write("You whip out your Jeff Dahmer cook book, and find the correct\n");
   write("recipe. Performing a magical gesture the corpse becomes a meal.\n");
   write("You dig in and eat.\n");
   destruct(target);
   this_player()->heal_self(MUNCH_HEAL);
   this_player()->add_spell_point(-MUNCH_COST);
   return 1;
}
