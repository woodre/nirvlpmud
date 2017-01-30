
#include "std.h"

int found;
object medal;

id(str) { return str == "rocks"; }

reset(arg) {
   if(!arg)
     set_light(1);
   found = 0;
}

init() {
   if(!present("qstob", this_player())) {
     write("You do not go by the right path.\n");
     move_object(this_player(), "/room/church");
     return 1;
   }
   add_action("search_rocks","search");
   add_action("search_rocks","examine");
   add_action("search_rocks","exa");
   add_action("west","west");
   add_action("church","church");
}

west() {
   this_player()->move_player("west#players/molasar/SEA/cave1");
   return 1;
}

church() {
   destruct(present("qstob", this_player()));
   this_player()->move_player("away#room/church");
   return 1;
}

short() { return "A cave"; }

long(str) {
   if(str == "rocks") {
     write("A large pile of rocks.\n");
     return 1;
   }
   write("You have entered a large cave.  There is a pile of rocks\n"+
         "lying against the wall to the north.\n");
   write("   There are two obvious exits:  west and church\n");
}

search_rocks(str) {
   if(str != "rocks") {
     write("Search what?\n");
     return 1;
   }
   if(found == 1) {
     write("You find nothing.\n");
     return 1;
   }
   write("You find a gold medallion!\n");
   medal = clone_object("players/molasar/ARMOR/medallion");
   move_object(medal, this_player());
   write("Congratulations!  You have completed this quest.\n");
   this_player()->set_quest("medallion");
   found = 1;
   return 1;
}


