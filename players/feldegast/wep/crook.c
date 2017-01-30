#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("crook");
  set_alias("staff");
  set_short("Shepherd's Crook");
  set_long(
    "This is a shepherd's crook, a simple wooden staff with a hook on the end.\n"
  );
  set_weight(2);
  set_type("polearm");
  set_class(14);
  set_value(250);
}
