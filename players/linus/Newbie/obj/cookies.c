#include "/players/linus/def.h"
inherit "/obj/treasure.c";
int mon;
id(str) { return str == "cookies" || str == "chocolate cookies"; }
reset(arg) {
 if(arg) return;
 set_short("Chocolate cookies");
 set_long(
 "Some fresh-baked chocolate cookies.  They look delicious.\n");
 set_weight(1);
 set_value(100);
}
query_save_flag() { return 1; }
init () {
 ::init();
    add_action ("eat_cookies","eat");
    add_action("pay_me","barter");
    mon = (150+random(100));
     }
eat_cookies(str) {
if(!id(str)) { notify_fail("Eat what?\n");
 return 0; }
     this_player()->heal_self(5);
   write("You hungrily eat the chocolate cookies.\n");
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
}
pay_me(str) {
 if(id(str)) {
 if(present("hank_the_ugly_barter_dude",environment(TP))) {
 write("Hank's eyes light up.  He then grabs the cookies and tosses\n"+
       mon+" coins into your hand.\n");
 say("Hank takes the cookies from "+TPN+" and tosses "+TPO+" some coins.\n");
 TP->add_money(mon);
 TP->add_weight(-1);
 destruct(TO);
 return 1;
}
}
}
