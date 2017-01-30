#include "defs.h"

inherit HEAL;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("cookie");
  set_short("A chocolate-chip cookie");
  set_long(
    "This is a delicious looking chocolate chip cookie just out of the oven.\n"+
    "Your mouth waters just looking at it.\n"
  );
  set_type("cookie");
  set_msg("The delicious cookie melts in your mouth. MMmmmMMMmm!\n");
  set_msg2(" eats a cookie.\n");
  add_cmd("eat");
  add_cmd("chew");
  add_cmd("bite");
  set_heal(5,5);
  set_charges(1);
  set_stuff(4);
  set_value(1);
}

short() {
  return "A chocolate-chip cookie";
}
