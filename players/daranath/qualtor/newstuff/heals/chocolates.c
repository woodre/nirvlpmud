/* Can be purchased for 600 from Chandra in the femstore */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("chocolate");
  add_alias("box");
  add_alias("candy");
  set_short("A box of "+RED+"chocolates"+NORM);
  set_long("A "+RED+"heart shaped"+NORM+" box of "+RED+"chocolates"+NORM+" that you\n"+
           "can "+WHT+"eat"+NORM+". A romantic gift anytime of the year.\n");

  set_msg("You eat on of your favorite "+RED+"chocolates"+NORM+".\n");
  set_msg2(" eats one of thier chocolate candies.\n");
  add_cmd("eat");
  set_type("chocolate");

  set_heal(20,20);
  set_charges(3);
  set_stuff(7);
  set_value(75);
}

query_save_flag(){
  return 1;
  }
