/* Can be purchased for 1800 from Randal at the Qual'tor Market Square */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("brandy");
  add_alias("flask");
set_short("A flask of "+RED+"dark brandy"+NORM);
  set_long("A small flask of highly intoxicating brandy. You think you\n"+
           "can take a "+HIR+"sip"+NORM+" of the "+RED+"dark brandy"+NORM+".\n");

  set_msg("You take a sip of "+RED+"dark brandy"+NORM+" from the flask.\n");
  set_msg2(" takes a sip of a "+RED+"dark brandy"+NORM+".\n");
  add_cmd("sip");
  set_type("sip");

  set_heal(0,100);
  set_charges(3);
  set_intox(14);
  set_value(400);
}

query_save_flag(){
  return 1;
  }
