/* Can be purchased for 800 from Randal at the Qual'tor Market Square */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("knucklebones");
  add_alias("knucklebone");
  add_alias("knuckle");
  add_alias("sack");
  set_short("A sack of "+WHT+"knucklebones"+NORM);
  set_long("A sack of "+WHT+"knucklebones"+NORM+" that you can "+RED+"pop"+NORM+".\n");

  set_msg("You "+RED+"pop"+NORM+" a "+WHT+"knucklebone."+NORM+" That was different.\n");
  set_msg2(" pops a "+WHT+"knucklebone"+NORM+" into thier mouth.\n");
  add_cmd("pop");
  set_type("knuckles");

  set_heal(35,15);
  set_charges(7);
  set_stuff(6);
  set_value(100);
}

query_save_flag(){
  return 1;
  }
