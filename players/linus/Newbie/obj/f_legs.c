#include "/players/linus/def.h"
inherit "/obj/treasure.c";
int mon;
id(str) { return str == "legs" || str == "frog legs"; }
reset(arg) {
 if(arg) return;
 set_short(GRN+"Frog legs"+NORM);
 set_long(GRN+
  "The legs of a frog.  They appear edible.\n"+NORM);
 set_weight(1);
 set_value(50);
}
query_save_flag() { return 1; }
init () {
 ::init();
     add_action ("eat_legs","eat");
    add_action("pay_me","barter");
    mon = (70+random(40));
     }
eat_legs(str) {
if(!id(str)) { notify_fail("Eat what?\n");
 return 0; }
     this_player()->heal_self(5);
   write("You wolf down the frog legs.\n");
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
}
pay_me(str) {
 if(id(str)) {
 if(present("hank_the_ugly_barter_dude",environment(TP))) {
 write("Hank eyes you suspiciously, then grumbles: I'll give ya "+mon+" coins for\n"+
       "these legs.  He hands you the coins and hungrily eats the legs.\n");
 say("Hank takes the legs from "+TPN+" and hands "+TPO+" some coins.\n");
 TP->add_money(mon);
 TP->add_weight(-1);
 destruct(TO);
 return 1;
}
}
}
