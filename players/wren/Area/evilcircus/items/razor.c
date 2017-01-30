	/* weapon template */
inherit "obj/weapon";
#include "/players/wren/ansi.h"

reset(arg)  {
    ::reset();
    if(arg) return;

set_name("razor");
set_alias("knife");
set_short("a long folding razor");
set_long("A gleeming single edged straight razor. It can fold\n"+
         "neatly back into its handle but you see that it locks\n"+
         "open for use in combat instead of grooming.    \n");

set_type("knife");   /*sword,knife,club,axe,bow,polearm */
set_class(18);
set_weight(1);
set_value(1000);
set_hit_func(this_object());

}

weapon_hit(attacker) {
int W;
W = random(13);
if(W>9)  {
    say("The razor flashes across a vein spraying"+HIR+" blood"+NORM+" everywhere. \n");
    write("Your razor flashes across your opponents vein spraying"+HIR+" blood"+NORM+" everywhere. \n");
    return 5;
          }
return;
}
