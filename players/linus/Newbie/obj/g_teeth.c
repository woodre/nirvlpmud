inherit "obj/treasure.c";
#include "/players/linus/def.h"
int mon;
id(str) { return str=="teeth" || str=="gopher teeth" || str=="tooth"; }
reset(arg) {
 if(arg) return;
 set_short("Gopher teeth");
 set_long(
"The front teeth of a gopher.  There are still bits of radish stuck to them.\n");
 set_weight(1);
 set_value(100);
}
 query_save_flag() { return 1; }
init() {
 ::init();
 add_action("pay_me","barter");
 mon = (150+random(100));
}
pay_me(str) {
 if(id(str)) {
if(present("hank_the_ugly_barter_dude",environment(TP))) {
 write("You show Hank the teeth.  He stares at them for a moment then grumbles:  I\n"+
       "know someone who makes fine jewellry from these.  He then hands you "+mon+" coins\n"+
       "and places the teeth in his pocket.\n");
say("Hank takes the teeth from "+TPN+" and hands "+TPO+" some coins.\n");
 TP->add_money(mon);
 TP->add_weight(-1);
 destruct(TO);
 return 1;
}
 notify_fail("Do what?\n");
  return 0;
}
}
