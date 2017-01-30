inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_id("hair");
  set_alias("wolf hair");
  set_short("Wolf hair");
  set_long(
"This is a nasty little glob of black wolf hair.  It has a pungent odor\n"+
"about it, and is somewhat grimy.  If you found someone who wanted this,\n"+
"you could 'barter' with them and get it's true value.\n");
  set_weight(1);
  set_value(100+random(3000)); /* 2700 +r1500 */
}
