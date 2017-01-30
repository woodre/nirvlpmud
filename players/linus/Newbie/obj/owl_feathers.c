#include "/players/linus/def.h"
inherit "/obj/treasure.c";
int mon;
id(str) { return str=="feathers" || str=="owl feathers"; }
reset(arg) {
 if(arg) return;
 set_short("Owl feathers");
 set_long("Some feathers that have been plucked from Owl's tail.  Traders\n"+
          "have been known to pay good money for owl feathers.\n");
 set_weight(1);
 set_value(200);
}
query_save_flag() { return 1; }
init() {
 ::init();
 add_action("pay_me","barter");
 mon = (350);
}
pay_me(str) {
 if(id(str)) {
if(present("hank_the_ugly_barter_dude",environment(TP))) {
write("Hank examines the feathers carefully, then grumbles: These come from a great\n"+
       "horned owl, a rather rare specimen!  I'll give ya "+mon+" coins for these\n");
 say("Hank takes the feathers from "+TPN+" and hands "+TPO+" some coins.\n");
 TP->add_money(mon);
 TP->add_weight(-1);
 destruct(TO);
 return 1;
}
 notify_fail("Do what?\n");
  return 0;
}
}
