#include <ansi.h>

inherit "/obj/generic_heal";

void reset(int arg)
{
  if(arg) return;
  ::reset(arg);
  set_name("lavadrink");
  add_alias("drink");
  set_short(HIR+"Lavadrink"+NORM);
  set_type("drink");
  set_long("A stone cup filled with smoking Lavadrink.\n");
  set_msg("You sip a bit of the steaming "+HIR+"Lavadrink"+NORM+"\n\
The near-boiling liquid scorches your throat, but once it hits\n\
your stomach you feel much better.\n");
  set_msg2(" sips a boiling "+HIR+"Lavadrink"+NORM+".\n");
  add_cmd("swig");
  add_cmd("sip");
  set_heal(40,40);
  set_charges(3);
  set_soak(13);
  set_value(300);
}
