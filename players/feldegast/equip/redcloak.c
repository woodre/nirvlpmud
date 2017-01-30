#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg) {
  set_name("cloak");
  set_alias("red cloak");
  set_short("A "+RED+"Crimson"+NORM+" cloak");
  set_long(
    "This is a crimson colored cloak with a steel brooch on the shoulder.\n"
  );
  set_ac(1);
  set_type("misc");
  set_weight(1);
  set_value(100);
}
