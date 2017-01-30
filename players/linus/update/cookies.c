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
     }
eat_cookies(str) {
if(!id(str)) { notify_fail("Eat what?\n");
 return 0; }
     this_player()->heal_self(20);
   write("You hungrily eat the chocolate cookies.\n");
  say(TPN+" hungrily eats some chocolate cookies.\n");
      destruct(this_object());
      this_player()->recalc_carry();
 return 1;
}
