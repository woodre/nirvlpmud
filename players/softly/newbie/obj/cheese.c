inherit "/obj/generic_heal.c";
#include "/players/softly/closed/ansi.h"

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("cheese");
  add_alias("Cheese");
  set_short(HIY+"Cheese"+NORM);
  set_long("A small bit of cheese.  You may taste it if you are\n"+
	   "desperate enough.\n");
  set_type("bite of cheese");
  set_msg("You munch slowly on the cheese.\n");
  set_msg2(" eats cheese.\n");
  add_cmd("eat");
  add_cmd("munch");
  add_cmd("bite");
  add_cmd("nibble");
  set_heal(20,0); 
  set_charges(2);
  set_stuff(8);
  set_value(104);
}
short(){ return HIY+"Cheese"+NORM+" ["+charges+"]"; }

