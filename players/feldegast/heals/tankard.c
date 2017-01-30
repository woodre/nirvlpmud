#include "defs.h"

inherit HEAL;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("ale");
  add_alias("tankard");
  set_short("A tankard of ale");
  set_long("This is a cheap pewter tankard with some ale left in it.\n");
  set_type("sips");
  set_msg("You swig some ale from the tankard.\n");
  set_msg2(" swigs some ale from a tankard.\n");
  add_cmd("drink");
  add_cmd("sip");
  add_cmd("swig");
  set_heal(30,30);
  set_charges(1);
  set_intox(7);
  set_value(200);
}
