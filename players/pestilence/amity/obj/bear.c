#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("teddy bear");
  set_alias("bear");
  set_short("teddy bear");
set_long(
"This is a fuzzy teddy bear.  It appears you could hug this bear.\n");
  set_value(500);
  set_weight(2);
}
init () {
   ::init() ;
     add_action ("hug_bear","hug");
     }

hug_bear(str) {
if(!id(str)) { notify_fail("Hug what?\n");
 return 0; }
     this_player()->heal_self(5+random(10));
     write("You squeeze the bear tightly in your arms.\n");
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
}
