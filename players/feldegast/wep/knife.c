#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("knife");
  set_short("A knife");
  set_long(
    "A wicked looking knife with a steel blade and a wooden handle.\n"
  );
  set_type("knife");
  set_class(13);
  set_weight(1);
  set_value(150);
}
