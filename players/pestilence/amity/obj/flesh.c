#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("flesh");
  set_alias("hunk");
  set_short("hunk of "+RED+"flesh"+NORM+"");
set_long(
"A hunk of "+RED+"flesh"+NORM+".  It is red and bloody.  It was taken from\n"+
"a person while fighting an ant.\n");
  set_value(random(7));
  set_weight(1);
}
init () {
   ::init() ;
     add_action ("eat_flesh","eat");
     }

eat_flesh(str) {
if(!id(str)) { notify_fail("Eat what?\n");
 return 0; }
      write("You eat down the flesh greedily.\n"+
            "A sickening feeling starts to come over your body.\n");
      move_object(clone_object("/players/pestilence/amity/obj/poison"), this_player());
      this_player()->recalc_carry();
      destruct(this_object());
      return 1;
}
