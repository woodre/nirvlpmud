inherit "obj/treasure.c";
#include "/players/linus/def.h"
int mon;
id(str) { return str=="foot" || str=="rabbit foot" || str=="rabbits foot"; }
reset(arg) {
 if(arg) return;
 set_short("Rabbit foot");
 set_long(
"A rabbit foot.  It has been said that the foot of a rabbit is\n"+
"considered to be lucky.  Apparently not for the rabbit!\n");
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
 write("Hank looks at the foot and grins.  'A \"lucky\" rabbit's foot.  I have\n"+
       "a buyer for these.'  He then drops "+mon+" coins into your open hand.\n");
say("Hank takes the foot from "+TPN+", dropping some coins into "+TPP+" hand.\n");
 TP->add_money(mon);
 TP->add_weight(-1);
 destruct(TO);
 return 1;
}
 notify_fail("Do what?\n");
  return 0;
}
}
