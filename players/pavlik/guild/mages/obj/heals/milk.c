inherit "/obj/generic_heal";

#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Glass of "+HIW+"Goat's Milk"+NORM);
  add_alias("milk");
  add_alias("glass of goat's milk");
  add_alias("goat milk");
  add_alias("goat's milk");
  add_alias("glass");
  set_short("A glass of "+HIW+"Goat's Milk"+NORM);
  set_long("A crystal glass of the old fashioned dairy original.\n");
  set_type("guzzles");
  set_type_single("guzzle");
  set_msg("You guzzle down a chug of "+HIW+"goat's milk"+NORM+".\n");
  set_msg2(" guzzles a chug of "+HIW+"goat's milk"+NORM+".\n");
  set_empty_msg("...gurgle...\nYou chugged the last drop down.\n");
  add_cmd("drink");
  add_cmd("chug");
  add_cmd("sip");
  add_cmd("guzzle");
  set_heal(25,75);
  set_charges(3);
  set_soak(20);
  set_value(250);
  /* see apple pie for heal guidelines */
}