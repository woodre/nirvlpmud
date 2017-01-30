/* Can be purchased for 800 from Randal at the Qual'tor Market Square */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

set_name("turkey");
add_alias("leg");
set_short(YEL+"Turkey Leg"+NORM);
set_long("An extremly juicy leg of turket, it is a favorite amongst the newer\n"+
         "warriors and explorers of Nirvana.\n"+
         "You can "+HIR+"eat"+NORM+" the turkey for some healing.\n");

set_msg("You tear off a good size hunk of the "+YEL+"Turkey Leg"+NORM+".\n");
set_msg2(" tears off a chunk of the "+YEL+"Turkey Leg"+NORM+".\n");
add_cmd("eat");
set_type("bite");

set_heal(25,25);
set_charges(4);
set_soak(5);
set_stuff(5);
set_value(125);
}

query_save_flag() {return 1; }
