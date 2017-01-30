#include "defs.h"

inherit "/obj/armor.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("cloak");
  set_alias("black cloak");
  set_short("A "+BOLD+BLK+"black"+NORM+" cloak");
  set_long(
    "This is a short black cloak, practically a cape, with a silvery\n"+
    "skull on the clasp.\n"
  );
  set_ac(1);
  set_type("misc");
  set_weight(1);
  set_value(500);
}
