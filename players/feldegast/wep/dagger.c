#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("dagger");
  set_short("A dagger");
  set_long(
    "A sharp steel dagger with a brass hilt and a wooden handle.\n"
  );
  set_type("knife");
  set_class(14);
  set_weight(1);
  set_value(200);
}
