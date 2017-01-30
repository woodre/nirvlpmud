#include "defs.h"

inherit HEAL;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("biscuits");
  add_alias("biscuit");
  add_alias("tin");
  add_alias("tin of biscuits");
  set_short("A tin of biscuits");
  set_long("This is a cheap tin filled with fresh baked biscuits.\n");
  set_type("biscuits");
  set_msg("You take a biscuit out of the tin and eat it.\n");
  set_msg2(" eats a biscuit.\n");
  add_cmd("eat");
  add_cmd("chew");
  set_heal(35,35);
  set_charges(5);
  set_stuff(14);
  set_value(240);
}
