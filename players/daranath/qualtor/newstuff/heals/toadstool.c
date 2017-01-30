/* Can be purchased for 800 from Randal at the Qual'tor Market Square */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("toadstool");
  add_alias("toad");
  set_short("A "+HIG+"toadstool"+NORM);
  set_long("A toadstool that you can "+WHT+"eat"+NORM+"\n");

  set_msg("You pop the "+HIG+"toadstool"+NORM+" into your mouth.\n");
  set_msg2(" eats a "+HIG+"toadstool"+NORM+".\n");
  add_cmd("eat");
  set_type("bite");

  set_heal(30,30);
  set_charges(1);
  set_stuff(6);
  set_value(50);
}

query_save_flag(){
  return 1;
  }
