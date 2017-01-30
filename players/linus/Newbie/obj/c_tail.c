inherit "obj/treasure.c";
#include "/players/linus/def.h"
int mon;
id(str) { return str=="tail" || str=="chipmunk tail" || str=="munk tail"; }
reset(arg) {
 if(arg) return;
 set_short("Chipmunk tail");
 set_long(
  "The tail from a chipmunk.  It is brown in color, with a small black stripe\n"+
  "that runs the length of it.\n");
 set_weight(1);
 set_value(100);
}
 query_save_flag() { return 1; }
init() {
 ::init();
 add_action("pay_me","barter");
 mon = (100+random(100));
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
