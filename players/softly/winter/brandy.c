inherit "/obj/generic_heal.c";
#include "/players/softly/misc/ansi.h"
void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("brandy");
  add_alias("brandy");
  set_short("Brandy");
  set_long("A cup of warm brandy.  It warms your hands.  You may 'sip' it.\n");
  set_type("sips");
  set_msg("You take a sip of warm brandy.\n");
  set_msg2(" sips some warm brandy.\n");
  add_cmd("sip");
  add_cmd("drink");
  set_heal(30,30);
  set_charges(3);
  set_intox(6);
  set_soak(12);
  set_value(240);

}
short(){ return "Brandy ["+charges+"]"; }
