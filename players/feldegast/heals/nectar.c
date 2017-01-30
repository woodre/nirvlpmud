#include "defs.h"

inherit HEAL;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("nectar");
  add_alias("jug");
  set_short("A jug of nectar");
  set_long("This is a clay jug with the label 'nectar' on it.\n");
  set_type("sips");
  set_msg("You take a sip of nectar.\n");
  set_msg2(" takes a sip of nectar.\n");
  add_cmd("swig");
  add_cmd("drink");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(3);
  set_soak(12);
  set_value(800);
}
