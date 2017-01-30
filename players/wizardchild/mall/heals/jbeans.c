/* jbeans.c: jelly beans */
#include "defs.h"
#include "color.h"
inherit "/players/wizardchild/mall/heals/healdrv.c";
reset(arg) {
  if(arg)
    return 0;
  set_id(({"beans","jelly beans","bag of jelly beans"}));
  set_short("A small bag of jelly beans");
  set_long(
 "A little plastic bag, filled with the small sugar candies. It looks like\n"
+"there are "+RED+"red"+OFF+" ones, "+GREEN+"green"+OFF+" ones, and "
+YELLOW+"yellow"+OFF+" ones.\n"
+"You could probably eat them.\n");
  set_usage("eat");
  set_type(FOOD);
  set_intox(12);
  set_heal(5);
  set_uses(23);
  set_my_msg("You eat a few jelly beans.\n"
            +"Due to your lack of color coordination in your choice, however, your tongue\n"
            +"turns "+BROWN+"brown"+OFF+".\n");
  set_o_msg("eats a few jelly beans.\n");
  set_edest(1);
  set_ddest(1);
}          
