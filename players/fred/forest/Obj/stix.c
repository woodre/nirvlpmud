

#include "/players/fred/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("pixi stix");
  add_alias("stix");
  set_short(HIG+"A"+HIC+" Pixi"+RED+" Stix"+NORM);
  set_long("A straw of sugar.  The words 'Pixi Stix' are written on the tube.\n");
  set_type("bite");
  set_msg("You tear the top of the straw off and pour some sugar into your mouth.\n");
  set_msg2(" eats some sugar from the Pixi Stix.\n");
  add_cmd("eat");
  set_heal(50,50); 
  set_charges(3);
  set_stuff(14);
  set_value(600);
}
