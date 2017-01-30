inherit "/obj/generic_heal";

#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Loaf of Bread");
  add_alias("loaf");
  add_alias("loaf of bread");
  add_alias("bread");
  set_short("A Loaf of Bread");
  set_long("A loaf of fine French bread, Biago's specialty.\n");
  set_type("hunks");
  set_type_single("hunk");
  set_msg("You rip off a hunk of bread and shove it in your mouth.\n");
  set_msg2(" rips off a hunk of bread and swallows it down.\n");
  set_empty_msg("You gobbled down the whole loaf.\n");
  add_cmd("bite");
  add_cmd("eat");
  set_heal(25,75);
  set_charges(3);
  set_stuff(20);
  set_value(250);
  /* see apple pie for heal guidelines */
}