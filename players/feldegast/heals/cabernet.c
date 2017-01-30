#include "defs.h"

inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("savignon");
  add_alias("cabernet");
  add_alias("cabernet savignon");
  add_alias("wine");
  add_alias("bottle");
  set_short("A bottle of "+RED+"Cabernet Savignon"+NORM);
  set_long(
    "This is an expensive bottle of a perfectly aged cabernet savignon.\n");
  set_type("sips");
  set_msg("You carefully sip the cabernet savignon.\n");
  set_msg2(" enjoys a glass of cabernet savignon.\n");
  add_cmd("drink");
  add_cmd("swig");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(3);
  set_intox(4);
  set_value(1500);
}
