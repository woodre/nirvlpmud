#include "/players/beck/esc.h"

id(str) { return str=="balloon" || str=="balloon"; }
reset () {}
short() {
   return "A "+BOLD+RED+"Red"+OFF+" Hot Air Balloon";
}
long() {
   write("A giant balloon for going places.  Try to take a 'ride'.\n");
}
init() {
   add_action("ride","ride");
}
ride(arg) {
   if(!arg){write("What do you want to ride?\n"); return 1;}
   if(arg !="balloon"){write("You can only ride the balloon.\n"); return 1;}
   write("You step into the balloon and take a relaxing ride.\n"+
      "As the balloon rises you begin to feel a gentle breeze.\n"+
      "Soon, however, the wind becomes strong and takes the balloon\n"+
      "out of your control.  You sail helplessly along the tradewinds.\n"+
      "");
   call_other(this_player(),"move_player","ride#/players/beck/room/venus1.c");
   return 1;
}
get() {
   tell_object(this_player(), "There's no way you can pick up the balloon.\n");
   return 0;
}
query_weight() { return 0; }
query_value() { return 5000; }
