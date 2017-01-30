#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mace");
  set_short("A steel mace");
  set_long(
    "This is a long metal club with a weighted head and a row of spikes\n"+
    "strategically placed on the head.\n"
  );
  set_type("club");
  set_class(16);
  set_weight(3);
  set_value(400+random(100));
}
