/* rcandy.c: rock candy */
#include "defs.h"
inherit "/players/wizardchild/mall/heals/healdrv.c";
reset(arg) {
  if(arg) 
    return 0;
  set_id(({"candy","rock candy","bag","bag of rock candy"}));
  set_short("A bag of Rock Candy");
  set_long(
 "A little red plastic bag of Rock Candy. By looking at it, you can tell\n"
+"that there's at least one serving left..\n"
+"You could probably eat it.\n");
  set_value(50);
  set_usage("eat");
  set_type(FOOD);
  set_intox(10);
  set_heal(5);  
  set_uses(3);
  set_my_msg("You crunch away on the rock candy. Yummie!\n");
  set_o_msg("crunches on some rock candy.\n");
  set_edest(1);
}
