
#include "std.h"

reset(arg) {
     if(arg) return;
     set_light(1);
     extra_reset();
}

int i;
object gopher, money;

extra_reset() {
     i = 0;
     if(!present("gopher")) {
       while(i<6) {
       i += 1;
       gopher = clone_object("players/molasar/MONSTERS/gopher");
       money = clone_object("obj/money");
       money->set_money(random(100));
       move_object(money, gopher);
       move_object(gopher, this_object());
       }
     }
}

short() { return "A large open plain"; }

long() {
   write("A large open plain.  Paths lead off south, east, and west.\n");
   write("   There are three obvious exits:  south, east, and west\n");
}

init() {
   add_action("south","south");
   add_action("east","east");
   add_action("west","west");
}

south() {
   this_player()->move_player("south#players/molasar/PLAINS/plain20");
   return 1;
}

east() {
   this_player()->move_player("east#players/molasar/PLAINS/plain18");
   return 1;
}

west() {
   this_player()->move_player("west#players/molasar/PLAINS/plain27");
   return 1;
}

