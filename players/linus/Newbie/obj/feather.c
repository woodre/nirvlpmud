#include "/players/linus/def.h"
inherit "/obj/treasure.c";
int mon;
id(str) { return str=="feather" || str=="bird feather" || str=="blue bird feather"; }
reset(arg) {
 if(arg) return;
 set_short("A "+HIB+"blue"+NORM+" feather");
 set_long("A small "+HIB+"blue"+NORM+" feather, which has been plucked from a\n"+
 HIB+"blue bird's"+NORM+" tail.\n");
 set_weight(1);
 set_value(90);
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
write("Hank takes the feather, then grumbles: I'll give ya "+mon+" coins for\n"+
       "it.\n");
 say("Hank takes the feather from "+TPN+" and hands "+TPO+" some coins.\n");
 TP->add_money(mon);
 TP->add_weight(-1);
 destruct(TO);
 return 1;
}
 notify_fail("Do what?\n");
  return 0;
}
}
