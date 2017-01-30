#include "std.h"
object grenade;
reset(arg) {
   int x;
   if (!arg) {
      set_light(1);
   }
if (!grenade || !present(grenade))
   x = random(1) + 1;
   while (x > 0) {
      grenade = clone_object("/players/blackadder/grenade");
      move_object(grenade,this_object());
      x = x - 1;
   }
}

long(str) {
   if (str == "door") {
      if (call_other("/players/blackadder/armory","query_door"))
         write("The door is closed.\n");
      else
         write("The door is open.\n");
      return;
   }
   write("You are in the armory vault.\n");
}

short() {
   return "armory vault";
}

init() {
   add_action("east","east");
   add_action("open","open");
}

east() {
   if (call_other("/players/blackadder/armory","query_door")) {
      write("The door is closed.\n");
      return 1;
   }
   call_other(this_player(), "move_player","east#/players/blackadder/armory");
   return 1;
}

open(str) {
   if (!str) return 0;
   if (!call_other("/players/blackadder/armory", "query_door"))
      return 0;
   call_other("/players/blackadder/armory","open_door_inside");
   say(call_other(this_player(), "query_name") +
      " opens the door.\n");
   write("Ok.\n");
   return 1;
}
