
#include "/players/molasar/rowan/room/exit.h"

int found;

reset(arg) {
   if(!arg)
     set_light(1);
   found = 0;
   extra_reset();
}

extra_reset() {
   object priest, mage;
   int i;
   if(!present("priest")) {
     priest = clone_object("players/molasar/rowan/monsters/d_priest");
     move_object(priest, this_object());
   }
   if(!present("mage")) {
     i = 0;
     while(i < 2) {
       mage = clone_object("players/molasar/rowan/monsters/d_mage");
       move_object(mage, this_object());
       i += 1;
     }
   }
}

short() { return "A large office"; }

id(str) { return str == "desk" || str == "bookcase"; }

long(str) {
   object key;
   if(str == "bookcase") {
     write("You search through bookcase but find nothing of interest.\n");
     return 1;
   }
   if(str == "desk") {
     if(found) {
       write("You search the desk but find nothing of interest.\n");
       return 1;
     }
     key = clone_object("obj/treasure");
     key->set_id("key");
     key->set_alias("mol_chest_key");
     key->set_short("A rusted key");
     key->set_value(100);
     move_object(key, this_player());
     write("You find a rusted key under some papers.\n");
     say(capitalize(this_player()->query_name())+" finds a key in "+
        "the desk.\n");
     found = 1;
     return 1;
   }
   write("You have entered what appears to be a large office.\n");
   write("A desk and bookcase are set against the western\n");
   write("wall. To the east is a small storage room.\n");
   write("     There are two obvious exits:  south and east\n");
}

init() {
   add_exit("south","/players/molasar/rowan/mtn/wunder3");
   add_exit("east","/players/molasar/rowan/mtn/wroom2");
}

move() {
   string verb;

   verb = query_verb();
   if(verb == "south") {
     this_player()->move_player("south#players/molasar/rowan/mtn/wunder3");
     return 1;
   }
   if(verb == "east") {
     this_player()->move_player("east#players/molasar/rowan/mtn/wroom2");
     return 1;
   }
}

