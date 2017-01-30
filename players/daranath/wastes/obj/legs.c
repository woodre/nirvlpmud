/* Can be purchased for 1050 from Randal at the Qual'tor Market Square */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("croaker's legs");
  add_alias("legs");
  add_alias("leg");
  set_short(HIG+"Croaker's Legs"+NORM);
  set_long("A pair of "+GRN+"legs"+NORM+" from the croaker that you can "+BOLD+"eat"+NORM+".\n");

  set_msg("You take a bite from the "+GRN+"croaker legs"+NORM+".\n");
  set_msg2(" takes a bite from the "+GRN+"croaker legs"+NORM+".\n");
  add_cmd("eat");
  set_type("bite");

  set_heal(20,20);
  set_charges(2);
  set_stuff(7);
  set_value(75);
}

query_save_flag(){
  return 1;
  }
