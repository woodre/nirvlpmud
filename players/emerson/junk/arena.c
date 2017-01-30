#include "std.h"
init() {
   add_action("remove_ghost","pray");
   set_light( 1);
   this_player()->set_fight_area();
}
short() {
   return "The Champions Arena";
}
long() {
   write("You are in the Champions arena.  This means you must fight well or\n"+
      "die.  You are strong however, having a blood scar is a sign of greatness.\n"+
      "May you fight well and increase your knowledge of battle.\n");
   write("There are no obvious exits.\n");
}

remove_ghost() {
   if(this_player()->query_ghost() > 0) {
      int xp,newxp;
      xp = this_player()->query_exp();
      newxp = xp*4;
      newxp = newxp/3;
      newxp = newxp - xp;
      call_other(this_player(),"add_exp",newxp);
      return call_other(this_player(), "remove_ghost",0);
      return 1;
   }
   
}
