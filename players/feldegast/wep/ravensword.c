#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("short sword");
  set_alias("shortsword");
  set_short("A shortsword");
  set_type("sword");
  set_class(15);
  set_weight(2);
  set_long(
    "This is a steel shortsword with a silver ravenshead on the pommel.\n"
  );
  set_value(600);
}
