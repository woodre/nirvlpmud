/* Can be purchased for 800 from Randal at the Qual'tor Market Square */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("slime");
  add_alias("patch");
  set_short("A patch of "+HIG+"luminescent slime"+NORM);
  set_long("A small patch of "+HIG+"slime"+NORM+" that seems to glow in the dark.\n"+
           "You believe you could "+RED+"consume"+NORM+" the "+HIG+"slime"+NORM+".\n");

  set_msg("You suck down some of the "+HIG+"luminescent slime"+NORM+".\n");
  set_msg2(" sucks down some "+HIG+"luminescent slime"+NORM+".\n");
  add_cmd("consume");
  set_type("portion");

  set_heal(0,50);
  set_charges(5);
  set_soak(10);
  set_value(100);
}

query_save_flag(){
  return 1;
  }
