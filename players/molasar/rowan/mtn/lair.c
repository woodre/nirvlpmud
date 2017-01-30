
#include "/players/molasar/rowan/room/exit.h"
#define TRGEN "/players/molasar/rowan/obj/tr_gen"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object dragon, sword;
   if(!present("dragon")) {
     dragon = clone_object("players/molasar/rowan/monsters/dragon");
     TRGEN->get_magic2(dragon);
     TRGEN->get_magic3(dragon);
     TRGEN->get_magic4(dragon);
     TRGEN->get_magic5(dragon);
     TRGEN->get_scroll1(dragon);  
     TRGEN->get_scroll1(dragon);
     sword = clone_object("players/molasar/rowan/arms/mor_sword");
     move_object(sword, dragon);
     move_object(dragon, this_object());
   }
}

id(str) { return str == "trash"; }

short() { return "The lair of the Great Dragon, Andriakas"; }

long(str) {
   if(str == "trash") {
     write("You find nothing of interest in the scattered debris.\n");
     return 1;
   }
   write("You are in the lair of Andriakas, the magical dragon\n");
   write("created by the Overfiend to wreak havoc on the town\n");
   write("of Rowan.  The stench in the place is unbearable.\n");
   write("Trash and filth cover every inch of the room.\n");
   write("     There is on obvious exit:  west\n");
}

init() {
   add_exit("west","/players/molasar/rowan/mtn/temple");
}

move() {
   string verb;

   verb = query_verb();
   if(verb == "west") {
     this_player()->move_player("west#players/molasar/rowan/mtn/temple");
     return 1;
   }
}


