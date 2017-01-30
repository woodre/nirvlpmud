#include "/players/linus/def.h"
inherit "/obj/armor.c";
int mon;

id(str) { return (::id(str) || str=="shell" || str=="turtle shell"); }

reset (arg) {
  ::reset(arg);
 set_name("Turtle shell");
 set_alias("shell");
 set_short(GRN+"Turtle shell"+NORM);
 set_long(GRN+
  "Once a home to a little turtle, the shell is now empty.\n"+NORM);
 set_weight(1);
 set_value(125);
 set_type("armor");
 set_ac(1);
}

query_save_flag() { return 1; }

init() {
  ::init();
 add_action("pay_me","barter");
 }

pay_me(str){
 mon = (150+random(100));
 if(id(str)) {
if(present("hank_the_ugly_barter_dude",environment(TP))) {
write("Hank stares at you a moment, then grumbles: I'll give ya "+mon+" coins for\n"+
       "this shell.  He hands you the coins and places the shell into his pack.\n");
 say("Hank takes the shell from "+TPN+" and hands "+TPO+" some coins.\n");
 TP->add_money(mon);
 TP->add_weight(-1);
 destruct(TO);
 return 1;
}
 notify_fail("Do what?\n");
  return 0;
 }
}
 
