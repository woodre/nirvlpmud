/* sdaddy.c: sugar daddy */
#include "defs.h"
inherit "/players/wizardchild/mall/heals/healdrv.c";
reset(arg) {
  if(arg)
    return 0;
  set_id(({"sugar","daddies","sugar daddies"}));
  set_short("A few sugar daddies");
  set_long(
 "A few loosely tied sugar daddies. Just by looking at them, you can tell\n"
+"they are LOADED with sugar.\n"
+"Excusing the other connotations, you could \"suck daddies\".\n");
  set_usage("suck");
  set_type(FOOD);
  set_intox(10);
  set_heal(19);
  set_uses(3);
  set_my_msg("You pop a sugar daddy into your mouth.\n"
            +"Halfway through it, you realize that your teeth are stuck to it.\n"
            +"Lucky you don't have dentures, eh?\n");
  set_o_msg("sucks on a sugar daddy, which promptly sticks to their teeth.\n");
  set_edest(1);
}
