/* Can be purchased for 1200 from either Randal at the Market sqaure or in
    the East Road shop */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("wine");
  add_alias("bottle");
  set_short("A "+WHT+"bottle"+NORM+" of dark "+RED+"red wine"+NORM);
  set_long("A bottle of highly intoxicating red wine. You think you can\n"+
           "take a "+WHT+"sip"+NORM+" the "+RED+"red wine"+NORM+".\n");

  set_msg("You take a sip of "+RED+"dark red"+NORM+" wine.\n");
  set_msg2(" takes a sip of exotic "+RED+"red wine"+NORM+".\n");
  add_cmd("sip");
  set_type("sip");

  set_heal(25,25);
  set_charges(6);
  set_intox(14);
  set_value(100);
}

query_save_flag(){
  return 1;
  }
