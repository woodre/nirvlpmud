#include "defs.h"

status main(string str, int glevel) {
  notify_fail("This command has been disabled, possibly only temporarily.\n-Earwax\n");
  return 0;
}
/*
   
    me = this_player()->query_name();

   if(str == "guardian") {
   if(this_player()->query_spell_point() < 20) {
     write("You are too low on power.\n");
     return 1;
   }
   demon = clone_object("players/angel/masons/guardian");
   dest = environment(this_player());
   write("You summon a guardian demon.\n");
   say(capitalize(me)+" utters an encantation and a large guardian demon "+
      "appears in a puff of smoke.\n");
   demon->set_owner(this_player()->query_real_name());
   move_object(demon, dest);
   this_player()->add_spell_point(-20);
   return 1;
   }
   if(str == "djinni") {
      if(this_player()->query_spell_point() < 20) {
        write("You are too low on power.\n");
        return 1;
      }
      write("You summon a Djinni.\n");
      say(capitalize(me)+" speaks an incantation and a Djinni appears "+
         "in a puff of smoke.\n");
      this_player()->add_spell_point(-20);
      demon = clone_object("players/angel/masons/djinni");
      dest = environment(this_player());
      demon->set_owner(this_player()->query_real_name());
      move_object(demon, dest);
      return 1;
    }
}
*/
