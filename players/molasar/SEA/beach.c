
#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
}

init() {
   add_action("up","up");
   add_action("sail","sail");
}

up() {
   this_player()->move_player("up#players/molasar/SEA/cliff2");
   return 1;
}

sail() {
   object ob;
   ob = present("boat");
   if(!ob) {
     write("How do you expect to sail without a boat?\n");
     return 1;
   }
   if(ob->query_placed() == 0) {
     write("The boat is not placed for sailing.\n");
     return 1;
   }
   write("You climb into the boat and go across the sea.\n");
   say(capitalize(this_player()->query_name())+" climbs into the boat "+
      "and sails away.\n");
   move_object(this_player(), "/players/molasar/SEA/sea");
   destruct(ob);
   return 1;
}

short() { return "A beach"; }

long() {
   write("You are on a sandy beach.  A large cliff is to the east.  You\n"+
         "notice a small trail that winds its way up the cliff.\n");
   write("A vast sea extends itself westward.\n");
   write("   There is on obvious exit:  up\n");
}


