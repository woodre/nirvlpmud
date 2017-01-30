
#include "/players/molasar/rowan/room/exit.h"

reset(arg) {
   if(!arg)
     set_light(0);
   extra_reset();
}

extra_reset() {
   object guard;
   object mage;
   int i;
   i = 0;
   if(!present("dragonman")) {  
     while(i < 3) {
       guard = clone_object("players/molasar/rowan/monsters/d_guard");
       move_object(guard, this_object());
       i += 1;
     }
     mage = clone_object("players/molasar/rowan/monsters/d_mage");
     move_object(mage, this_object());
   }
}

id(str) { return str == "bunk" || str == "bunks" ||
                 str == "locker" || str == "lockers"; }

short() { return "Guard Barracks"; }

long(str) {
   if(str == "bunk" || str == "bunks" || 
                                      str == "locker" || str == "lockers") {
     write("You search but find nothing of interest.\n");
     return 1;
   }
   write("You are in the guard's barracks.\n");
   write("Rows of bunks and lockers line the room making it difficult\n");
   write("to move around in.\n");
   write("     There is one obvious exit:  east\n");
}

init() {
   add_exit("east","/players/molasar/rowan/mtn/eroom1");
}

move() {
  string verb;

  verb = query_verb();
  if(verb == "east") {
    this_player()->move_player("east#players/molasar/rowan/mtn/eroom1");
    return 1;
  }
}

