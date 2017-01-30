#include "defs.h"

inherit HEAL;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("chocolates");
  set_short("A box of chocolates");
  set_long("This is a heart-shaped box of assorted chocolates.\n");
  set_type("chocolates");
  set_msg("You eat a chocolate.\n");
  set_msg2(" eats a chocolate.\n");
  add_cmd("eat");
  set_heal(5,5);
  set_charges(5);
  set_stuff(4);
  set_value(1);
}
short() {
  return short_desc;
}
