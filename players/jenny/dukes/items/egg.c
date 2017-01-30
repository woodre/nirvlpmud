/*
*actual value of the heal is 135

*/
#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("egg");
   set_alias("chicken egg");
   set_short("an egg");
   set_long(
      "This is a recently laid chicken egg.  It has a white shell.  The\n"+
      "Dukes make a little extra money by selling the eggs they don't\n"+
      "use.  You could "+CYN+"eat egg."+NORM+"\n");
   set_weight(1);
   set_value(95);
   set_dest_flag(1);
}
init() {
   ::init();
   add_action("egg","eat");
}
egg(arg) {
   if(arg == "egg") {
      if(!arg) { return 0; }
      if(!TP->eat_food(2)) {
         write("You are too full to eat an egg.\n");
      }
      write(YEL+"You eat the egg and feel better."+NORM+"\n");
      TP->add_hit_point(18);
      destruct(this_object()); TP->recalc_carry();
      return 1; }
}
