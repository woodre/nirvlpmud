#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  if(arg) return;
  ::reset();
  set_name("club");
  set_type("club");
  set_short("A wooden club");
  set_long(
"This is a stout piece of wood about a yard long.  At the\n"+
"grip it is about the diameter of a hand, and at the receiving\n"+
"end it gets about as thick as a head.  The club is covered\n"+
"in little gnaw marks.\n"
  );
  set_weight(3);
  set_class(15);
  set_value(300);
}
