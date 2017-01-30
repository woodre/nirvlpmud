#include "defs.h"

inherit HEAL;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("potion");
  add_alias("heal");
  add_alias("fullheal");
  add_alias("healing potion");
  set_short("A healing potion");
  set_long("A clear glass bottle with a strangely glowing liquid inside.\n");
  set_type("heals");
  set_msg("You drink the potion and feel whole, renewed and revitalized.\n");
  add_cmd("drink");
  add_cmd("sip");
  add_cmd("swig");
  set_heal(500,500);
  set_charges(1);
  set_value(10000);
}
