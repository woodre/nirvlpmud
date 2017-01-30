inherit "/obj/generic_heal";

#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("bag of cookies");
  add_alias("bag");
  add_alias("cookies");
  set_short("A bag of cookies");
  set_long("A bag of Helen's wonderful chocolate chip cookies.\n");
  set_type("cookies");
  set_type_single("cookie");
  set_msg("You gobble down a soft chocolate chip cookie.\n");
  set_msg2(" eats a cookie.\n");
  set_empty_msg("The cookies are all gone.\n");
  add_cmd("bite");
  add_cmd("eat");
  set_heal(6,18);
  set_charges(12);
  set_stuff(5);
  set_value(60);
  /* see apple pie for heal guidelines */
}