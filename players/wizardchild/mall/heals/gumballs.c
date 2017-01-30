/* gumballs.c: gumballs (doh) */
#include "defs.h"
inherit "/players/wizardchild/mall/heals/healdrv.c";
reset(arg) {
  if(arg)
    return 0;
  set_id(({"gumballs","gum","balls","gum balls", "bag of gumballs"}));
  set_short("A bag of gumballs");
  set_long(
 "A small bag with maybe 10-20 colored gumballs in it. If you chomped them\n"
+"in huge amounts, you could probably finish it in 3 servings.\n"
+"You could probably chew them.\n");
  set_value(150);
  set_usage("chew");
  set_type(FOOD);
  set_intox(8);
  set_heal(8);
  set_uses(3);
  set_my_msg("You grab a handfull of gumballs and start chewing away.\n"
            +"Unfortunately, you grabbed a non-matching bunch, so the flavor is rather\n"
            +"unpleasant.\n");
  set_o_msg("chews on a handfull of gumballs.\n");
  set_edest(1);
}
