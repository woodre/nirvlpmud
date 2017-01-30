
#include "std.h"

int found;
object amulokt;

id(str) { return str == "rift"; }

reset(arg) {
   if(!arg)
     set_light(1);
   found = 0;
}

init() {
   if(!present("Hood of masters", this_player())) {
   write("A voice echoes in your mind: You have not what it takes to enter.\n");
   move_object(this_player(), "/room/church");
   return 1;
   }
   add_action("search_rift","search");
   add_action("search_rift","examine");
   add_action("search_rift","exa");
   add_action("south","south");
}

south() {
   command("drop all",this_player());
   this_player()->move_player("south#room/sea");
   return 1;
}

church() {
   destruct(present("Hood of masters", this_player()));
   this_player()->move_player("away#room/church");
   return 1;
}

short() { return "Inner Chamber"; }

long(str) {
   if(str == "rift") {
     write("A rift in the fabric of space.\n");
     return 1;
   }
   write("You have entered the inner chamber of the Masters.\n");
   write("you see absolutely nothing but a small rift in the center\n");
   write("of the room. A tremendous force is at work here.\n");
   write("   There is one obvious exit:  south\n");
}

search_rift(str) {
   if(str != "rift") {
     write("Search what?\n");
     return 1;
   }
   if(found == 1) {
     write("You find nothing.\n");
     return 1;
   }
   write("You stick your hands into the rift...\n");
   write("...and pull out a strange object.\n");
   write("You've found the powerful amulokt!\n");
   amulokt = clone_object("players/cyrex/quest/amulokt");
   move_object(amulokt, this_player());
   found = 1;
   return 1;
}
