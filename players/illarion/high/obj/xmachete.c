/* weapon for high/mon/xavier.c */
inherit "obj/weapon";
#include "/players/illarion/dfns.h"

#define CHANCE 

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("machete");
  set_type("sword");
  set_short("A nasty-looking machete");
  set_long(
"The hilt of this weapon is ludicrously fancy: gold-plated, mother of pearl \n"+
"inlaid, but still servicable.  The blade, in contrast, is simply an ugly slice\n"+
"of nearly black metal.  A faint stink rises from the blade.\n");
  set_class(18);
  set_weight(4);
  set_value(5000);
  set_params("other|poison",0,"poison_hit");
}

/* NOTE:  10% change of 10 damage = +1 wc */
int poison_hit(object victim) {
  if(!wielded_by || !victim) return 0;
  
  if(!random(10)) {
    if(wielded_by->query_alignment() > -100) {
      write("The machete quivers in your hands, but nothing else happens.\n");
      return 0;
    }
    
    write("Poison oozes from the machete's blade!\n");
    say("Poison oozes from "+(string)this_player()->query_name()+"'s blade!");
  }
  return 10;
}
