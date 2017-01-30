
#include "/players/molasar/rowan/room/exit.h"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object priest, mage;
   int i, n;
   if(!present("dragonman")) {
     i = 0;  
     while(i < 3) {
       priest = clone_object("players/molasar/rowan/monsters/d_priest");
       move_object(priest, this_object());
       i++;
     }
     n = 0;
     while(n < 2) {
       mage = clone_object("players/molasar/rowan/monsters/d_mage");
       move_object(mage, this_object());
       n++;
     }
   }
}

id(str) { return str == "altar"; }

short() { return "An underground temple"; }

long(str) {
  if(str == "altar") {
    write("The altar is made of stone.  It is actually a very poor\n");
    write("excuse for an altar, being basically a huge block of\n");
    write("granite.\n");
    return 1;
  }
  write("This is an underground temple used by the Dragonmen Priest\n");
  write("to worship their leader the Great Dragon Andriakas.\n");
  write("A large altar is next to the western wall.  To the east\n");
  write("a large opening leads into what appears an immense\n");
  write("underground cavern.\n");
  write("     There are two obvious exits:  north and east\n");
}

init() {
   add_exit("north","/players/molasar/rowan/mtn/wunder5");
   add_exit("east","/players/molasar/rowan/mtn/lair");
}

move() {
   string verb;

   verb = query_verb();
   if(verb == "north") {
     this_player()->move_player("north#players/molasar/rowan/mtn/wunder5");
     return 1;
   }
   if(verb == "east") {
     if(present("dragonman")) {
       write("A dragonman yells: YOU MAY NOT HARM OUR LORD!\n");
       return 1;
     }
     this_player()->move_player("east#players/molasar/rowan/mtn/lair");
     return 1;
   }
}

