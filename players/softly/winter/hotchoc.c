inherit "/obj/generic_heal.c";
#include "/players/softly/misc/ansi.h"

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("hot chocolate");
  add_alias("chocolate");
  add_alias("choc");
  set_short("Hot Chocolate");
  set_long("A large styrofoam cup filled with steaming hot chocolate for you to drink.\n");
  set_type("sips");
  set_msg("You take a large swallow of thick sweet hot chocolate.\n");
  set_msg2(" sips some steaming hot chocolate.\n");
  add_cmd("drink");
  add_cmd("sip");
  set_heal(40,0); 
  set_charges(3);
  set_soak(12);
  set_value(208);
}
short(){ return "Hot Chocolate ["+charges+"]"; }
