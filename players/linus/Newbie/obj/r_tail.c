inherit "obj/treasure.c";
#include "/players/linus/def.h"
int mon;
id(str) { return str=="tail" || str=="raccoon tail" || str=="coon tail"; }
reset(arg) {
 if(arg) return;
 set_short("Raccoon tail");
 set_long(
 "A black and grey ringed tail from a raccoon.\n");
 set_weight(1);
 set_value(100);
}
 query_save_flag() { return 1; }
init() {
 add_action("pay_me","barter");
 mon = (150+random(100));
}
pay_me(str) {
 if(id(str)) {
if(present("hank_the_ugly_barter_dude",environment(TP))) {
 write("Hank eyes you suspiciously, then grumbles: I'll give ya "+mon+" coins for\n"+
       "this tail.  He hands you the coins and places the tail into his pocket.\n");
 say("Hank takes the tail from "+TPN+" and hands "+TPO+" some coins.\n");
 TP->add_money(mon);
 TP->add_weight(-1);
 destruct(TO);
 return 1;
}
 notify_fail("Do what?\n");
  return 0;
}
}
