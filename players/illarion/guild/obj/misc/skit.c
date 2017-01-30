/* skit.c */

/* sharpening kit for blademasters.  needed to sharpen the guild weapon, */
/* and limited number of uses */

inherit "obj/treasure";
#include "/players/illarion/guild/def.h"

int uses;

reset(arg) {
  if(arg) return;

  uses=15;

  set_id("pouch");
  set_alias("blademaster_sharpening_pouch");
  set_short("A small leather pouch");
  set_long("Inside this pouch are a number of items used to take care of\n"+
           "edged weapons, including oil, rags, and sharpening stones.\n"+
           "They all seem specialized somehow, as if intended for use on\n"+
           "a specific weapon or kind of weapon.\n");

  set_weight(1);
  set_value(0);
}
query_uses() { return uses; }

use_kit() {
  return --uses;
}

long() {
  ::long();
  if(present(OB_NAME,TP))
    write("You could use the pouch for sharpening "+uses+" more time"+
    (uses==1?"":"s")+".\n");
}
