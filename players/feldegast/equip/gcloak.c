#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg) {
  set_name("cloak");
  set_alias("gold cloak");
  set_short("A "+HIY+"gold"+NORM+" cloak");
  set_long(
    "This is a bright yellow cloak with a golden clasp.\n"
  );
  set_ac(1);
  set_type("misc");
  set_weight(1);
  set_value(100);
}
