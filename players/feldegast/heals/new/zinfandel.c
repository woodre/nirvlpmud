#include "defs.h"

inherit HEAL;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("zinfandel");
  add_alias("wine");
  add_alias("white zinfandel");
  add_alias("zin");
  add_alias("bottle");
  set_short("A bottle of White Zinfandel");
  set_long("This is a bottle of cheap wine, its glass tinted a dark green and\n"+
           "with a label naming the vineyard and a very bad year.\n");
  set_type("sips");
  set_msg("You take a swig of the white zinfandel and then replace the cork.\n");
  set_msg2(" drinks some wine.\n");
  add_cmd("drink");
  add_cmd("swig");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(3);
  set_intox(10);
  set_value(500);
}
